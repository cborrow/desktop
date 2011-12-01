// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#ifndef SWITCHERVIEW_H
#define SWITCHERVIEW_H

#include "SwitcherModel.h"
#include "AbstractIconRenderer.h"
#include "StaticCairoText.h"
#include "LayoutSystem.h"
#include "BackgroundEffectHelper.h"

#include "Introspectable.h"

#include <boost/shared_ptr.hpp>
#include <sigc++/sigc++.h>

#include <Nux/View.h>
#include <NuxCore/ObjectPtr.h>
#include <NuxCore/Property.h>


namespace unity
{
namespace launcher
{
class AbstractLauncherIcon;
}
namespace switcher
{

class SwitcherView : public Introspectable, public nux::View
{
  NUX_DECLARE_OBJECT_TYPE(SwitcherView, nux::View);
public:
  typedef nux::ObjectPtr<SwitcherView> Ptr;

  SwitcherView(NUX_FILE_LINE_PROTO);
  virtual ~SwitcherView();

  ui::LayoutWindowList ExternalTargets ();

  void SetModel(SwitcherModel::Ptr model);
  SwitcherModel::Ptr GetModel();

  void SetupBackground ();

  nux::Property<bool> render_boxes;
  nux::Property<int> border_size;
  nux::Property<int> flat_spacing;
  nux::Property<int> icon_size;
  nux::Property<int> minimum_spacing;
  nux::Property<int> tile_size;
  nux::Property<int> vertical_size;
  nux::Property<int> text_size;
  nux::Property<int> animation_length;
  nux::Property<double> spread_size;
  nux::Property<nux::Color> background_color;

protected:
  // Introspectable methods
  const gchar* GetName();
  void AddProperties(GVariantBuilder* builder);

  void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);

  ui::RenderArg InterpolateRenderArgs(ui::RenderArg const& start, ui::RenderArg const& end, float progress);
  nux::Geometry InterpolateBackground (nux::Geometry const& start, nux::Geometry const& end, float progress);

  std::list<ui::RenderArg> RenderArgsFlat(nux::Geometry& background_geo, int selection, timespec const& current);

  ui::RenderArg CreateBaseArgForIcon(launcher::AbstractLauncherIcon* icon);
private:
  void DrawBackground(nux::GraphicsEngine& GfxContext, nux::Geometry const& geo);

  void OnSelectionChanged(launcher::AbstractLauncherIcon* selection);
  void OnDetailSelectionChanged (bool detail);
  void OnDetailSelectionIndexChanged (unsigned int index);

  void OnIconSizeChanged (int size);
  void OnTileSizeChanged (int size);

  nux::Geometry UpdateRenderTargets (nux::Point const& center, timespec const& current);
  void OffsetRenderTargets (int x, int y);

  nux::Size SpreadSize ();

  void GetFlatIconPositions (int n_flat_icons, 
                             int size, 
                             int selection, 
                             int &first_flat, 
                             int &last_flat, 
                             int &half_fold_left, 
                             int &half_fold_right);

  static gboolean OnDrawTimeout(gpointer data);

  void SaveLast ();

  ui::LayoutSystem::Ptr layout_system_;
  ui::AbstractIconRenderer::Ptr icon_renderer_;
  SwitcherModel::Ptr model_;
  bool target_sizes_set_;

  guint redraw_handle_;

  nux::BaseTexture* background_top_;
  nux::BaseTexture* background_left_;
  nux::BaseTexture* background_corner_;
  nux::BaseTexture* rounding_texture_;

  nux::StaticCairoText* text_view_;

  std::list<ui::RenderArg> last_args_;
  std::list<ui::RenderArg> saved_args_;

  nux::Geometry last_background_;
  nux::Geometry saved_background_;

  ui::LayoutWindowList render_targets_;

  timespec save_time_;

  bool animation_draw_;

  BackgroundEffectHelper bg_effect_helper_;
};

}
}

#endif // SWITCHERVIEW_H

