// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Jay Taoko <jay.taoko@canonical.com>
 */

#include "BackgroundEffectHelper.h"
#include "TimeUtil.h"

#include <time.h>
#include <X11/Xregion.h>
#include <boost/utility.hpp>


using namespace unity;

std::list<BackgroundEffectHelper*> BackgroundEffectHelper::registered_list_;

nux::Geometry BackgroundEffectHelper::monitor_rect_;

nux::Property<BlurType> BackgroundEffectHelper::blur_type (BLUR_ACTIVE);
nux::Property<float> BackgroundEffectHelper::sigma_high (5.0f);
nux::Property<float> BackgroundEffectHelper::sigma_med (3.0f);
nux::Property<float> BackgroundEffectHelper::sigma_low (1.0f);
nux::Property<bool> BackgroundEffectHelper::updates_enabled (true);
nux::Property<bool> BackgroundEffectHelper::detecting_occlusions (false);

BackgroundEffectHelper::BackgroundEffectHelper()
{
  enabled = false;
  cache_dirty = true;
  enabled.changed.connect (sigc::mem_fun(this, &BackgroundEffectHelper::OnEnabledChanged));
  noise_texture_ = nux::CreateTextureFromFile(PKGDATADIR"/dash_noise.png");

  Register(this);
}

BackgroundEffectHelper::~BackgroundEffectHelper()
{
  noise_texture_->UnReference();
  Unregister(this);
}

void BackgroundEffectHelper::OnEnabledChanged(bool value)
{
  if (value)
    DirtyCache();
}

void BackgroundEffectHelper::ProcessDamage(nux::Geometry geo)
{
  for (BackgroundEffectHelper * bg_effect_helper : registered_list_)
  {
    if (bg_effect_helper->cache_dirty || !bg_effect_helper->owner)
      continue;

    if (!geo.Intersect (bg_effect_helper->blur_geometry_).IsNull())
    {
      bg_effect_helper->DirtyCache();
    }
  }
}

bool BackgroundEffectHelper::HasEnabledHelpers()
{
  for (BackgroundEffectHelper * bg_effect_helper : registered_list_)
    if (bg_effect_helper->enabled)
      return true;

  return false;
}

void BackgroundEffectHelper::Register(BackgroundEffectHelper* self)
{
  registered_list_.push_back(self);
}

void BackgroundEffectHelper::Unregister(BackgroundEffectHelper* self)
{
  registered_list_.remove(self);
}

void BackgroundEffectHelper::DirtyCache ()
{
  if (cache_dirty)
    return;

  cache_dirty = true;
  if (owner)
    owner()->QueueDraw();
}

