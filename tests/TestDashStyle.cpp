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
 * Authored by: Mirco Müller <mirco.mueller@canonical.com
 */

#include "DashStyle.h"

namespace unity
{
  class DashStyleO : public DashStyle
  {
    public:
      DashStyleO();
      ~DashStyleO();

      bool ScrollbarVert (cairo_t* cr, nux::State state);
      bool TrackView (cairo_t* cr, nux::State state);
  };

  class DashStyleP : public DashStyle
  {
    public:
      DashStyleP();
      ~DashStyleP();

      bool ScrollbarVert (cairo_t* cr, nux::State state);
      bool TrackView (cairo_t* cr, nux::State state);
  };

  DashStyleO::DashStyleO ()
  {
  }

  DashStyleO::~DashStyleO ()
  {
  }

  bool DashStyleO::ScrollbarVert (cairo_t* cr, nux::State state)
  {
    cairo_set_source_rgba (cr, 0.0, 1.0, 0.0, 1.0);
    cairo_paint (cr);

    return true;
  }

  bool DashStyleO::TrackView (cairo_t* cr, nux::State state)
  {
    cairo_set_source_rgba (cr, 0.0, 1.0, 1.0, 1.0);
    cairo_paint (cr);

    return true;
  }

  DashStyleP::DashStyleP ()
  {
  }

  DashStyleP::~DashStyleP ()
  {
  }

  bool DashStyleP::ScrollbarVert (cairo_t* cr, nux::State state)
  {
    cairo_set_source_rgba (cr, 1.0, 0.0, 0.0, 1.0);
    cairo_paint (cr);

    return true;
  }

  bool DashStyleP::TrackView (cairo_t* cr, nux::State state)
  {
    cairo_set_source_rgba (cr, 1.0, 1.0, 0.0, 1.0);
    cairo_paint (cr);

    return true;
  }
}

void wipe (cairo_t* cr)
{
  // sanity check
  if (cairo_status (cr) != CAIRO_STATUS_SUCCESS)
    return;

  cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint (cr);
  cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
  cairo_scale (cr, 1.0, 1.0);
}

int main (int    argc,
          char** argv)
{
  // setup
  //unity::DashStyleO* oDashStyle = new unity::DashStyleO ();
  unity::DashStyleP* pDashStyle = new unity::DashStyleP ();
  cairo_surface_t* surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
                                                         400,
                                                         400);
  cairo_t* cr = cairo_create (surface);
  wipe (cr);

  // render some elements from different styles to PNG-images
  /*if (oDashStyle->ScrollbarVert (cr, nux::NUX_STATE_NORMAL))
  {
    cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/scrollbarv-o.png");
    wipe (cr);
  }

  if (oDashStyle->TrackView (cr, nux::NUX_STATE_NORMAL))
  {
    cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/trackview-o.png");
    wipe (cr);
  }*/

  if (pDashStyle->ScrollbarVert (cr, nux::NUX_STATE_NORMAL))
  {
    cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/scrollbarv-p.png");
    wipe (cr);
  }

  if (pDashStyle->TrackView (cr, nux::NUX_STATE_NORMAL))
  {
    cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/trackview-p.png");
    wipe (cr);
  }

  pDashStyle->Star (cr, nux::NUX_STATE_NORMAL);
  cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/star-p.png");
  wipe (cr);

  pDashStyle->DrawIcon (cr, unity::DashStyle::STOCK_ICON_GRID_VIEW, 0.8, 3);
  cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/icon-p.png");
  wipe (cr);

  // clean up
  cairo_destroy (cr);
  //delete oDashStyle;
  delete pDashStyle;

  return 0;
}
