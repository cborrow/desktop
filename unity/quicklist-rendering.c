/* quicklist-rendering.c generated by valac, the Vala compiler
 * generated from quicklist-rendering.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <cairo.h>
#include <pango/pangocairo.h>
#include <pango/pango.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>


#define UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR (unity_quicklist_rendering_seperator_get_type ())
#define UNITY_QUICKLIST_RENDERING_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperator))
#define UNITY_QUICKLIST_RENDERING_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperatorClass))
#define UNITY_QUICKLIST_RENDERING_IS_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR))
#define UNITY_QUICKLIST_RENDERING_IS_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR))
#define UNITY_QUICKLIST_RENDERING_SEPERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperatorClass))

typedef struct _UnityQuicklistRenderingSeperator UnityQuicklistRenderingSeperator;
typedef struct _UnityQuicklistRenderingSeperatorClass UnityQuicklistRenderingSeperatorClass;
typedef struct _UnityQuicklistRenderingSeperatorPrivate UnityQuicklistRenderingSeperatorPrivate;

#define UNITY_QUICKLIST_RENDERING_TYPE_ITEM (unity_quicklist_rendering_item_get_type ())
#define UNITY_QUICKLIST_RENDERING_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItem))
#define UNITY_QUICKLIST_RENDERING_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItemClass))
#define UNITY_QUICKLIST_RENDERING_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM))
#define UNITY_QUICKLIST_RENDERING_IS_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_ITEM))
#define UNITY_QUICKLIST_RENDERING_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItemClass))

typedef struct _UnityQuicklistRenderingItem UnityQuicklistRenderingItem;
typedef struct _UnityQuicklistRenderingItemClass UnityQuicklistRenderingItemClass;
typedef struct _UnityQuicklistRenderingItemPrivate UnityQuicklistRenderingItemPrivate;
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _pango_font_description_free0(var) ((var == NULL) ? NULL : (var = (pango_font_description_free (var), NULL)))

#define UNITY_QUICKLIST_RENDERING_TYPE_MENU (unity_quicklist_rendering_menu_get_type ())
#define UNITY_QUICKLIST_RENDERING_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenu))
#define UNITY_QUICKLIST_RENDERING_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenuClass))
#define UNITY_QUICKLIST_RENDERING_IS_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU))
#define UNITY_QUICKLIST_RENDERING_IS_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_MENU))
#define UNITY_QUICKLIST_RENDERING_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenuClass))

typedef struct _UnityQuicklistRenderingMenu UnityQuicklistRenderingMenu;
typedef struct _UnityQuicklistRenderingMenuClass UnityQuicklistRenderingMenuClass;
typedef struct _UnityQuicklistRenderingMenuPrivate UnityQuicklistRenderingMenuPrivate;
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))

struct _UnityQuicklistRenderingSeperator {
	GObject parent_instance;
	UnityQuicklistRenderingSeperatorPrivate * priv;
};

struct _UnityQuicklistRenderingSeperatorClass {
	GObjectClass parent_class;
};

struct _UnityQuicklistRenderingItem {
	GObject parent_instance;
	UnityQuicklistRenderingItemPrivate * priv;
};

struct _UnityQuicklistRenderingItemClass {
	GObjectClass parent_class;
};

struct _UnityQuicklistRenderingMenu {
	GObject parent_instance;
	UnityQuicklistRenderingMenuPrivate * priv;
};

struct _UnityQuicklistRenderingMenuClass {
	GObjectClass parent_class;
};


static gpointer unity_quicklist_rendering_seperator_parent_class = NULL;
static gpointer unity_quicklist_rendering_item_parent_class = NULL;
static gpointer unity_quicklist_rendering_menu_parent_class = NULL;

#define UNITY_QUICKLIST_RENDERING_LINE_WIDTH 0.083f
#define UNITY_QUICKLIST_RENDERING_LINE_WIDTH_ABS 1.5f
#define UNITY_QUICKLIST_RENDERING_TEXT_HEIGHT 1.0f
#define UNITY_QUICKLIST_RENDERING_MAX_TEXT_WIDTH 15.0f
#define UNITY_QUICKLIST_RENDERING_GAP 0.25f
#define UNITY_QUICKLIST_RENDERING_MARGIN 0.5f
#define UNITY_QUICKLIST_RENDERING_BORDER 0.25f
#define UNITY_QUICKLIST_RENDERING_CORNER_RADIUS 0.3f
#define UNITY_QUICKLIST_RENDERING_CORNER_RADIUS_ABS 5.0f
#define UNITY_QUICKLIST_RENDERING_SHADOW_SIZE 1.25f
#define UNITY_QUICKLIST_RENDERING_ITEM_HEIGHT 2.0f
#define UNITY_QUICKLIST_RENDERING_ITEM_CORNER_RADIUS 0.3f
#define UNITY_QUICKLIST_RENDERING_ITEM_CORNER_RADIUS_ABS 4.0f
#define UNITY_QUICKLIST_RENDERING_ANCHOR_HEIGHT 1.5f
#define UNITY_QUICKLIST_RENDERING_ANCHOR_HEIGHT_ABS 18.0f
#define UNITY_QUICKLIST_RENDERING_ANCHOR_WIDTH 0.75f
#define UNITY_QUICKLIST_RENDERING_ANCHOR_WIDTH_ABS 10.0f
GType unity_quicklist_rendering_seperator_get_type (void);
enum  {
	UNITY_QUICKLIST_RENDERING_SEPERATOR_DUMMY_PROPERTY
};
void unity_quicklist_rendering_seperator_fill_mask (cairo_t* cr);
void unity_quicklist_rendering_seperator_image_background (cairo_t* cr, gint w, gint h);
UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_new (void);
UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_construct (GType object_type);
GType unity_quicklist_rendering_item_get_type (void);
enum  {
	UNITY_QUICKLIST_RENDERING_ITEM_DUMMY_PROPERTY
};
static void _unity_quicklist_rendering_item_round_rect (cairo_t* cr, double aspect, double x, double y, double corner_radius, double width, double height);
void unity_quicklist_rendering_item_get_text_extents (const char* font, const char* text, gint* width, gint* height);
void unity_quicklist_rendering_item_normal_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text);
void unity_quicklist_rendering_item_selected_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text);
UnityQuicklistRenderingItem* unity_quicklist_rendering_item_new (void);
UnityQuicklistRenderingItem* unity_quicklist_rendering_item_construct (GType object_type);
GType unity_quicklist_rendering_menu_get_type (void);
enum  {
	UNITY_QUICKLIST_RENDERING_MENU_DUMMY_PROPERTY
};
static double _unity_quicklist_rendering_menu_align (double val);
static void _unity_quicklist_rendering_menu_round_rect_anchor (cairo_t* cr, double aspect, double x, double y, double corner_radius, double width, double height, double anchor_width, double anchor_height, double anchor_x, double anchor_y);
static void _unity_quicklist_rendering_menu_draw_mask (cairo_t* cr, gint w, gint h, float anchor_y);
void unity_quicklist_rendering_menu_full_mask (cairo_t* cr, gint w, gint h, float anchor_y);
void unity_quicklist_rendering_menu_fill_mask (cairo_t* cr, gint w, gint h, float anchor_y);
void unity_quicklist_rendering_menu_background (cairo_t* cr, gint w, gint h, float anchor_y);
UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_new (void);
UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_construct (GType object_type);



void unity_quicklist_rendering_seperator_fill_mask (cairo_t* cr) {
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f);
	cairo_paint (cr);
}


void unity_quicklist_rendering_seperator_image_background (cairo_t* cr, gint w, gint h) {
	float half_height;
	float fract;
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_set_line_width (cr, (double) 1.5f);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.75f);
	cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
	half_height = ((float) h) / 2.0f;
	fract = half_height - ((gint) half_height);
	if (fract == 0.0f) {
		half_height = half_height + 0.5f;
	}
	cairo_move_to (cr, (double) 0.0f, (double) half_height);
	cairo_line_to (cr, (double) ((float) w), (double) half_height);
	cairo_stroke (cr);
}


UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_construct (GType object_type) {
	UnityQuicklistRenderingSeperator * self;
	self = (UnityQuicklistRenderingSeperator*) g_object_new (object_type, NULL);
	return self;
}


UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_new (void) {
	return unity_quicklist_rendering_seperator_construct (UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR);
}


static void unity_quicklist_rendering_seperator_class_init (UnityQuicklistRenderingSeperatorClass * klass) {
	unity_quicklist_rendering_seperator_parent_class = g_type_class_peek_parent (klass);
}


static void unity_quicklist_rendering_seperator_instance_init (UnityQuicklistRenderingSeperator * self) {
}


GType unity_quicklist_rendering_seperator_get_type (void) {
	static volatile gsize unity_quicklist_rendering_seperator_type_id__volatile = 0;
	if (g_once_init_enter (&unity_quicklist_rendering_seperator_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityQuicklistRenderingSeperatorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_quicklist_rendering_seperator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityQuicklistRenderingSeperator), 0, (GInstanceInitFunc) unity_quicklist_rendering_seperator_instance_init, NULL };
		GType unity_quicklist_rendering_seperator_type_id;
		unity_quicklist_rendering_seperator_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityQuicklistRenderingSeperator", &g_define_type_info, 0);
		g_once_init_leave (&unity_quicklist_rendering_seperator_type_id__volatile, unity_quicklist_rendering_seperator_type_id);
	}
	return unity_quicklist_rendering_seperator_type_id__volatile;
}


static void _unity_quicklist_rendering_item_round_rect (cairo_t* cr, double aspect, double x, double y, double corner_radius, double width, double height) {
	double radius;
	g_return_if_fail (cr != NULL);
	radius = corner_radius / aspect;
	cairo_move_to (cr, x + radius, y);
	cairo_line_to (cr, (x + width) - radius, y);
	cairo_arc (cr, (x + width) - radius, y + radius, radius, ((-90.0f) * G_PI) / 180.0f, (0.0f * G_PI) / 180.0f);
	cairo_line_to (cr, x + width, (y + height) - radius);
	cairo_arc (cr, (x + width) - radius, (y + height) - radius, radius, (0.0f * G_PI) / 180.0f, (90.0f * G_PI) / 180.0f);
	cairo_line_to (cr, x + radius, y + height);
	cairo_arc (cr, x + radius, (y + height) - radius, radius, (90.0f * G_PI) / 180.0f, (180.0f * G_PI) / 180.0f);
	cairo_arc (cr, x + radius, y + radius, radius, (180.0f * G_PI) / 180.0f, (270.0f * G_PI) / 180.0f);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_quicklist_rendering_item_get_text_extents (const char* font, const char* text, gint* width, gint* height) {
	cairo_surface_t* surface;
	cairo_t* cr;
	PangoLayout* layout;
	GtkSettings* settings;
	PangoFontDescription* desc;
	PangoContext* pango_context;
	GdkScreen* screen;
	gint _tmp0_;
	PangoRectangle log_rect = {0};
	g_return_if_fail (font != NULL);
	g_return_if_fail (text != NULL);
	surface = cairo_image_surface_create (CAIRO_FORMAT_A1, 1, 1);
	cr = cairo_create (surface);
	layout = pango_cairo_create_layout (cr);
	settings = _g_object_ref0 (gtk_settings_get_default ());
	desc = pango_font_description_from_string (font);
	pango_font_description_set_weight (desc, PANGO_WEIGHT_NORMAL);
	pango_layout_set_font_description (layout, desc);
	pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
	pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
	pango_layout_set_text (layout, text, -1);
	pango_context = _g_object_ref0 (pango_layout_get_context (layout));
	screen = _g_object_ref0 (gdk_screen_get_default ());
	pango_cairo_context_set_font_options (pango_context, gdk_screen_get_font_options (screen));
	pango_cairo_context_set_resolution (pango_context, (double) (((float) (g_object_get (settings, "gtk-xft-dpi", &_tmp0_, NULL), _tmp0_)) / ((float) PANGO_SCALE)));
	pango_layout_context_changed (layout);
	pango_layout_get_extents (layout, NULL, &log_rect);
	*width = log_rect.width / PANGO_SCALE;
	*height = log_rect.height / PANGO_SCALE;
	_cairo_surface_destroy0 (surface);
	_cairo_destroy0 (cr);
	_g_object_unref0 (layout);
	_g_object_unref0 (settings);
	_pango_font_description_free0 (desc);
	_g_object_unref0 (pango_context);
	_g_object_unref0 (screen);
}


void unity_quicklist_rendering_item_normal_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text) {
	PangoLayout* layout;
	GtkSettings* settings;
	PangoFontDescription* desc;
	PangoContext* pango_context;
	GdkScreen* screen;
	gint _tmp0_;
	gint text_width = 0;
	gint text_height = 0;
	g_return_if_fail (cr != NULL);
	g_return_if_fail (font != NULL);
	g_return_if_fail (text != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f);
	layout = pango_cairo_create_layout (cr);
	settings = _g_object_ref0 (gtk_settings_get_default ());
	desc = pango_font_description_from_string (font);
	pango_font_description_set_weight (desc, PANGO_WEIGHT_NORMAL);
	pango_layout_set_font_description (layout, desc);
	pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
	pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
	pango_layout_set_text (layout, text, -1);
	pango_context = _g_object_ref0 (pango_layout_get_context (layout));
	screen = _g_object_ref0 (gdk_screen_get_default ());
	pango_cairo_context_set_font_options (pango_context, gdk_screen_get_font_options (screen));
	pango_cairo_context_set_resolution (pango_context, (double) (((float) (g_object_get (settings, "gtk-xft-dpi", &_tmp0_, NULL), _tmp0_)) / ((float) PANGO_SCALE)));
	pango_layout_context_changed (layout);
	unity_quicklist_rendering_item_get_text_extents (font, text, &text_width, &text_height);
	cairo_move_to (cr, ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_MARGIN), (double) (((float) (h - text_height)) / 2.0f));
	pango_cairo_show_layout (cr, layout);
	_g_object_unref0 (layout);
	_g_object_unref0 (settings);
	_pango_font_description_free0 (desc);
	_g_object_unref0 (pango_context);
	_g_object_unref0 (screen);
}


void unity_quicklist_rendering_item_selected_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text) {
	PangoLayout* layout;
	GtkSettings* settings;
	PangoFontDescription* desc;
	PangoContext* pango_context;
	GdkScreen* screen;
	gint _tmp0_;
	gint text_width = 0;
	gint text_height = 0;
	g_return_if_fail (cr != NULL);
	g_return_if_fail (font != NULL);
	g_return_if_fail (text != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f);
	_unity_quicklist_rendering_item_round_rect (cr, (double) 1.0f, (double) 0.5f, (double) 0.5f, (double) UNITY_QUICKLIST_RENDERING_ITEM_CORNER_RADIUS_ABS, (double) (w - 1.0f), (double) (h - 1.0f));
	cairo_fill (cr);
	layout = pango_cairo_create_layout (cr);
	settings = _g_object_ref0 (gtk_settings_get_default ());
	desc = pango_font_description_from_string (font);
	pango_font_description_set_weight (desc, PANGO_WEIGHT_NORMAL);
	pango_layout_set_font_description (layout, desc);
	pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
	pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
	pango_layout_set_text (layout, text, -1);
	pango_context = _g_object_ref0 (pango_layout_get_context (layout));
	screen = _g_object_ref0 (gdk_screen_get_default ());
	pango_cairo_context_set_font_options (pango_context, gdk_screen_get_font_options (screen));
	pango_cairo_context_set_resolution (pango_context, (double) (((float) (g_object_get (settings, "gtk-xft-dpi", &_tmp0_, NULL), _tmp0_)) / ((float) PANGO_SCALE)));
	pango_layout_context_changed (layout);
	unity_quicklist_rendering_item_get_text_extents (font, text, &text_width, &text_height);
	cairo_move_to (cr, ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_MARGIN), (double) (((float) (h - text_height)) / 2.0f));
	cairo_set_source_rgba (cr, (double) 0.0f, (double) 0.0f, (double) 0.0f, (double) 0.0f);
	pango_cairo_show_layout (cr, layout);
	_g_object_unref0 (layout);
	_g_object_unref0 (settings);
	_pango_font_description_free0 (desc);
	_g_object_unref0 (pango_context);
	_g_object_unref0 (screen);
}


UnityQuicklistRenderingItem* unity_quicklist_rendering_item_construct (GType object_type) {
	UnityQuicklistRenderingItem * self;
	self = (UnityQuicklistRenderingItem*) g_object_new (object_type, NULL);
	return self;
}


UnityQuicklistRenderingItem* unity_quicklist_rendering_item_new (void) {
	return unity_quicklist_rendering_item_construct (UNITY_QUICKLIST_RENDERING_TYPE_ITEM);
}


static void unity_quicklist_rendering_item_class_init (UnityQuicklistRenderingItemClass * klass) {
	unity_quicklist_rendering_item_parent_class = g_type_class_peek_parent (klass);
}


static void unity_quicklist_rendering_item_instance_init (UnityQuicklistRenderingItem * self) {
}


GType unity_quicklist_rendering_item_get_type (void) {
	static volatile gsize unity_quicklist_rendering_item_type_id__volatile = 0;
	if (g_once_init_enter (&unity_quicklist_rendering_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityQuicklistRenderingItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_quicklist_rendering_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityQuicklistRenderingItem), 0, (GInstanceInitFunc) unity_quicklist_rendering_item_instance_init, NULL };
		GType unity_quicklist_rendering_item_type_id;
		unity_quicklist_rendering_item_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityQuicklistRenderingItem", &g_define_type_info, 0);
		g_once_init_leave (&unity_quicklist_rendering_item_type_id__volatile, unity_quicklist_rendering_item_type_id);
	}
	return unity_quicklist_rendering_item_type_id__volatile;
}


static double _unity_quicklist_rendering_menu_align (double val) {
	double result = 0.0;
	double fract;
	fract = val - ((gint) val);
	if (fract != 0.5f) {
		result = (double) (((gint) val) + 0.5f);
		return result;
	} else {
		result = val;
		return result;
	}
}


static void _unity_quicklist_rendering_menu_round_rect_anchor (cairo_t* cr, double aspect, double x, double y, double corner_radius, double width, double height, double anchor_width, double anchor_height, double anchor_x, double anchor_y) {
	double radius;
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	double g;
	double h;
	double* _tmp1_;
	gint _p0_size_;
	gint p0_length1;
	double* _tmp0_ = NULL;
	double* p0;
	double* _tmp3_;
	gint _p1_size_;
	gint p1_length1;
	double* _tmp2_ = NULL;
	double* p1;
	double* _tmp5_;
	gint _p2_size_;
	gint p2_length1;
	double* _tmp4_ = NULL;
	double* p2;
	double* _tmp7_;
	gint _p3_size_;
	gint p3_length1;
	double* _tmp6_ = NULL;
	double* p3;
	double* _tmp9_;
	gint _p4_size_;
	gint p4_length1;
	double* _tmp8_ = NULL;
	double* p4;
	double* _tmp11_;
	gint _p5_size_;
	gint p5_length1;
	double* _tmp10_ = NULL;
	double* p5;
	double* _tmp13_;
	gint _p6_size_;
	gint p6_length1;
	double* _tmp12_ = NULL;
	double* p6;
	double* _tmp15_;
	gint _p7_size_;
	gint p7_length1;
	double* _tmp14_ = NULL;
	double* p7;
	double* _tmp17_;
	gint _p8_size_;
	gint p8_length1;
	double* _tmp16_ = NULL;
	double* p8;
	double* _tmp19_;
	gint _p9_size_;
	gint p9_length1;
	double* _tmp18_ = NULL;
	double* p9;
	double* _tmp21_;
	gint _p10_size_;
	gint p10_length1;
	double* _tmp20_ = NULL;
	double* p10;
	double* _tmp23_;
	gint _q0_size_;
	gint q0_length1;
	double* _tmp22_ = NULL;
	double* q0;
	double* _tmp25_;
	gint _q1_size_;
	gint q1_length1;
	double* _tmp24_ = NULL;
	double* q1;
	double* _tmp27_;
	gint _q2_size_;
	gint q2_length1;
	double* _tmp26_ = NULL;
	double* q2;
	double* _tmp29_;
	gint _q3_size_;
	gint q3_length1;
	double* _tmp28_ = NULL;
	double* q3;
	g_return_if_fail (cr != NULL);
	radius = corner_radius / aspect;
	a = _unity_quicklist_rendering_menu_align (x);
	b = _unity_quicklist_rendering_menu_align (x + radius);
	c = _unity_quicklist_rendering_menu_align (x + width);
	d = _unity_quicklist_rendering_menu_align ((x + width) - radius);
	e = _unity_quicklist_rendering_menu_align (y);
	f = _unity_quicklist_rendering_menu_align (y + radius);
	g = _unity_quicklist_rendering_menu_align (y + height);
	h = _unity_quicklist_rendering_menu_align ((y + height) - radius);
	p0 = (_tmp1_ = (_tmp0_ = g_new0 (double, 2), _tmp0_[0] = b, _tmp0_[1] = e, _tmp0_), p0_length1 = 2, _p0_size_ = p0_length1, _tmp1_);
	p1 = (_tmp3_ = (_tmp2_ = g_new0 (double, 2), _tmp2_[0] = d, _tmp2_[1] = e, _tmp2_), p1_length1 = 2, _p1_size_ = p1_length1, _tmp3_);
	p2 = (_tmp5_ = (_tmp4_ = g_new0 (double, 2), _tmp4_[0] = c, _tmp4_[1] = f, _tmp4_), p2_length1 = 2, _p2_size_ = p2_length1, _tmp5_);
	p3 = (_tmp7_ = (_tmp6_ = g_new0 (double, 2), _tmp6_[0] = c, _tmp6_[1] = h, _tmp6_), p3_length1 = 2, _p3_size_ = p3_length1, _tmp7_);
	p4 = (_tmp9_ = (_tmp8_ = g_new0 (double, 2), _tmp8_[0] = d, _tmp8_[1] = g, _tmp8_), p4_length1 = 2, _p4_size_ = p4_length1, _tmp9_);
	p5 = (_tmp11_ = (_tmp10_ = g_new0 (double, 2), _tmp10_[0] = b, _tmp10_[1] = g, _tmp10_), p5_length1 = 2, _p5_size_ = p5_length1, _tmp11_);
	p6 = (_tmp13_ = (_tmp12_ = g_new0 (double, 2), _tmp12_[0] = a, _tmp12_[1] = h, _tmp12_), p6_length1 = 2, _p6_size_ = p6_length1, _tmp13_);
	p7 = (_tmp15_ = (_tmp14_ = g_new0 (double, 2), _tmp14_[0] = _unity_quicklist_rendering_menu_align (anchor_x + anchor_width), _tmp14_[1] = _unity_quicklist_rendering_menu_align (anchor_y + (anchor_height / 2.0f)), _tmp14_), p7_length1 = 2, _p7_size_ = p7_length1, _tmp15_);
	p8 = (_tmp17_ = (_tmp16_ = g_new0 (double, 2), _tmp16_[0] = _unity_quicklist_rendering_menu_align (anchor_x), _tmp16_[1] = _unity_quicklist_rendering_menu_align (anchor_y), _tmp16_), p8_length1 = 2, _p8_size_ = p8_length1, _tmp17_);
	p9 = (_tmp19_ = (_tmp18_ = g_new0 (double, 2), _tmp18_[0] = _unity_quicklist_rendering_menu_align (anchor_x + anchor_width), _tmp18_[1] = _unity_quicklist_rendering_menu_align (anchor_y - (anchor_height / 2.0f)), _tmp18_), p9_length1 = 2, _p9_size_ = p9_length1, _tmp19_);
	p10 = (_tmp21_ = (_tmp20_ = g_new0 (double, 2), _tmp20_[0] = a, _tmp20_[1] = f, _tmp20_), p10_length1 = 2, _p10_size_ = p10_length1, _tmp21_);
	q0 = (_tmp23_ = (_tmp22_ = g_new0 (double, 2), _tmp22_[0] = a, _tmp22_[1] = e, _tmp22_), q0_length1 = 2, _q0_size_ = q0_length1, _tmp23_);
	q1 = (_tmp25_ = (_tmp24_ = g_new0 (double, 2), _tmp24_[0] = c, _tmp24_[1] = e, _tmp24_), q1_length1 = 2, _q1_size_ = q1_length1, _tmp25_);
	q2 = (_tmp27_ = (_tmp26_ = g_new0 (double, 2), _tmp26_[0] = c, _tmp26_[1] = g, _tmp26_), q2_length1 = 2, _q2_size_ = q2_length1, _tmp27_);
	q3 = (_tmp29_ = (_tmp28_ = g_new0 (double, 2), _tmp28_[0] = a, _tmp28_[1] = g, _tmp28_), q3_length1 = 2, _q3_size_ = q3_length1, _tmp29_);
	cairo_move_to (cr, p0[0], p0[1]);
	cairo_line_to (cr, p1[0], p1[1]);
	cairo_curve_to (cr, q1[0] - (radius * 0.45f), q1[1], q1[0], q1[1] + (radius * 0.45f), p2[0], p2[1]);
	cairo_line_to (cr, p3[0], p3[1]);
	cairo_curve_to (cr, q2[0], q2[1] - (radius * 0.45f), q2[0] - (radius * 0.45f), q2[1], p4[0], p4[1]);
	cairo_line_to (cr, p5[0], p5[1]);
	cairo_curve_to (cr, q3[0] + (radius * 0.45f), q3[1], q3[0], q3[1] - (radius * 0.45f), p6[0], p6[1]);
	cairo_line_to (cr, p7[0], p7[1]);
	cairo_line_to (cr, p8[0], p8[1]);
	cairo_line_to (cr, p9[0], p9[1]);
	cairo_line_to (cr, p10[0], p10[1]);
	cairo_curve_to (cr, q0[0], q0[1] + (radius * 0.45f), q0[0] + (radius * 0.45f), q0[1], p0[0], p0[1]);
	p0 = (g_free (p0), NULL);
	p1 = (g_free (p1), NULL);
	p2 = (g_free (p2), NULL);
	p3 = (g_free (p3), NULL);
	p4 = (g_free (p4), NULL);
	p5 = (g_free (p5), NULL);
	p6 = (g_free (p6), NULL);
	p7 = (g_free (p7), NULL);
	p8 = (g_free (p8), NULL);
	p9 = (g_free (p9), NULL);
	p10 = (g_free (p10), NULL);
	q0 = (g_free (q0), NULL);
	q1 = (g_free (q1), NULL);
	q2 = (g_free (q2), NULL);
	q3 = (g_free (q3), NULL);
}


static void _unity_quicklist_rendering_menu_draw_mask (cairo_t* cr, gint w, gint h, float anchor_y) {
	g_return_if_fail (cr != NULL);
	_unity_quicklist_rendering_menu_round_rect_anchor (cr, (double) 1.0f, UNITY_QUICKLIST_RENDERING_ANCHOR_WIDTH_ABS + ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_SHADOW_SIZE), ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_SHADOW_SIZE), (double) UNITY_QUICKLIST_RENDERING_CORNER_RADIUS_ABS, ((double) w) - (UNITY_QUICKLIST_RENDERING_ANCHOR_WIDTH_ABS + ctk_em_to_pixel ((double) (2 * UNITY_QUICKLIST_RENDERING_SHADOW_SIZE))), ((double) h) - ctk_em_to_pixel ((double) (2 * UNITY_QUICKLIST_RENDERING_SHADOW_SIZE)), (double) UNITY_QUICKLIST_RENDERING_ANCHOR_WIDTH_ABS, (double) UNITY_QUICKLIST_RENDERING_ANCHOR_HEIGHT_ABS, ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_SHADOW_SIZE), (double) anchor_y);
}


void unity_quicklist_rendering_menu_full_mask (cairo_t* cr, gint w, gint h, float anchor_y) {
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f);
	cairo_paint (cr);
}


void unity_quicklist_rendering_menu_fill_mask (cairo_t* cr, gint w, gint h, float anchor_y) {
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
}


void unity_quicklist_rendering_menu_background (cairo_t* cr, gint w, gint h, float anchor_y) {
	cairo_surface_t* dots;
	cairo_t* cr_dots;
	cairo_pattern_t* dot_pattern;
	cairo_pattern_t* hl_pattern;
	cairo_pattern_t* _tmp0_;
	cairo_pattern_t* _tmp1_;
	g_return_if_fail (cr != NULL);
	dots = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 4, 4);
	cr_dots = cairo_create (dots);
	dot_pattern = NULL;
	hl_pattern = NULL;
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 0.0f, (double) 0.0f, (double) 0.0f, (double) 0.48f);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
	ctk_surface_blur (cairo_get_target (cr), (guint) ((gint) ctk_em_to_pixel ((double) (UNITY_QUICKLIST_RENDERING_SHADOW_SIZE / 2))));
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_scale (cr, (double) 1.0f, (double) 1.0f);
	cairo_set_source_rgba (cr, (double) 0.0f, (double) 0.0f, (double) 0.0f, (double) 0.7f);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
	cairo_set_operator (cr_dots, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr_dots);
	cairo_scale (cr_dots, (double) 1.0f, (double) 1.0f);
	cairo_set_operator (cr_dots, CAIRO_OPERATOR_OVER);
	cairo_set_source_rgba (cr_dots, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.15f);
	cairo_rectangle (cr_dots, (double) 0.0f, (double) 0.0f, (double) 1.0f, (double) 1.0f);
	cairo_fill (cr_dots);
	cairo_rectangle (cr_dots, (double) 2.0f, (double) 2.0f, (double) 1.0f, (double) 1.0f);
	cairo_fill (cr_dots);
	dot_pattern = (_tmp0_ = cairo_pattern_create_for_surface (dots), _cairo_pattern_destroy0 (dot_pattern), _tmp0_);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_source (cr, dot_pattern);
	cairo_pattern_set_extend (dot_pattern, CAIRO_EXTEND_REPEAT);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	hl_pattern = (_tmp1_ = cairo_pattern_create_radial (((double) w) / 2.0f, ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_BORDER) - 15.0f, (double) 0.0f, ((double) w) / 2.0f, ctk_em_to_pixel ((double) UNITY_QUICKLIST_RENDERING_BORDER) - 15.0f, (((double) w) / 2.0f) + 20.0f), _cairo_pattern_destroy0 (hl_pattern), _tmp1_);
	cairo_pattern_add_color_stop_rgba (hl_pattern, (double) 0.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.65f);
	cairo_pattern_add_color_stop_rgba (hl_pattern, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.0f);
	cairo_set_source (cr, hl_pattern);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_fill (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_set_line_width (cr, (double) UNITY_QUICKLIST_RENDERING_LINE_WIDTH_ABS);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.75f);
	_unity_quicklist_rendering_menu_draw_mask (cr, w, h, anchor_y);
	cairo_stroke (cr);
	_cairo_surface_destroy0 (dots);
	_cairo_destroy0 (cr_dots);
	_cairo_pattern_destroy0 (dot_pattern);
	_cairo_pattern_destroy0 (hl_pattern);
}


UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_construct (GType object_type) {
	UnityQuicklistRenderingMenu * self;
	self = (UnityQuicklistRenderingMenu*) g_object_new (object_type, NULL);
	return self;
}


UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_new (void) {
	return unity_quicklist_rendering_menu_construct (UNITY_QUICKLIST_RENDERING_TYPE_MENU);
}


static void unity_quicklist_rendering_menu_class_init (UnityQuicklistRenderingMenuClass * klass) {
	unity_quicklist_rendering_menu_parent_class = g_type_class_peek_parent (klass);
}


static void unity_quicklist_rendering_menu_instance_init (UnityQuicklistRenderingMenu * self) {
}


GType unity_quicklist_rendering_menu_get_type (void) {
	static volatile gsize unity_quicklist_rendering_menu_type_id__volatile = 0;
	if (g_once_init_enter (&unity_quicklist_rendering_menu_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityQuicklistRenderingMenuClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_quicklist_rendering_menu_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityQuicklistRenderingMenu), 0, (GInstanceInitFunc) unity_quicklist_rendering_menu_instance_init, NULL };
		GType unity_quicklist_rendering_menu_type_id;
		unity_quicklist_rendering_menu_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityQuicklistRenderingMenu", &g_define_type_info, 0);
		g_once_init_leave (&unity_quicklist_rendering_menu_type_id__volatile, unity_quicklist_rendering_menu_type_id);
	}
	return unity_quicklist_rendering_menu_type_id__volatile;
}




