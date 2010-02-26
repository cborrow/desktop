/* bar-view.c generated by valac, the Vala compiler
 * generated from bar-view.vala, do not modify */

/*
 * Copyright (C) 2009 Canonical Ltd
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
 * Authored by Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *             Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <gee.h>
#include <clutter/clutter.h>


#define UNITY_PLACES_BAR_TYPE_VIEW (unity_places_bar_view_get_type ())
#define UNITY_PLACES_BAR_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarView))
#define UNITY_PLACES_BAR_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarViewClass))
#define UNITY_PLACES_BAR_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_BAR_TYPE_VIEW))
#define UNITY_PLACES_BAR_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_BAR_TYPE_VIEW))
#define UNITY_PLACES_BAR_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarViewClass))

typedef struct _UnityPlacesBarView UnityPlacesBarView;
typedef struct _UnityPlacesBarViewClass UnityPlacesBarViewClass;
typedef struct _UnityPlacesBarViewPrivate UnityPlacesBarViewPrivate;

#define UNITY_PLACES_TYPE_MODEL (unity_places_model_get_type ())
#define UNITY_PLACES_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModel))
#define UNITY_PLACES_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))
#define UNITY_PLACES_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_IS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))

typedef struct _UnityPlacesModel UnityPlacesModel;
typedef struct _UnityPlacesModelClass UnityPlacesModelClass;

#define UNITY_PLACES_BAR_TYPE_PLACE_ICON (unity_places_bar_place_icon_get_type ())
#define UNITY_PLACES_BAR_PLACE_ICON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_BAR_TYPE_PLACE_ICON, UnityPlacesBarPlaceIcon))
#define UNITY_PLACES_BAR_PLACE_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_BAR_TYPE_PLACE_ICON, UnityPlacesBarPlaceIconClass))
#define UNITY_PLACES_BAR_IS_PLACE_ICON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_BAR_TYPE_PLACE_ICON))
#define UNITY_PLACES_BAR_IS_PLACE_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_BAR_TYPE_PLACE_ICON))
#define UNITY_PLACES_BAR_PLACE_ICON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_BAR_TYPE_PLACE_ICON, UnityPlacesBarPlaceIconClass))

typedef struct _UnityPlacesBarPlaceIcon UnityPlacesBarPlaceIcon;
typedef struct _UnityPlacesBarPlaceIconClass UnityPlacesBarPlaceIconClass;

#define UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR (unity_places_cairo_drawing_places_vseparator_get_type ())
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_VSEPARATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR, UnityPlacesCairoDrawingPlacesVSeparator))
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_VSEPARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR, UnityPlacesCairoDrawingPlacesVSeparatorClass))
#define UNITY_PLACES_CAIRO_DRAWING_IS_PLACES_VSEPARATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR))
#define UNITY_PLACES_CAIRO_DRAWING_IS_PLACES_VSEPARATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR))
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_VSEPARATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_VSEPARATOR, UnityPlacesCairoDrawingPlacesVSeparatorClass))

typedef struct _UnityPlacesCairoDrawingPlacesVSeparator UnityPlacesCairoDrawingPlacesVSeparator;
typedef struct _UnityPlacesCairoDrawingPlacesVSeparatorClass UnityPlacesCairoDrawingPlacesVSeparatorClass;

#define UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND (unity_places_cairo_drawing_places_background_get_type ())
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND, UnityPlacesCairoDrawingPlacesBackground))
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND, UnityPlacesCairoDrawingPlacesBackgroundClass))
#define UNITY_PLACES_CAIRO_DRAWING_IS_PLACES_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND))
#define UNITY_PLACES_CAIRO_DRAWING_IS_PLACES_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND))
#define UNITY_PLACES_CAIRO_DRAWING_PLACES_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_PLACES_BACKGROUND, UnityPlacesCairoDrawingPlacesBackgroundClass))

typedef struct _UnityPlacesCairoDrawingPlacesBackground UnityPlacesCairoDrawingPlacesBackground;
typedef struct _UnityPlacesCairoDrawingPlacesBackgroundClass UnityPlacesCairoDrawingPlacesBackgroundClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityPlacesBarPlaceIconPrivate UnityPlacesBarPlaceIconPrivate;

struct _UnityPlacesBarView {
	CtkBox parent_instance;
	UnityPlacesBarViewPrivate * priv;
};

struct _UnityPlacesBarViewClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesBarViewPrivate {
	UnityPlacesModel* _model;
	UnityShell* _shell;
	GeeArrayList* places_icons;
	UnityPlacesBarPlaceIcon* trash_icon;
	UnityPlacesCairoDrawingPlacesVSeparator* separator;
	UnityPlacesCairoDrawingPlacesBackground* bg;
};

struct _UnityPlacesBarPlaceIcon {
	CtkImage parent_instance;
	UnityPlacesBarPlaceIconPrivate * priv;
};

struct _UnityPlacesBarPlaceIconClass {
	CtkImageClass parent_class;
};

struct _UnityPlacesBarPlaceIconPrivate {
	UnityPlacesPlace* _place;
};


static gpointer unity_places_bar_view_parent_class = NULL;
static gpointer unity_places_bar_place_icon_parent_class = NULL;

#define UNITY_PLACES_BAR_PANEL_HEIGHT ((float) 24)
#define UNITY_PLACES_BAR_ICON_SIZE 48
#define UNITY_PLACES_BAR_ICON_VIEW_WIDTH 80.0f
#define UNITY_PLACES_BAR_ICON_VIEW_Y1 8.0f
#define UNITY_PLACES_BAR_QL_PAD 12.0f
#define UNITY_PLACES_BAR_TRASH_FILE PKGDATADIR "/trash.png"
GType unity_places_bar_view_get_type (void);
GType unity_places_model_get_type (void);
GType unity_places_bar_place_icon_get_type (void);
GType unity_places_cairo_drawing_places_vseparator_get_type (void);
GType unity_places_cairo_drawing_places_background_get_type (void);
#define UNITY_PLACES_BAR_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarViewPrivate))
enum  {
	UNITY_PLACES_BAR_VIEW_DUMMY_PROPERTY,
	UNITY_PLACES_BAR_VIEW_MODEL,
	UNITY_PLACES_BAR_VIEW_SHELL
};
UnityPlacesCairoDrawingPlacesBackground* unity_places_cairo_drawing_places_background_new (void);
UnityPlacesCairoDrawingPlacesBackground* unity_places_cairo_drawing_places_background_construct (GType object_type);
UnityShell* unity_places_bar_view_get_shell (UnityPlacesBarView* self);
static void unity_places_bar_view_on_indicators_changed (UnityPlacesBarView* self, gint width);
static void _unity_places_bar_view_on_indicators_changed_unity_shell_indicators_changed (UnityShell* _sender, gint width, gpointer self);
UnityPlacesModel* unity_places_bar_view_get_model (UnityPlacesBarView* self);
GType unity_places_place_get_type (void);
static void unity_places_bar_view_on_place_added (UnityPlacesBarView* self, UnityPlacesPlace* place);
static void _unity_places_bar_view_on_place_added_unity_places_model_place_added (UnityPlacesModel* _sender, UnityPlacesPlace* place, gpointer self);
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_new (gint width, const char* name, const char* icon_name, const char* tooltip);
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_construct (GType object_type, gint width, const char* name, const char* icon_name, const char* tooltip);
gboolean unity_places_bar_view_on_button_release (UnityPlacesBarView* self, ClutterEvent* event);
static gboolean _unity_places_bar_view_on_button_release_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
UnityPlacesCairoDrawingPlacesVSeparator* unity_places_cairo_drawing_places_vseparator_new (void);
UnityPlacesCairoDrawingPlacesVSeparator* unity_places_cairo_drawing_places_vseparator_construct (GType object_type);
UnityPlacesBarView* unity_places_bar_view_new (UnityPlacesModel* model, UnityShell* shell);
UnityPlacesBarView* unity_places_bar_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell);
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_new_from_place (gint size, UnityPlacesPlace* place);
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_construct_from_place (GType object_type, gint size, UnityPlacesPlace* place);
void unity_places_cairo_drawing_places_background_create_places_background (UnityPlacesCairoDrawingPlacesBackground* self, gint WindowWidth, gint WindowHeight, gint TabPositionX, gint TabWidth, gint menu_width);
void unity_places_place_set_active (UnityPlacesPlace* self, gboolean value);
UnityPlacesPlace* unity_places_bar_place_icon_get_place (UnityPlacesBarPlaceIcon* self);
static void unity_places_bar_view_real_map (ClutterActor* base);
static void unity_places_bar_view_real_unmap (ClutterActor* base);
static void unity_places_bar_view_real_paint (ClutterActor* base);
static void unity_places_bar_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_places_bar_view_set_model (UnityPlacesBarView* self, UnityPlacesModel* value);
static void unity_places_bar_view_set_shell (UnityPlacesBarView* self, UnityShell* value);
static void unity_places_bar_view_finalize (GObject* obj);
static void unity_places_bar_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_bar_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
#define UNITY_PLACES_BAR_PLACE_ICON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_BAR_TYPE_PLACE_ICON, UnityPlacesBarPlaceIconPrivate))
enum  {
	UNITY_PLACES_BAR_PLACE_ICON_DUMMY_PROPERTY,
	UNITY_PLACES_BAR_PLACE_ICON_PLACE
};
const char* unity_places_place_get_name (UnityPlacesPlace* self);
const char* unity_places_place_get_icon_name (UnityPlacesPlace* self);
void unity_places_bar_place_icon_set_place (UnityPlacesBarPlaceIcon* self, UnityPlacesPlace* value);
static void unity_places_bar_place_icon_finalize (GObject* obj);
static void unity_places_bar_place_icon_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_bar_place_icon_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 114 "bar-view.vala"
static void _unity_places_bar_view_on_indicators_changed_unity_shell_indicators_changed (UnityShell* _sender, gint width, gpointer self) {
#line 200 "bar-view.c"
	unity_places_bar_view_on_indicators_changed (self, width);
}


#line 85 "bar-view.vala"
static void _unity_places_bar_view_on_place_added_unity_places_model_place_added (UnityPlacesModel* _sender, UnityPlacesPlace* place, gpointer self) {
#line 207 "bar-view.c"
	unity_places_bar_view_on_place_added (self, place);
}


#line 185 "bar-view.vala"
static gboolean _unity_places_bar_view_on_button_release_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
#line 214 "bar-view.c"
	return unity_places_bar_view_on_button_release (self, event);
}


#line 42 "bar-view.vala"
UnityPlacesBarView* unity_places_bar_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell) {
#line 221 "bar-view.c"
	UnityPlacesBarView * self;
	CtkEffectGlow* glow;
	ClutterColor _tmp0_ = {0};
	ClutterColor white;
	UnityPlacesCairoDrawingPlacesBackground* _tmp1_;
	GeeArrayList* _tmp2_;
	UnityPlacesBarPlaceIcon* _tmp3_;
	CtkEffectGlow* _tmp4_;
	UnityPlacesCairoDrawingPlacesVSeparator* _tmp5_;
#line 42 "bar-view.vala"
	g_return_val_if_fail (model != NULL, NULL);
#line 42 "bar-view.vala"
	g_return_val_if_fail (shell != NULL, NULL);
#line 235 "bar-view.c"
	glow = NULL;
#line 45 "bar-view.vala"
	white = (_tmp0_.red = (guint8) 255, _tmp0_.green = (guint8) 255, _tmp0_.blue = (guint8) 255, _tmp0_.alpha = (guint8) 255, _tmp0_);
#line 47 "bar-view.vala"
	self = (UnityPlacesBarView*) g_object_new (object_type, "model", model, "shell", shell, NULL);
#line 50 "bar-view.vala"
	ctk_box_set_homogeneous ((CtkBox*) self, FALSE);
#line 51 "bar-view.vala"
	ctk_box_set_orientation ((CtkBox*) self, (gint) CTK_ORIENTATION_HORIZONTAL);
#line 54 "bar-view.vala"
	self->priv->bg = (_tmp1_ = g_object_ref_sink (unity_places_cairo_drawing_places_background_new ()), _g_object_unref0 (self->priv->bg), _tmp1_);
#line 55 "bar-view.vala"
	clutter_actor_set_parent ((ClutterActor*) self->priv->bg, (ClutterActor*) self);
#line 56 "bar-view.vala"
	clutter_actor_show ((ClutterActor*) self->priv->bg);
#line 58 "bar-view.vala"
	g_signal_connect_object (self->priv->_shell, "indicators-changed", (GCallback) _unity_places_bar_view_on_indicators_changed_unity_shell_indicators_changed, self, 0);
#line 61 "bar-view.vala"
	self->priv->places_icons = (_tmp2_ = gee_array_list_new (UNITY_PLACES_BAR_TYPE_PLACE_ICON, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->places_icons), _tmp2_);
#line 62 "bar-view.vala"
	g_signal_connect_object (self->priv->_model, "place-added", (GCallback) _unity_places_bar_view_on_place_added_unity_places_model_place_added, self, 0);
#line 65 "bar-view.vala"
	self->priv->trash_icon = (_tmp3_ = g_object_ref_sink (unity_places_bar_place_icon_new (UNITY_PLACES_BAR_ICON_SIZE, "Trash", UNITY_PLACES_BAR_TRASH_FILE, "Your piece of waste")), _g_object_unref0 (self->priv->trash_icon), _tmp3_);
#line 69 "bar-view.vala"
	glow = (_tmp4_ = g_object_ref_sink ((CtkEffectGlow*) ctk_effect_glow_new ()), _g_object_unref0 (glow), _tmp4_);
#line 70 "bar-view.vala"
	ctk_effect_glow_set_color (glow, &white);
#line 71 "bar-view.vala"
	ctk_effect_glow_set_factor (glow, 1.0f);
#line 72 "bar-view.vala"
	ctk_effect_set_margin ((CtkEffect*) glow, 6);
#line 73 "bar-view.vala"
	ctk_actor_add_effect ((CtkActor*) self->priv->trash_icon, (CtkEffect*) glow);
#line 75 "bar-view.vala"
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->trash_icon, FALSE, FALSE);
#line 76 "bar-view.vala"
	g_signal_connect_object ((ClutterActor*) self->priv->trash_icon, "button-release-event", (GCallback) _unity_places_bar_view_on_button_release_clutter_actor_button_release_event, self, 0);
#line 79 "bar-view.vala"
	self->priv->separator = (_tmp5_ = g_object_ref_sink (unity_places_cairo_drawing_places_vseparator_new ()), _g_object_unref0 (self->priv->separator), _tmp5_);
#line 80 "bar-view.vala"
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->separator, FALSE, FALSE);
#line 82 "bar-view.vala"
	clutter_actor_show_all ((ClutterActor*) self);
#line 279 "bar-view.c"
	_g_object_unref0 (glow);
	return self;
}


#line 42 "bar-view.vala"
UnityPlacesBarView* unity_places_bar_view_new (UnityPlacesModel* model, UnityShell* shell) {
#line 42 "bar-view.vala"
	return unity_places_bar_view_construct (UNITY_PLACES_BAR_TYPE_VIEW, model, shell);
#line 289 "bar-view.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 85 "bar-view.vala"
static void unity_places_bar_view_on_place_added (UnityPlacesBarView* self, UnityPlacesPlace* place) {
#line 300 "bar-view.c"
	ClutterColor _tmp0_ = {0};
	ClutterColor white;
	UnityPlacesBarPlaceIcon* icon;
	CtkEffectGlow* glow;
#line 85 "bar-view.vala"
	g_return_if_fail (self != NULL);
#line 85 "bar-view.vala"
	g_return_if_fail (place != NULL);
#line 87 "bar-view.vala"
	white = (_tmp0_.red = (guint8) 255, _tmp0_.green = (guint8) 255, _tmp0_.blue = (guint8) 255, _tmp0_.alpha = (guint8) 255, _tmp0_);
#line 89 "bar-view.vala"
	icon = g_object_ref_sink (unity_places_bar_place_icon_new_from_place (UNITY_PLACES_BAR_ICON_SIZE, place));
#line 90 "bar-view.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->places_icons, icon);
#line 92 "bar-view.vala"
	glow = g_object_ref_sink ((CtkEffectGlow*) ctk_effect_glow_new ());
#line 93 "bar-view.vala"
	ctk_effect_glow_set_color (glow, &white);
#line 94 "bar-view.vala"
	ctk_effect_glow_set_factor (glow, 1.0f);
#line 95 "bar-view.vala"
	ctk_effect_set_margin ((CtkEffect*) glow, 6);
#line 96 "bar-view.vala"
	ctk_actor_add_effect ((CtkActor*) icon, (CtkEffect*) glow);
#line 98 "bar-view.vala"
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) icon, FALSE, FALSE);
#line 99 "bar-view.vala"
	g_signal_connect_object ((ClutterActor*) icon, "button-release-event", (GCallback) _unity_places_bar_view_on_button_release_clutter_actor_button_release_event, self, 0);
#line 101 "bar-view.vala"
	if (gee_collection_get_size ((GeeCollection*) self->priv->places_icons) == 1) {
#line 331 "bar-view.c"
		ClutterActor* stage;
		CtkPadding _tmp1_ = {0};
#line 103 "bar-view.vala"
		stage = _g_object_ref0 (clutter_actor_get_stage ((ClutterActor*) icon));
#line 104 "bar-view.vala"
		unity_places_cairo_drawing_places_background_create_places_background (self->priv->bg, (gint) clutter_actor_get_width (stage), (gint) clutter_actor_get_height (stage), (gint) ((ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_).left + UNITY_PLACES_BAR_QL_PAD), (gint) UNITY_PLACES_BAR_ICON_VIEW_WIDTH, unity_shell_get_indicators_width (self->priv->_shell));
#line 110 "bar-view.vala"
		unity_places_place_set_active (unity_places_bar_place_icon_get_place (icon), TRUE);
#line 340 "bar-view.c"
		_g_object_unref0 (stage);
	}
	_g_object_unref0 (icon);
	_g_object_unref0 (glow);
}


#line 114 "bar-view.vala"
static void unity_places_bar_view_on_indicators_changed (UnityPlacesBarView* self, gint width) {
#line 350 "bar-view.c"
	ClutterActor* stage;
	CtkPadding _tmp0_ = {0};
#line 114 "bar-view.vala"
	g_return_if_fail (self != NULL);
#line 116 "bar-view.vala"
	stage = _g_object_ref0 (clutter_actor_get_stage ((ClutterActor*) self));
#line 117 "bar-view.vala"
	unity_places_cairo_drawing_places_background_create_places_background (self->priv->bg, (gint) clutter_actor_get_width (stage), (gint) clutter_actor_get_height (stage), (gint) ((ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_).left + UNITY_PLACES_BAR_QL_PAD), (gint) UNITY_PLACES_BAR_ICON_VIEW_WIDTH, width);
#line 122 "bar-view.vala"
	clutter_actor_queue_relayout ((ClutterActor*) self);
#line 361 "bar-view.c"
	_g_object_unref0 (stage);
}


#line 125 "bar-view.vala"
static void unity_places_bar_view_real_map (ClutterActor* base) {
#line 368 "bar-view.c"
	UnityPlacesBarView * self;
	self = (UnityPlacesBarView*) base;
#line 127 "bar-view.vala"
	CLUTTER_ACTOR_CLASS (unity_places_bar_view_parent_class)->map ((ClutterActor*) CTK_BOX (self));
#line 128 "bar-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->bg);
#line 375 "bar-view.c"
}


#line 131 "bar-view.vala"
static void unity_places_bar_view_real_unmap (ClutterActor* base) {
#line 381 "bar-view.c"
	UnityPlacesBarView * self;
	self = (UnityPlacesBarView*) base;
#line 133 "bar-view.vala"
	CLUTTER_ACTOR_CLASS (unity_places_bar_view_parent_class)->unmap ((ClutterActor*) CTK_BOX (self));
#line 134 "bar-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->bg);
#line 388 "bar-view.c"
}


#line 137 "bar-view.vala"
static void unity_places_bar_view_real_paint (ClutterActor* base) {
#line 394 "bar-view.c"
	UnityPlacesBarView * self;
	self = (UnityPlacesBarView*) base;
#line 139 "bar-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->bg);
#line 140 "bar-view.vala"
	CLUTTER_ACTOR_CLASS (unity_places_bar_view_parent_class)->paint ((ClutterActor*) CTK_BOX (self));
#line 401 "bar-view.c"
}


#line 143 "bar-view.vala"
static void unity_places_bar_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
#line 407 "bar-view.c"
	UnityPlacesBarView * self;
	ClutterActorBox _tmp0_ = {0};
	ClutterActorBox child_box;
	gint n_places;
	CtkPadding _tmp1_ = {0};
	float lpadding;
	gint i_width;
	self = (UnityPlacesBarView*) base;
#line 146 "bar-view.vala"
	child_box = (_tmp0_.x1 = (float) 0, _tmp0_.y1 = (float) 0, _tmp0_.x2 = (float) 0, _tmp0_.y2 = (float) 0, _tmp0_);
#line 147 "bar-view.vala"
	child_box.x1 = 0.0f;
#line 148 "bar-view.vala"
	child_box.x2 = (*box).x2 - (*box).x1;
#line 149 "bar-view.vala"
	child_box.y1 = 0.0f;
#line 150 "bar-view.vala"
	child_box.y2 = (*box).y2 - (*box).y1;
#line 152 "bar-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->bg, &child_box, flags);
#line 155 "bar-view.vala"
	n_places = 0;
#line 156 "bar-view.vala"
	lpadding = (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_).left + UNITY_PLACES_BAR_QL_PAD;
#line 158 "bar-view.vala"
	child_box.y1 = UNITY_PLACES_BAR_ICON_VIEW_Y1;
#line 159 "bar-view.vala"
	child_box.y2 = child_box.y1 + UNITY_PLACES_BAR_ICON_SIZE;
#line 436 "bar-view.c"
	{
		GeeIterator* _place_it;
		_place_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->places_icons);
#line 161 "bar-view.vala"
		while (TRUE) {
#line 442 "bar-view.c"
			UnityPlacesBarPlaceIcon* place;
#line 161 "bar-view.vala"
			if (!gee_iterator_next (_place_it)) {
#line 161 "bar-view.vala"
				break;
#line 448 "bar-view.c"
			}
#line 161 "bar-view.vala"
			place = (UnityPlacesBarPlaceIcon*) gee_iterator_get (_place_it);
#line 163 "bar-view.vala"
			child_box.x1 = lpadding + (UNITY_PLACES_BAR_ICON_VIEW_WIDTH * n_places);
#line 164 "bar-view.vala"
			child_box.x2 = child_box.x1 + UNITY_PLACES_BAR_ICON_VIEW_WIDTH;
#line 166 "bar-view.vala"
			clutter_actor_allocate ((ClutterActor*) place, &child_box, flags);
#line 168 "bar-view.vala"
			n_places++;
#line 460 "bar-view.c"
			_g_object_unref0 (place);
		}
		_g_object_unref0 (_place_it);
	}
#line 172 "bar-view.vala"
	i_width = unity_shell_get_indicators_width (self->priv->_shell) + 8;
#line 173 "bar-view.vala"
	child_box.x1 = (((*box).x2 - (*box).x1) - i_width) - UNITY_PLACES_BAR_ICON_VIEW_WIDTH;
#line 174 "bar-view.vala"
	child_box.x2 = child_box.x1 + UNITY_PLACES_BAR_ICON_VIEW_WIDTH;
#line 175 "bar-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->trash_icon, &child_box, flags);
#line 178 "bar-view.vala"
	child_box.x1 = child_box.x1 - 12.0f;
#line 179 "bar-view.vala"
	child_box.x2 = child_box.x1 + 5;
#line 180 "bar-view.vala"
	child_box.y1 = (float) 10;
#line 181 "bar-view.vala"
	child_box.y2 = (float) UNITY_PLACES_BAR_ICON_SIZE;
#line 182 "bar-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->separator, &child_box, flags);
#line 483 "bar-view.c"
}


#line 185 "bar-view.vala"
gboolean unity_places_bar_view_on_button_release (UnityPlacesBarView* self, ClutterEvent* event) {
#line 489 "bar-view.c"
	gboolean result;
	GError * _inner_error_;
	ClutterActor* actor;
	ClutterActor* _tmp0_;
#line 185 "bar-view.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 496 "bar-view.c"
	_inner_error_ = NULL;
	actor = NULL;
#line 188 "bar-view.vala"
	actor = (_tmp0_ = _g_object_ref0 ((*event).button.source), _g_object_unref0 (actor), _tmp0_);
#line 190 "bar-view.vala"
	if (UNITY_PLACES_BAR_IS_PLACE_ICON (actor)) {
#line 503 "bar-view.c"
		ClutterActor* _tmp1_;
		UnityPlacesBarPlaceIcon* icon;
#line 192 "bar-view.vala"
		icon = _g_object_ref0 ((_tmp1_ = actor, UNITY_PLACES_BAR_IS_PLACE_ICON (_tmp1_) ? ((UnityPlacesBarPlaceIcon*) _tmp1_) : NULL));
#line 195 "bar-view.vala"
		if (actor == CLUTTER_ACTOR (self->priv->trash_icon)) {
#line 510 "bar-view.c"
			{
#line 199 "bar-view.vala"
				g_spawn_command_line_async ("xdg-open trash:///", &_inner_error_);
#line 514 "bar-view.c"
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == G_SPAWN_ERROR) {
						goto __catch11_g_spawn_error;
					}
					_g_object_unref0 (icon);
					_g_object_unref0 (actor);
					g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return FALSE;
				}
			}
			goto __finally11;
			__catch11_g_spawn_error:
			{
				GError * e;
				e = _inner_error_;
				_inner_error_ = NULL;
				{
#line 203 "bar-view.vala"
					g_warning ("bar-view.vala:203: Unable to show Trash: %s", e->message);
#line 535 "bar-view.c"
					_g_error_free0 (e);
				}
			}
			__finally11:
			if (_inner_error_ != NULL) {
				_g_object_unref0 (icon);
				_g_object_unref0 (actor);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return FALSE;
			}
		} else {
#line 206 "bar-view.vala"
			if (UNITY_PLACES_IS_PLACE (unity_places_bar_place_icon_get_place (icon))) {
#line 550 "bar-view.c"
				ClutterActor* stage;
#line 208 "bar-view.vala"
				stage = _g_object_ref0 (clutter_actor_get_stage (actor));
#line 211 "bar-view.vala"
				unity_places_cairo_drawing_places_background_create_places_background (self->priv->bg, (gint) clutter_actor_get_width (stage), (gint) clutter_actor_get_height (stage), (gint) clutter_actor_get_x (actor), 80, unity_shell_get_indicators_width (self->priv->_shell));
#line 556 "bar-view.c"
				{
					GeeIterator* _picon_it;
					_picon_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->places_icons);
#line 218 "bar-view.vala"
					while (TRUE) {
#line 562 "bar-view.c"
						UnityPlacesBarPlaceIcon* picon;
#line 218 "bar-view.vala"
						if (!gee_iterator_next (_picon_it)) {
#line 218 "bar-view.vala"
							break;
#line 568 "bar-view.c"
						}
#line 218 "bar-view.vala"
						picon = (UnityPlacesBarPlaceIcon*) gee_iterator_get (_picon_it);
#line 220 "bar-view.vala"
						if (UNITY_PLACES_IS_PLACE (unity_places_bar_place_icon_get_place (picon))) {
#line 574 "bar-view.c"
							gboolean _tmp2_ = FALSE;
#line 221 "bar-view.vala"
							if (picon == icon) {
#line 221 "bar-view.vala"
								_tmp2_ = TRUE;
#line 580 "bar-view.c"
							} else {
#line 221 "bar-view.vala"
								_tmp2_ = FALSE;
#line 584 "bar-view.c"
							}
#line 221 "bar-view.vala"
							unity_places_place_set_active (unity_places_bar_place_icon_get_place (picon), _tmp2_);
#line 588 "bar-view.c"
						}
						_g_object_unref0 (picon);
					}
					_g_object_unref0 (_picon_it);
				}
				_g_object_unref0 (stage);
			}
		}
		result = TRUE;
		_g_object_unref0 (icon);
		_g_object_unref0 (actor);
#line 225 "bar-view.vala"
		return result;
#line 602 "bar-view.c"
	}
	result = FALSE;
	_g_object_unref0 (actor);
#line 228 "bar-view.vala"
	return result;
#line 608 "bar-view.c"
}


UnityPlacesModel* unity_places_bar_view_get_model (UnityPlacesBarView* self) {
	UnityPlacesModel* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_model;
#line 33 "bar-view.vala"
	return result;
#line 618 "bar-view.c"
}


static void unity_places_bar_view_set_model (UnityPlacesBarView* self, UnityPlacesModel* value) {
	UnityPlacesModel* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_model = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_model), _tmp0_);
	g_object_notify ((GObject *) self, "model");
}


UnityShell* unity_places_bar_view_get_shell (UnityPlacesBarView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
#line 34 "bar-view.vala"
	return result;
#line 636 "bar-view.c"
}


static void unity_places_bar_view_set_shell (UnityPlacesBarView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static void unity_places_bar_view_class_init (UnityPlacesBarViewClass * klass) {
	unity_places_bar_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesBarViewPrivate));
	CLUTTER_ACTOR_CLASS (klass)->map = unity_places_bar_view_real_map;
	CLUTTER_ACTOR_CLASS (klass)->unmap = unity_places_bar_view_real_unmap;
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_places_bar_view_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_bar_view_real_allocate;
	G_OBJECT_CLASS (klass)->get_property = unity_places_bar_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_bar_view_set_property;
	G_OBJECT_CLASS (klass)->finalize = unity_places_bar_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_BAR_VIEW_MODEL, g_param_spec_object ("model", "model", "model", UNITY_PLACES_TYPE_MODEL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_BAR_VIEW_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_bar_view_instance_init (UnityPlacesBarView * self) {
	self->priv = UNITY_PLACES_BAR_VIEW_GET_PRIVATE (self);
}


static void unity_places_bar_view_finalize (GObject* obj) {
	UnityPlacesBarView * self;
	self = UNITY_PLACES_BAR_VIEW (obj);
	_g_object_unref0 (self->priv->_model);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->places_icons);
	_g_object_unref0 (self->priv->trash_icon);
	_g_object_unref0 (self->priv->separator);
	_g_object_unref0 (self->priv->bg);
	G_OBJECT_CLASS (unity_places_bar_view_parent_class)->finalize (obj);
}


GType unity_places_bar_view_get_type (void) {
	static GType unity_places_bar_view_type_id = 0;
	if (unity_places_bar_view_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesBarViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_bar_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesBarView), 0, (GInstanceInitFunc) unity_places_bar_view_instance_init, NULL };
		unity_places_bar_view_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesBarView", &g_define_type_info, 0);
	}
	return unity_places_bar_view_type_id;
}


static void unity_places_bar_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesBarView * self;
	self = UNITY_PLACES_BAR_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_BAR_VIEW_MODEL:
		g_value_set_object (value, unity_places_bar_view_get_model (self));
		break;
		case UNITY_PLACES_BAR_VIEW_SHELL:
		g_value_set_object (value, unity_places_bar_view_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_bar_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesBarView * self;
	self = UNITY_PLACES_BAR_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_BAR_VIEW_MODEL:
		unity_places_bar_view_set_model (self, g_value_get_object (value));
		break;
		case UNITY_PLACES_BAR_VIEW_SHELL:
		unity_places_bar_view_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


#line 236 "bar-view.vala"
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_construct (GType object_type, gint width, const char* name, const char* icon_name, const char* tooltip) {
#line 727 "bar-view.c"
	UnityPlacesBarPlaceIcon * self;
#line 236 "bar-view.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 236 "bar-view.vala"
	g_return_val_if_fail (icon_name != NULL, NULL);
#line 236 "bar-view.vala"
	g_return_val_if_fail (tooltip != NULL, NULL);
#line 241 "bar-view.vala"
	self = (UnityPlacesBarPlaceIcon*) g_object_new (object_type, "size", width, NULL);
#line 243 "bar-view.vala"
	ctk_image_set_from_filename ((CtkImage*) self, icon_name);
#line 244 "bar-view.vala"
	clutter_actor_set_reactive ((ClutterActor*) self, TRUE);
#line 741 "bar-view.c"
	return self;
}


#line 236 "bar-view.vala"
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_new (gint width, const char* name, const char* icon_name, const char* tooltip) {
#line 236 "bar-view.vala"
	return unity_places_bar_place_icon_construct (UNITY_PLACES_BAR_TYPE_PLACE_ICON, width, name, icon_name, tooltip);
#line 750 "bar-view.c"
}


#line 247 "bar-view.vala"
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_construct_from_place (GType object_type, gint size, UnityPlacesPlace* place) {
#line 756 "bar-view.c"
	UnityPlacesBarPlaceIcon * self;
#line 247 "bar-view.vala"
	g_return_val_if_fail (place != NULL, NULL);
#line 249 "bar-view.vala"
	self = (UnityPlacesBarPlaceIcon*) unity_places_bar_place_icon_construct (object_type, size, unity_places_place_get_name (place), unity_places_place_get_icon_name (place), "");
#line 250 "bar-view.vala"
	unity_places_bar_place_icon_set_place (self, place);
#line 764 "bar-view.c"
	return self;
}


#line 247 "bar-view.vala"
UnityPlacesBarPlaceIcon* unity_places_bar_place_icon_new_from_place (gint size, UnityPlacesPlace* place) {
#line 247 "bar-view.vala"
	return unity_places_bar_place_icon_construct_from_place (UNITY_PLACES_BAR_TYPE_PLACE_ICON, size, place);
#line 773 "bar-view.c"
}


UnityPlacesPlace* unity_places_bar_place_icon_get_place (UnityPlacesBarPlaceIcon* self) {
	UnityPlacesPlace* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_place;
#line 234 "bar-view.vala"
	return result;
#line 783 "bar-view.c"
}


void unity_places_bar_place_icon_set_place (UnityPlacesBarPlaceIcon* self, UnityPlacesPlace* value) {
	UnityPlacesPlace* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_place = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_place), _tmp0_);
	g_object_notify ((GObject *) self, "place");
}


static void unity_places_bar_place_icon_class_init (UnityPlacesBarPlaceIconClass * klass) {
	unity_places_bar_place_icon_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesBarPlaceIconPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_bar_place_icon_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_bar_place_icon_set_property;
	G_OBJECT_CLASS (klass)->finalize = unity_places_bar_place_icon_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_BAR_PLACE_ICON_PLACE, g_param_spec_object ("place", "place", "place", UNITY_PLACES_TYPE_PLACE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_places_bar_place_icon_instance_init (UnityPlacesBarPlaceIcon * self) {
	self->priv = UNITY_PLACES_BAR_PLACE_ICON_GET_PRIVATE (self);
}


static void unity_places_bar_place_icon_finalize (GObject* obj) {
	UnityPlacesBarPlaceIcon * self;
	self = UNITY_PLACES_BAR_PLACE_ICON (obj);
	_g_object_unref0 (self->priv->_place);
	G_OBJECT_CLASS (unity_places_bar_place_icon_parent_class)->finalize (obj);
}


GType unity_places_bar_place_icon_get_type (void) {
	static GType unity_places_bar_place_icon_type_id = 0;
	if (unity_places_bar_place_icon_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesBarPlaceIconClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_bar_place_icon_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesBarPlaceIcon), 0, (GInstanceInitFunc) unity_places_bar_place_icon_instance_init, NULL };
		unity_places_bar_place_icon_type_id = g_type_register_static (CTK_TYPE_IMAGE, "UnityPlacesBarPlaceIcon", &g_define_type_info, 0);
	}
	return unity_places_bar_place_icon_type_id;
}


static void unity_places_bar_place_icon_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesBarPlaceIcon * self;
	self = UNITY_PLACES_BAR_PLACE_ICON (object);
	switch (property_id) {
		case UNITY_PLACES_BAR_PLACE_ICON_PLACE:
		g_value_set_object (value, unity_places_bar_place_icon_get_place (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_bar_place_icon_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesBarPlaceIcon * self;
	self = UNITY_PLACES_BAR_PLACE_ICON (object);
	switch (property_id) {
		case UNITY_PLACES_BAR_PLACE_ICON_PLACE:
		unity_places_bar_place_icon_set_place (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




