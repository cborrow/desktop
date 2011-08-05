/*
 * Copyright 2011 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */

#include "config.h"
#include "Nux/Nux.h"

#include "FilterRatingsButton.h"

namespace unity {

  FilterRatingsButton::FilterRatingsButton (NUX_FILE_LINE_DECL)
      : nux::Button (NUX_FILE_LINE_PARAM)
  {
    InitTheme();

    OnMouseDown.connect (sigc::mem_fun (this, &FilterRatingsButton::RecvMouseDown) );
  }

  FilterRatingsButton::~FilterRatingsButton() {
    delete _full_normal;
    delete _full_prelight;
    delete _half_normal;
    delete _half_prelight;
    delete _empty_normal;
    delete _empty_prelight;
  }

  void FilterRatingsButton::SetFilter(dash::Filter::Ptr filter)
  {
    filter_ = std::static_pointer_cast<dash::RatingsFilter>(filter);
    filter_->rating.changed.connect (sigc::mem_fun (this, &FilterRatingsButton::OnRatingsChanged));
    NeedRedraw();
  }

  std::string FilterRatingsButton::GetFilterType ()
  {
    return "FilterRatingsButton";
  }

  void FilterRatingsButton::InitTheme()
  {
    //FIXME - build theme here - store images, cache them, fun fun fun
    // ratings bar requires us to store/create three states for stares, half open, selected/unselected

    //these should be cached and shared between widgets if at all possible
    _full_prelight = new nux::ColorLayer (nux::Color (1.0, 1.0, 1.0, 1.0));
    _full_normal = new nux::ColorLayer (nux::Color (0.8, 0.8, 0.8, 1.0));

    _empty_prelight = new nux::ColorLayer (nux::Color (0.7, 0.0, 0.0, 1.0));
    _empty_normal = new nux::ColorLayer (nux::Color (0.5, 0.0, 0.0, 1.0));

    _half_prelight = new nux::ColorLayer (nux::Color (0.0, 0.0, 0.7, 1.0));
    _half_normal = new nux::ColorLayer (nux::Color (0.0, 0.0, 0.5, 1.0));
  }


  long int FilterRatingsButton::ProcessEvent(nux::IEvent& ievent, long int TraverseInfo, long int ProcessEventInfo) {
    return nux::Button::ProcessEvent(ievent, TraverseInfo, ProcessEventInfo);
  }

  void FilterRatingsButton::Draw(nux::GraphicsEngine& GfxContext, bool force_draw) {
    int rating = filter_->rating * 10;
    int total_full_stars = rating / 2;
    int total_half_stars = rating % 2;

    nux::Geometry geometry = GetGeometry ();
    geometry.width = geometry.width / 5;
    for (int index = 0; index < 5; index++) {
      geometry.x = index * geometry.width;

      nux::AbstractPaintLayer *render_layer;
      if (index < total_full_stars) {
        render_layer = _full_normal;
      }
      else if (index < total_full_stars + total_half_stars) {
        render_layer = _half_normal;
      }
      else {
        render_layer = _empty_normal;
      }

      render_layer->SetGeometry(geometry);
      render_layer->Renderlayer(GfxContext);

    }
  }

  void FilterRatingsButton::DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw) {
    nux::Button::DrawContent(GfxContext, force_draw);
  }

  void FilterRatingsButton::PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw) {
    nux::Button::PostDraw(GfxContext, force_draw);
  }

  void FilterRatingsButton::RecvMouseDown (int x, int y, unsigned long button_flags, unsigned long key_flags) {
    int width = GetGeometry().width;
    filter_->rating = ceil(x / (width / 10.0));
  }

  void FilterRatingsButton::OnRatingsChanged (int rating) {
    NeedRedraw();
  }

};
