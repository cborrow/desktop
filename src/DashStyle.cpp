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

#include <math.h>
#include <glib.h>
#include <gdk/gdk.h>
#include <pango/pango.h>
#include <json-glib/json-glib.h>

#include "DashStyle.h"

//#define DASH_WIDGETS_FILE "/usr/share/unity/themes/dash-widgets.json"
#define DASH_WIDGETS_FILE "/home/mirco/src/avantika-team/unity.style/resources/dash-widgets.json"

namespace unity
{
  bool DashStyle::ReadColorSingle (JsonNode*    root,
                                   const gchar* nodeName,
                                   const gchar* memberName,
                                   double*      color)
  {
	JsonObject* object = NULL;
	JsonNode*   node   = NULL;

    if (!root || !nodeName || !memberName || !color)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);

    const gchar* string = NULL;
    PangoColor   col    = {0, 0, 0};

    string = json_object_get_string_member (object, memberName);
    pango_color_parse (&col, string);
    color[R] = (double) col.red   / (double) 0xffff;
    color[G] = (double) col.green / (double) 0xffff;
    color[B] = (double) col.blue  / (double) 0xffff;
    
    return true;
  }

  bool DashStyle::ReadColorArray (JsonNode*    root,
                                  const gchar* nodeName,
                                  const gchar* memberName,
                                  double colors[][CHANNELS])
  {
	JsonObject*  object = NULL;
	JsonNode*    node   = NULL;
    JsonArray*   array  = NULL;
    unsigned int i      = 0;

    if (!root || !nodeName || !memberName || !colors)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);
    array  = json_object_get_array_member (object, memberName);

    for (i = 0; i < json_array_get_length (array); i++)
    {
      const gchar* string = NULL;
      PangoColor   color  = {0, 0, 0};
      string = json_array_get_string_element (array, i);
      pango_color_parse (&color, string);
      colors[i][R] = (double) color.red   / (double) 0xffff;
      colors[i][G] = (double) color.green / (double) 0xffff;
      colors[i][B] = (double) color.blue  / (double) 0xffff;
    }
    
    return true;
  }

  bool DashStyle::ReadDoubleSingle (JsonNode*    root,
                                    const gchar* nodeName,
                                    const gchar* memberName,
                                    double*      value)
  {
	JsonObject* object = NULL;
	JsonNode*   node   = NULL;

    if (!root || !nodeName || !memberName || !value)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);

    *value = json_object_get_double_member (object, memberName);

    return true;
  }

  bool DashStyle::ReadDoubleArray (JsonNode*    root,
                                   const gchar* nodeName,
                                   const gchar* memberName,
                                   double*      values)
  {
	JsonObject*  object = NULL;
	JsonNode*    node   = NULL;
    JsonArray*   array  = NULL;
    unsigned int i      = 0;

    if (!root || !nodeName || !memberName || !values)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);
    array  = json_object_get_array_member (object, memberName);

    for (i = 0; i < json_array_get_length (array); i++)
      values[i] = json_array_get_double_element (array, i);

    return true;
  }

  bool DashStyle::ReadIntSingle (JsonNode*    root,
                                 const gchar* nodeName,
                                 const gchar* memberName,
                                 int*         value)
  {
	JsonObject* object = NULL;
	JsonNode*   node   = NULL;

    if (!root || !nodeName || !memberName || !value)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);

    *value = json_object_get_int_member (object, memberName);

    return true;
  }

  bool DashStyle::ReadIntArray (JsonNode*    root,
                                const gchar* nodeName,
                                const gchar* memberName,
                                int*         values)
  {
	JsonObject*  object = NULL;
	JsonNode*    node   = NULL;
    JsonArray*   array  = NULL;
    unsigned int i      = 0;

    if (!root || !nodeName || !memberName || !values)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);
    array  = json_object_get_array_member (object, memberName);

    for (i = 0; i < json_array_get_length (array); i++)
      values[i] = json_array_get_int_element (array, i);

    return true;
  }

  bool DashStyle::ReadModeSingle (JsonNode*    root,
                                  const gchar* nodeName,
                                  const gchar* memberName,
                                  BlendMode*   mode)
  {
	JsonObject*  object = NULL;
	JsonNode*    node   = NULL;
    const gchar* string = NULL;

    if (!root || !nodeName || !memberName || !mode)
      return false;

    object = json_node_get_object (root);
    node   = json_object_get_member (object, nodeName);
    object = json_node_get_object (node);

    string = json_object_get_string_member (object, memberName);
    if (!g_strcmp0 (string, "normal"))
      *mode = BLEND_MODE_NORMAL ;

    if (!g_strcmp0 (string, "multiply"))
      *mode = BLEND_MODE_MULTIPLY ;

    if (!g_strcmp0 (string, "screen"))
      *mode = BLEND_MODE_SCREEN ;

    return true;
  }

  bool DashStyle::ReadModeArray (JsonNode*    root,
                                 const gchar* nodeName,
                                 const gchar* memberName,
                                 BlendMode*   modes)
  {
    if (!root || !nodeName || !memberName || !modes)
      return false;

    return true;
  }

  bool DashStyle::ReadStyleSingle (JsonNode*    root,
                                   const gchar* nodeName,
                                   const gchar* memberName,
                                   FontStyle*   style)
  {
    if (!root || !nodeName || !memberName || !style)
      return false;

    return true;
  }

  bool DashStyle::ReadStyleArray (JsonNode*    root,
                                  const gchar* nodeName,
                                  const gchar* memberName,
                                  FontStyle*   styles)
  {
    if (!root || !nodeName || !memberName || !styles)
      return false;

    return true;
  }

  DashStyle::DashStyle ()
  {
    JsonParser*  parser = NULL;
    GError*      error  = NULL;
    gboolean     result = FALSE;
    JsonNode*    root   = NULL;
    unsigned int i      = 0;

	g_type_init ();

    parser = json_parser_new ();
    result = json_parser_load_from_file (parser, DASH_WIDGETS_FILE, &error);
    if (!result)
    {
      g_object_unref (parser);
      g_warning ("Failure: %s", error->message);
      g_error_free (error);
      UseDefaultValues ();
	  return;
    }

    root = json_parser_get_root (parser); // not ref'ed

    if (JSON_NODE_TYPE (root) != JSON_NODE_OBJECT)
    {
      g_warning ("Root node is not an object, fail.  It's an: %s",
                 json_node_type_name (root));
      g_object_unref (parser);
      UseDefaultValues ();
      return;
    }

    ReadColorSingle (root, "icon-only", "color", _iconOnlyColor);
    g_print ("icon-only color = %1.2f/%1.2f/%1.2f\n",
             _iconOnlyColor[R],
             _iconOnlyColor[G],
             _iconOnlyColor[B]);

    ReadColorArray (root, "button-icon", "color", _buttonIconColor);
    for (i = 0; i < 5; i++)
    {
      g_print ("button-icon color = %1.2f/%1.2f/%1.2f\n",
               _buttonIconColor[i][R],
               _buttonIconColor[i][G],
               _buttonIconColor[i][B]);
    }

    ReadDoubleSingle (root, "icon-only", "opacity", &_iconOnlyOpacity);
    g_print ("icon-only opacity = %1.2f\n", _iconOnlyOpacity);

    ReadDoubleArray (root, "button-icon", "opacity", _buttonIconOpacity);
    for (i = 0; i < 5; i++)
      g_print ("button-icon opacity = %1.2f\n", _buttonIconOpacity[i]);

    ReadDoubleArray (root, "button-icon", "overlay-opacity", _buttonIconOverlayOpacity);
    for (i = 0; i < 5; i++)
      g_print ("button-icon overlay-opacity = %1.2f\n", _buttonIconOverlayOpacity[i]);

    ReadIntArray (root, "button-icon", "blur-size", _buttonIconBlurSize);
    for (i = 0; i < 5; i++)
      g_print ("button-icon blur-size = %d\n", _buttonIconBlurSize[i]);

    ReadModeSingle (root, "icon-only", "overlay-mode", &_iconOnlyOverlayMode);
    g_print ("icon-only overlay-mode = %d\n", _iconOnlyOverlayMode);

    g_object_unref (parser);
  }

  DashStyle::~DashStyle ()
  {
  }

  bool DashStyle::ButtonWithIcon (cairo_t*             cr,
                                  DashStyle::StockIcon id,
                                  nux::State           state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

	// clear context
    cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
    cairo_paint (cr);
	cairo_scale (cr, 1.0, 1.0);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);

    // draw icon
    DrawIcon (cr,
              id,
              _buttonIconOpacity[state],
              _buttonIconBlurSize[state]);

    return true;
  }

  bool DashStyle::ButtonWithLabel (cairo_t*    cr,
                                   const char* text,
                                   nux::State  state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::ButtonWithIconAndLabel (cairo_t*             cr,
                                          DashStyle::StockIcon id,
                                          const char*          text,
                                          nux::State           state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::ScrollbarVert (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::ScrollbarHoriz (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::TrackView (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::PreviewHeading (cairo_t* cr)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::MultiRangeBar (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::RatingsBar (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::LensNavBar (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::SeparatorVert (cairo_t* cr)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::SeparatorHoriz (cairo_t* cr)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  bool DashStyle::ButtonBackground (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return false;

    return true;
  }

  static inline double
  _align (double val)
  {
    double fract = val - (int) val;

    if (fract != 0.5f)
      return (double) ((int) val + 0.5f);
    else
      return val;
  }

  void
  DashStyle::RoundedRect (cairo_t* cr,
                          double   aspect,
                          double   x,
                          double   y,
                          double   cornerRadius,
                          double   width,
                          double   height,
                          bool     align)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

    double radius = cornerRadius / aspect;

    if (align)
    {
      // top-left, right of the corner
      cairo_move_to (cr, _align (x + radius), _align (y));

      // top-right, left of the corner
      cairo_line_to (cr, _align (x + width - radius), _align (y));

      // top-right, below the corner
      cairo_arc (cr,
                 _align (x + width - radius),
                 _align (y + radius),
                 radius,
                 -90.0f * G_PI / 180.0f,
                 0.0f * G_PI / 180.0f);

      // bottom-right, above the corner
      cairo_line_to (cr, _align (x + width), _align (y + height - radius));

      // bottom-right, left of the corner
      cairo_arc (cr,
                 _align (x + width - radius),
                 _align (y + height - radius),
                 radius,
                 0.0f * G_PI / 180.0f,
                 90.0f * G_PI / 180.0f);

      // bottom-left, right of the corner
      cairo_line_to (cr, _align (x + radius), _align (y + height));

      // bottom-left, above the corner
      cairo_arc (cr,
                 _align (x + radius),
                 _align (y + height - radius),
                 radius,
                 90.0f * G_PI / 180.0f,
                 180.0f * G_PI / 180.0f);

      // top-left, right of the corner
      cairo_arc (cr,
                 _align (x + radius),
                 _align (y + radius),
                 radius,
                 180.0f * G_PI / 180.0f,
                 270.0f * G_PI / 180.0f);
    }
    else
    {
      // top-left, right of the corner
      cairo_move_to (cr, x + radius, y);

      // top-right, left of the corner
      cairo_line_to (cr, x + width - radius, y);

      // top-right, below the corner
      cairo_arc (cr,
                 x + width - radius,
                 y + radius,
                 radius,
                 -90.0f * G_PI / 180.0f,
                 0.0f * G_PI / 180.0f);

      // bottom-right, above the corner
      cairo_line_to (cr, x + width, y + height - radius);

      // bottom-right, left of the corner
      cairo_arc (cr,
                 x + width - radius,
                 y + height - radius,
                 radius,
                 0.0f * G_PI / 180.0f,
                 90.0f * G_PI / 180.0f);

      // bottom-left, right of the corner
      cairo_line_to (cr, x + radius, y + height);

      // bottom-left, above the corner
      cairo_arc (cr,
                 x + radius,
                 y + height - radius,
                 radius,
                 90.0f * G_PI / 180.0f,
                 180.0f * G_PI / 180.0f);

      // top-left, right of the corner
      cairo_arc (cr,
                 x + radius,
                 y + radius,
                 radius,
                 180.0f * G_PI / 180.0f,
                 270.0f * G_PI / 180.0f);
    }
  }

  void DashStyle::DrawIcon (cairo_t*             cr,
                            DashStyle::StockIcon id,
                            double               opacity,
                            int                  blurSize)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

	double x;
	double y;
	double w;
	double h;
    double width;
	double height;

	width  = cairo_image_surface_get_width (cairo_get_target (cr));
	height = cairo_image_surface_get_height (cairo_get_target (cr));
	w = 48.0;
	h = 48.0;
	x = (width - w) / 2.0;
	y = (height - h) / 2.0;

    switch (id)
	{
      case STOCK_ICON_CHECKMARK:
        cairo_set_source_rgba (cr, 1.0, 0.9, 0.5, opacity);
		cairo_rectangle (cr, x, y, w, h);
		cairo_fill (cr);
	  break;

      case STOCK_ICON_CROSS:
        cairo_set_source_rgba (cr, 0.4, 0.9, 0.2, opacity);
		cairo_rectangle (cr, x, y, w, h);
		cairo_fill (cr);
	  break;

      case STOCK_ICON_GRID_VIEW:
        cairo_set_source_rgba (cr, 0.4, 0.2, 0.7, opacity);
		cairo_rectangle (cr, x, y, w, h);
		cairo_fill (cr);
	  break;

      case STOCK_ICON_FLOW_VIEW:
        cairo_set_source_rgba (cr, 0.0, 0.5, 1.0, opacity);
		cairo_rectangle (cr, x, y, w, h);
		cairo_fill (cr);
	  break;

      case STOCK_ICON_STAR:
        cairo_set_source_rgba (cr, 0.0, 0.0, 1.0, opacity);
		cairo_rectangle (cr, x, y, w, h);
		cairo_fill (cr);
	  break;
	}

	Blur (cr, blurSize);
  }

  static inline void _blurinner (guchar* pixel,
                                 gint*   zR,
                                 gint*   zG,
                                 gint*   zB,
                                 gint*   zA,
                                 gint    alpha,
                                 gint    aprec,
                                 gint    zprec)
  {
    gint   r;
    gint   g;
    gint   b;
    guchar a;

    r = *pixel;
    g = *(pixel + 1);
    b = *(pixel + 2);
    a = *(pixel + 3);

    *zR += (alpha * ((r << zprec) - *zR)) >> aprec;
    *zG += (alpha * ((g << zprec) - *zG)) >> aprec;
    *zB += (alpha * ((b << zprec) - *zB)) >> aprec;
    *zA += (alpha * ((a << zprec) - *zA)) >> aprec;

    *pixel       = *zR >> zprec;
    *(pixel + 1) = *zG >> zprec;
    *(pixel + 2) = *zB >> zprec;
    *(pixel + 3) = *zA >> zprec;
  }

  static inline void _blurrow (guchar* pixels,
                               gint    width,
                               gint    height,
                               gint    channels,
                               gint    line,
                               gint    alpha,
                               gint    aprec,
                               gint    zprec)
  {
    gint    zR;
    gint    zG;
    gint    zB;
    gint    zA;
    gint    index;
    guchar* scanline;

    scanline = &(pixels[line * width * channels]);

    zR = *scanline << zprec;
    zG = *(scanline + 1) << zprec;
    zB = *(scanline + 2) << zprec;
    zA = *(scanline + 3) << zprec;

    for (index = 0; index < width; index ++)
      _blurinner (&scanline[index * channels], &zR, &zG, &zB, &zA, alpha, aprec,
      zprec);

    for (index = width - 2; index >= 0; index--)
      _blurinner (&scanline[index * channels], &zR, &zG, &zB, &zA, alpha, aprec,
      zprec);
  }

  static inline void _blurcol (guchar* pixels,
                               gint    width,
                               gint    height,
                               gint    channels,
                               gint    x,
                               gint    alpha,
                               gint    aprec,
                               gint    zprec)
  {
    gint zR;
    gint zG;
    gint zB;
    gint zA;
    gint index;
    guchar* ptr;

    ptr = pixels;

    ptr += x * channels;

    zR = *((guchar*) ptr    ) << zprec;
    zG = *((guchar*) ptr + 1) << zprec;
    zB = *((guchar*) ptr + 2) << zprec;
    zA = *((guchar*) ptr + 3) << zprec;

    for (index = width; index < (height - 1) * width; index += width)
      _blurinner ((guchar*) &ptr[index * channels], &zR, &zG, &zB, &zA, alpha,
      aprec, zprec);

    for (index = (height - 2) * width; index >= 0; index -= width)
      _blurinner ((guchar*) &ptr[index * channels], &zR, &zG, &zB, &zA, alpha,
      aprec, zprec);
  }

  //
  // pixels   image-data
  // width    image-width
  // height   image-height
  // channels image-channels
  //
  // in-place blur of image 'img' with kernel of approximate radius 'radius'
  //
  // blurs with two sided exponential impulse response
  //
  // aprec = precision of alpha parameter in fixed-point format 0.aprec
  //
  // zprec = precision of state parameters zR,zG,zB and zA in fp format 8.zprec
  //
  void _expblur (guchar* pixels,
                 gint    width,
                 gint    height,
                 gint    channels,
                 gint    radius,
                 gint    aprec,
                 gint    zprec)
  {
    gint alpha;
    gint row = 0;
    gint col = 0;

    if (radius < 1)
      return;

    // calculate the alpha such that 90% of 
    // the kernel is within the radius.
    // (Kernel extends to infinity)
    alpha = (gint) ((1 << aprec) * (1.0f - expf (-2.3f / (radius + 1.f))));

    for (; row < height; row++)
      _blurrow (pixels, width, height, channels, row, alpha, aprec, zprec);

    for(; col < width; col++)
      _blurcol (pixels, width, height, channels, col, alpha, aprec, zprec);

    return;
  }

  void DashStyle::Blur (cairo_t* cr, int size)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

    cairo_surface_t* surface;
    guchar*          pixels;
    guint            width;
    guint            height;
    cairo_format_t   format;

    surface = cairo_get_target (cr);

    // before we mess with the surface execute any pending drawing
    cairo_surface_flush (surface);

    pixels = cairo_image_surface_get_data (surface);
    width  = cairo_image_surface_get_width (surface);
    height = cairo_image_surface_get_height (surface);
    format = cairo_image_surface_get_format (surface);

    switch (format)
    {
      case CAIRO_FORMAT_ARGB32:
        _expblur (pixels, width, height, 4, size, 16, 7);
      break;

      case CAIRO_FORMAT_RGB24:
        _expblur (pixels, width, height, 3, size, 16, 7);
      break;

      case CAIRO_FORMAT_A8:
        _expblur (pixels, width, height, 1, size, 16, 7);
      break;

      default :
        // do nothing
      break;
    }

    // inform cairo we altered the surfaces contents
    cairo_surface_mark_dirty (surface);
  }

  void DashStyle::Text (cairo_t* cr)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

  }

  void DashStyle::Triangle (cairo_t*               cr,
                            DashStyle::Orientation orientation,
                            nux::State             state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

  }

  void DashStyle::Star (cairo_t* cr, nux::State state)
  {
    // sanity check
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS &&
        cairo_surface_get_type (cairo_get_target (cr)) != CAIRO_SURFACE_TYPE_IMAGE)
      return;

    double outter[5][2] = {{0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0}};
    double inner[5][2]  = {{0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0}};
    double angle[5]     = {-90.0, -18.0, 54.0, 126.0, 198.0};
    double outterRadius = 1.0;
    double innerRadius  = 0.5;

    for (int i = 0; i < 5; i++)
    {
      outter[i][0] = outterRadius * cos (angle[i] * M_PI / 180.0);
      outter[i][1] = outterRadius * sin (angle[i] * M_PI / 180.0);
      inner[i][0]  = innerRadius * cos ((angle[i] + 36.0) * M_PI / 180.0);
      inner[i][1]  = innerRadius * sin ((angle[i] + 36.0) * M_PI / 180.0);
    }

    cairo_pattern_t* pattern = cairo_pattern_create_linear (0.0, 0.0, 10.0, 0.0);
    cairo_pattern_add_color_stop_rgba (pattern, 0.0,   1.0, 1.0, 1.0, 1.0);
    cairo_pattern_add_color_stop_rgba (pattern, 0.25,  1.0, 1.0, 1.0, 1.0);
    cairo_pattern_add_color_stop_rgba (pattern, 0.251, 1.0, 1.0, 1.0, 0.5);
    cairo_pattern_add_color_stop_rgba (pattern, 1.0,   1.0, 1.0, 1.0, 0.5);
    cairo_pattern_set_extend (pattern, CAIRO_EXTEND_REPEAT);
    cairo_set_source (cr, pattern);
    cairo_matrix_t matrix; // will die with the end of this scope
    cairo_matrix_init_rotate (&matrix, 45.0 * M_PI / 180.0);
    cairo_pattern_set_matrix (pattern, &matrix);
    //cairo_rectangle (cr, 100.0, 200.0, 75.0, 150.0);
    //cairo_fill (cr);

    cairo_translate (cr, 50.0, 50.0);
    cairo_save (cr);
    cairo_scale (cr, 25.0, 25.0);
    cairo_move_to (cr, outter[0][0], outter[0][1]);
    cairo_line_to (cr, inner[0][0], inner[0][1]);
    cairo_line_to (cr, outter[1][0], outter[1][1]);
    cairo_line_to (cr, inner[1][0], inner[1][1]);
    cairo_line_to (cr, outter[2][0], outter[2][1]);
    cairo_line_to (cr, inner[2][0], inner[2][1]);
    cairo_line_to (cr, outter[3][0], outter[3][1]);
    cairo_line_to (cr, inner[3][0], inner[3][1]);
    cairo_line_to (cr, outter[4][0], outter[4][1]);
    cairo_line_to (cr, inner[4][0], inner[4][1]);
    cairo_close_path (cr);
    cairo_restore (cr);

    //cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.75);
    //cairo_rectangle (cr, -(4.0 * 50.0 + 4.0 * 7.0), -30.0, 4.0 * 50.0 + 4.0 * 7.0, 55.0);
    //cairo_clip (cr);
    cairo_fill_preserve (cr);
    cairo_pattern_destroy (pattern);
    pattern = cairo_pattern_create_rgba (1.0, 1.0, 1.0, 1.0);
    cairo_set_source (cr, pattern);
    //cairo_reset_clip (cr);
    cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 1.0);
    cairo_stroke (cr);

    cairo_set_source_rgba (cr, 1.0, 0.0, 0.0, 0.5);
    cairo_rectangle (cr, -(4.0 * 50.0 + 4.0 * 7.0), -30.0, 4.0 * 50.0 + 4.0 * 7.0, 55.0);
    cairo_fill (cr);

  }

  void DashStyle::UseDefaultValues ()
  {
    _buttonIconColor[nux::NUX_STATE_NORMAL][R]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_NORMAL][G]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_NORMAL][B]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_ACTIVE][R]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_ACTIVE][G]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_ACTIVE][B]      = 1.0;
    _buttonIconColor[nux::NUX_STATE_PRELIGHT][R]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_PRELIGHT][G]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_PRELIGHT][B]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_SELECTED][R]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_SELECTED][G]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_SELECTED][B]    = 1.0;
    _buttonIconColor[nux::NUX_STATE_INSENSITIVE][R] = 1.0;
    _buttonIconColor[nux::NUX_STATE_INSENSITIVE][G] = 1.0;
    _buttonIconColor[nux::NUX_STATE_INSENSITIVE][B] = 1.0;
    _buttonIconOpacity[nux::NUX_STATE_NORMAL]       = 1.0;
    _buttonIconOpacity[nux::NUX_STATE_ACTIVE]       = 1.0;
    _buttonIconOpacity[nux::NUX_STATE_PRELIGHT]     = 1.0;
    _buttonIconOpacity[nux::NUX_STATE_SELECTED]     = 1.0;
    _buttonIconOpacity[nux::NUX_STATE_INSENSITIVE]  = 1.0;
    _buttonIconOverlayOpacity[nux::NUX_STATE_NORMAL]      = 0.0;
	_buttonIconOverlayOpacity[nux::NUX_STATE_ACTIVE]      = 0.0;
    _buttonIconOverlayOpacity[nux::NUX_STATE_PRELIGHT]    = 0.0;
	_buttonIconOverlayOpacity[nux::NUX_STATE_SELECTED]    = 0.0;
	_buttonIconOverlayOpacity[nux::NUX_STATE_INSENSITIVE] = 0.0;
    _buttonIconOverlayMode[nux::NUX_STATE_NORMAL]      = BLEND_MODE_NORMAL;
    _buttonIconOverlayMode[nux::NUX_STATE_ACTIVE]      = BLEND_MODE_NORMAL;
    _buttonIconOverlayMode[nux::NUX_STATE_PRELIGHT]    = BLEND_MODE_NORMAL;
    _buttonIconOverlayMode[nux::NUX_STATE_SELECTED]    = BLEND_MODE_NORMAL;
    _buttonIconOverlayMode[nux::NUX_STATE_INSENSITIVE] = BLEND_MODE_NORMAL;
    _buttonIconBlurSize[nux::NUX_STATE_NORMAL]      = 0;
    _buttonIconBlurSize[nux::NUX_STATE_ACTIVE]      = 0;
    _buttonIconBlurSize[nux::NUX_STATE_PRELIGHT]    = 0;
    _buttonIconBlurSize[nux::NUX_STATE_SELECTED]    = 0;
    _buttonIconBlurSize[nux::NUX_STATE_INSENSITIVE] = 0;
  }
}
