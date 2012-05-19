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
 * Authored by: Gordon Allott <gord.alott@canonical.com>
 */


#include "BGHash.h"
#include <gdk/gdkx.h>
#include <NuxCore/Logger.h>
#include <libgnome-desktop/gnome-bg.h>
#include <unity-misc/gnome-bg-slideshow.h>
#include "unity-shared/UBusMessages.h"

namespace
{
  nux::logging::Logger logger("unity.BGHash");
}

namespace unity
{

BGHash::BGHash ()
  : background_monitor_(gnome_bg_new()),
    client_(g_settings_new("org.gnome.desktop.background")),
    transition_animator_(500),
    _current_color(unity::colors::Aubergine),
    _new_color(unity::colors::Aubergine),
    _old_color(unity::colors::Aubergine)
{
  _override_color.alpha= 0.0f;

  signal_manager_.Add(
    new glib::Signal<void, GnomeBG*>(background_monitor_,
                                     "changed",
                                     sigc::mem_fun(this, &BGHash::OnBackgroundChanged)));

  signal_manager_.Add(
    new glib::Signal<void, GSettings*, gchar*>(client_,
                                               "changed",
                                               sigc::mem_fun(this, &BGHash::OnGSettingsChanged)));

  gnome_bg_load_from_preferences(background_monitor_, client_);

  transition_animator_.animation_updated.connect(sigc::mem_fun(this, &BGHash::OnTransitionUpdated));
  ubus_manager_.RegisterInterest(UBUS_BACKGROUND_REQUEST_COLOUR_EMIT, [&](GVariant *) { DoUbusColorEmit(); } );

  RefreshColor();
}

BGHash::~BGHash()
{}

void BGHash::OverrideColor (nux::Color color)
{
  _override_color = color;
  OnBackgroundChanged(background_monitor_);
}

void BGHash::RefreshColor()
{
  Atom         real_type;
  gint         result;
  gint         real_format;
  gulong       items_read;
  gulong       items_left;
  gchar*       colors;
  Atom         representative_colors_atom;
  Display*     display;
  GdkRGBA      color_gdk;

  representative_colors_atom = gdk_x11_get_xatom_by_name("_GNOME_BACKGROUND_REPRESENTATIVE_COLORS");
  display = gdk_x11_display_get_xdisplay (gdk_display_get_default ());

  gdk_error_trap_push ();
  result = XGetWindowProperty (display,
             GDK_ROOT_WINDOW (),
             representative_colors_atom,
             0L,
             G_MAXLONG,
             False,
             XA_STRING,
             &real_type,
             &real_format,
             &items_read,
             &items_left,
             (guchar **) &colors);
  gdk_flush ();
  gdk_error_trap_pop_ignored ();

  if (result == Success && items_read)
  {
    gdk_rgba_parse(&color_gdk, colors);
    nux::Color new_color(color_gdk.red,
                         color_gdk.green,
                         color_gdk.blue,
                         1.0f);
    TransitionToNewColor(MatchColor(new_color));
    XFree (colors);
  }
}

void BGHash::OnGSettingsChanged (GSettings *settings, gchar *key)
{
  gnome_bg_load_from_preferences(background_monitor_, client_);
}

void BGHash::OnBackgroundChanged(GnomeBG *bg)
{
  if (_override_color.alpha)
  {
    TransitionToNewColor (_override_color);
    return;
  }

  RefreshColor();
}

nux::Color BGHash::InterpolateColor (nux::Color colora, nux::Color colorb, float value)
{
  // takes two colours, transitions between them, we can do it linearly or whatever
  // i don't think it will matter that much
  // it doesn't happen too often
  return colora + ((colorb - colora) * value);
}

void BGHash::TransitionToNewColor(nux::color::Color new_color)
{
  if (new_color == _current_color)
  {
    LOG_DEBUG(logger) << "rejecting colour";
    return;
  }

  LOG_DEBUG(logger) << "transitioning from: " << _current_color.red << " to " << new_color.red;

  _old_color = _current_color;
  _new_color = new_color;

  transition_animator_.Stop();
  transition_animator_.Start();
}

void BGHash::OnTransitionUpdated(double progress)
{
  _current_color = InterpolateColor(_old_color, _new_color, progress);
  DoUbusColorEmit();
}

void BGHash::DoUbusColorEmit()
{
  ubus_manager_.SendMessage(UBUS_BACKGROUND_COLOR_CHANGED,
                            g_variant_new ("(dddd)",
                                           _current_color.red,
                                           _current_color.green,
                                           _current_color.blue,
                                           _current_color.alpha));
}

nux::Color BGHash::MatchColor (const nux::Color base_color)
{
  nux::Color colors[12];

  colors[ 0] = nux::Color (0x540e44);
  colors[ 1] = nux::Color (0x6e0b2a);
  colors[ 2] = nux::Color (0x841617);
  colors[ 3] = nux::Color (0x84371b);
  colors[ 4] = nux::Color (0x864d20);
  colors[ 5] = nux::Color (0x857f31);
  colors[ 6] = nux::Color (0x1d6331);
  colors[ 7] = nux::Color (0x11582e);
  colors[ 8] = nux::Color (0x0e5955);
  colors[ 9] = nux::Color (0x192b59);
  colors[10] = nux::Color (0x1b134c);
  colors[11] = nux::Color (0x2c0d46);

  float closest_diff = 200.0f;
  nux::Color chosen_color;
  nux::color::HueSaturationValue base_hsv (base_color);

  if (base_hsv.saturation < 0.08)
  {
    // grayscale image
    LOG_DEBUG (logger) << "got a grayscale image";
    chosen_color = nux::Color (46 , 52 , 54 );
    chosen_color.alpha = 0.72f;
  }
  else
  {
    LOG_DEBUG (logger) << "got a colour image";
    // full colour image
    for (int i = 0; i < 11; i++)
    {
      nux::color::HueSaturationValue comparison_hsv (colors[i]);
      float color_diff = fabs(base_hsv.hue - comparison_hsv.hue);

      if (color_diff < closest_diff)
      {
        chosen_color = colors[i];
        closest_diff = color_diff;
      }
    }

    nux::color::HueSaturationValue hsv_color (chosen_color);
    hsv_color.saturation = std::min(base_hsv.saturation, hsv_color.saturation);
    hsv_color.saturation *= (2.0f - hsv_color.saturation);
    hsv_color.value = std::min(std::min(base_hsv.value, hsv_color.value), 0.26f);

    chosen_color = nux::Color (nux::color::RedGreenBlue(hsv_color));
    chosen_color.alpha = 0.72f;
  }

  LOG_DEBUG(logger) << "eventually chose "
                    << chosen_color.red << ", "
                    << chosen_color.green << ", "
                    << chosen_color.blue;
  return chosen_color;
}

nux::Color BGHash::CurrentColor ()
{
  return _current_color;
}

}