nux::ObjectPtr<nux::IOpenGLBaseTexture> BackgroundEffectHelper::GetBlurRegion(nux::Geometry geo, bool force_update)
{
  bool should_update = force_update || cache_dirty;

  /* Static blur: only update when the size changed */
  if ((blur_type != BLUR_ACTIVE || !should_update)
      && blur_texture_.IsValid()
      && (geo == blur_geometry_))
  {
    return blur_texture_;
  }

  nux::GraphicsEngine* graphics_engine = nux::GetGraphicsDisplay()->GetGraphicsEngine();
  
  int monitor_width = BackgroundEffectHelper::monitor_rect_.width;
  int monitor_height = BackgroundEffectHelper::monitor_rect_.height;

  nux::Geometry temp = geo;
  temp.OffsetPosition(-monitor_rect_.x, -monitor_rect_.y);
  blur_geometry_ =  nux::Geometry(0, 0, monitor_width, monitor_height).Intersect(temp);

  nux::GpuDevice* gpu_device = nux::GetGraphicsDisplay()->GetGpuDevice();
  if (blur_geometry_.IsNull() || blur_type == BLUR_NONE || !gpu_device->backup_texture0_.IsValid())
  {
    return nux::ObjectPtr<nux::IOpenGLBaseTexture>();
  }

  int opengl_version = gpu_device->GetOpenGLMajorVersion();
  int sigma = opengl_version >= 3 ? sigma_high : sigma_med;
  int radius = 3 * sigma;

  // Define a larger region of that account for the blur radius
  nux::Geometry larger_blur_geometry;
  larger_blur_geometry.x = std::max(blur_geometry_.x - radius, 0);
  larger_blur_geometry.y = std::max(blur_geometry_.y - radius, 0);
  
  int xx = std::min(blur_geometry_.x + blur_geometry_.width + radius, monitor_width);

  larger_blur_geometry.width = xx - larger_blur_geometry.x;

  int yy = std::min(blur_geometry_.y + blur_geometry_.height + radius, monitor_height);

  larger_blur_geometry.height = yy - larger_blur_geometry.y;

  int dleft     = blur_geometry_.x - larger_blur_geometry.x;
  int dbottom   = (larger_blur_geometry.y + larger_blur_geometry.height) - (blur_geometry_.y + blur_geometry_.height);

  // save the current fbo
  nux::ObjectPtr<nux::IOpenGLFrameBufferObject> current_fbo = gpu_device->GetCurrentFrameBufferObject();
  gpu_device->DeactivateFrameBuffer();

  // Set a viewport to the requested size
  // FIXME: We need to do multiple passes for the dirty region
  // on the underlying backup texture so that we're only updating
  // the bits that we need
  graphics_engine->SetViewport(0, 0, larger_blur_geometry.width, larger_blur_geometry.height);
  graphics_engine->SetScissor(0, 0, larger_blur_geometry.width, larger_blur_geometry.height);
  // Disable nux scissoring
  graphics_engine->GetRenderStates ().EnableScissor (false);

  // The background texture is the same size as the monitor where we are rendering.
  nux::TexCoordXForm texxform__bg;
  texxform__bg.flip_v_coord = false;
  texxform__bg.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
  texxform__bg.uoffset = ((float) larger_blur_geometry.x) / monitor_width;
  texxform__bg.voffset = ((float) monitor_height - larger_blur_geometry.y - larger_blur_geometry.height) / monitor_height;

  bool support_frag = gpu_device->GetGpuInfo().Support_ARB_Fragment_Shader();
  bool support_vert = gpu_device->GetGpuInfo().Support_ARB_Vertex_Shader();

  if (support_vert && support_frag && opengl_version >= 2)
  {
    float noise_factor = 1.1f;
    float gaussian_sigma = opengl_version >= 3 ? sigma_high : sigma_med;
    int blur_passes = 1;

    nux::ObjectPtr<nux::IOpenGLBaseTexture> device_texture = gpu_device->backup_texture0_;
    nux::ObjectPtr<nux::CachedBaseTexture> noise_device_texture = graphics_engine->CacheResource(noise_texture_);

    int down_size_factor = 1;
    unsigned int buffer_width = larger_blur_geometry.width;
    unsigned int buffer_height = larger_blur_geometry.height;

    int x =  0;
    int y =  0;

    unsigned int down_size_width = buffer_width / down_size_factor;
    unsigned int down_size_height = buffer_height / down_size_factor;

    nux::TexCoordXForm texxform;
    nux::TexCoordXForm noise_texxform;

    texxform.SetFilter(nux::TEXFILTER_NEAREST, nux::TEXFILTER_NEAREST);

    noise_texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
    noise_texxform.SetWrap(nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
    noise_texxform.SetFilter(nux::TEXFILTER_NEAREST, nux::TEXFILTER_NEAREST);

    // Down size
    graphics_engine->QRP_GetCopyTexture(down_size_width, down_size_height,
                                        resize_tmp_, device_texture,
                                        texxform__bg, nux::color::White);

    blur_fx_struct_.src_texture = resize_tmp_;
    // Blur at a lower resolution (less pixels to process)
    // nux::ObjectPtr<nux::IOpenGLBaseTexture> low_res_blur;
    // low_res_blur = graphics_engine->QRP_GetHQBlur(x, y, down_size_width, down_size_height,
    //                                               resized_texture, texxform, nux::color::White,
    //                                               gaussian_sigma, blur_passes);

    graphics_engine->QRP_GLSL_GetHQBlurFx(x, y, down_size_width, down_size_height,
                                                  &blur_fx_struct_, texxform, nux::color::White,
                                                 gaussian_sigma, blur_passes);


    // Up size
    graphics_engine->QRP_GetCopyTexture(buffer_width, buffer_height,
                                        resize_tmp_, blur_fx_struct_.dst_texture,
                                        texxform, nux::color::White);
    noise_fx_struct_.src_texture = resize_tmp_;

    // Add Noise
    nux::Color noise_color(noise_factor * 1.0f/buffer_width,
                           noise_factor * 1.0f/buffer_height,
                           1.0f, 1.0f);
    // noisy_tmp_ = graphics_engine->QRP_GLSL_GetDisturbedTexture(
    //   0, 0, buffer_width, buffer_height,
    //   noise_device_texture->m_Texture, noise_texxform, noise_color,
    //   resized_texture, texxform, nux::color::White);

    graphics_engine->QRP_GLSL_GetDisturbedTextureFx(
      0, 0, buffer_width, buffer_height,
      noise_device_texture->m_Texture, noise_texxform, noise_color,
      &noise_fx_struct_, texxform, nux::color::White);

    // Returns a smaller blur region (minus blur radius).
    texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
    texxform.flip_v_coord = true;
    texxform.uoffset = dleft / (float) buffer_width;
    texxform.voffset = dbottom / (float) buffer_height;
    graphics_engine->QRP_GetCopyTexture(blur_geometry_.width, blur_geometry_.height,
                                        blur_texture_, noise_fx_struct_.dst_texture,
                                        texxform, nux::color::White);
  }
  else
  {
    // GPUs with only ARB support are treated here

    float gaussian_sigma = sigma_low;
    int blur_passes = 1;

    nux::ObjectPtr<nux::IOpenGLBaseTexture> device_texture = gpu_device->backup_texture0_;
    nux::ObjectPtr<nux::CachedBaseTexture> noise_device_texture = graphics_engine->CacheResource(noise_texture_);

    unsigned int offset = 0;
    int quad_width = larger_blur_geometry.width;
    int quad_height = larger_blur_geometry.height;

    int down_size_factor = 4;
    unsigned int buffer_width = quad_width + 2 * offset;
    unsigned int buffer_height = quad_height + 2 * offset;

    int x = (buffer_width - quad_width) / 2;
    int y = (buffer_height - quad_height) / 2;

    unsigned int down_size_width = buffer_width / down_size_factor;
    unsigned int down_size_height = buffer_height / down_size_factor;

    nux::TexCoordXForm texxform;
    nux::TexCoordXForm noise_texxform;

    texxform.SetFilter(nux::TEXFILTER_NEAREST, nux::TEXFILTER_NEAREST);

    noise_texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
    noise_texxform.SetWrap(nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
    noise_texxform.SetFilter(nux::TEXFILTER_NEAREST, nux::TEXFILTER_NEAREST);

    // Copy source texture
    nux::ObjectPtr<nux::IOpenGLBaseTexture> texture_copy;
    graphics_engine->QRP_GetCopyTexture(buffer_width, buffer_height,
                                        texture_copy, device_texture,
                                        texxform__bg, nux::color::White);

    // Down size
    nux::ObjectPtr<nux::IOpenGLBaseTexture> resized_texture;
    graphics_engine->QRP_GetCopyTexture(down_size_width, down_size_height,
                                        resized_texture, texture_copy,
                                        texxform, nux::color::White);

    // Blur at a lower resolution (less pixels to process)
    nux::ObjectPtr<nux::IOpenGLBaseTexture> low_res_blur;
    low_res_blur = graphics_engine->QRP_GetBlurTexture(x, y, down_size_width, down_size_height,
                                                       resized_texture, texxform,
                                                       nux::color::White,
                                                       gaussian_sigma, blur_passes);

    // Up size
    texxform.SetFilter(nux::TEXFILTER_LINEAR, nux::TEXFILTER_LINEAR);
    graphics_engine->QRP_GetCopyTexture(buffer_width, buffer_height, resized_texture,
                                        low_res_blur, texxform, nux::color::White);

    // Returns a smaller blur region (minus blur radius).
    texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
    texxform.flip_v_coord = true;
    texxform.uoffset = dleft / (float) buffer_width;
    texxform.voffset = dbottom / (float) buffer_height;
    graphics_engine->QRP_GetCopyTexture(blur_geometry_.width, blur_geometry_.height,
                                        blur_texture_, resized_texture,
                                        texxform, nux::color::White);
  }

  if (current_fbo.IsValid())
  {
    current_fbo->Activate(true);
    graphics_engine->Push2DWindow(current_fbo->GetWidth(), current_fbo->GetHeight());
    graphics_engine->GetRenderStates ().EnableScissor (true);
  }
  else
  {
    graphics_engine->SetViewport(0, 0, monitor_width, monitor_height);
    graphics_engine->Push2DWindow(monitor_width, monitor_height);

    graphics_engine->ApplyClippingRectangle();
  }

  cache_dirty = false;
  return blur_texture_;
}
