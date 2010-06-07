/* default-view.c generated by valac, the Vala compiler
 * generated from default-view.vala, do not modify */

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
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <unity-utils.h>
#include <float.h>
#include <math.h>
#include <pango/pango.h>
#include <stdio.h>
#include <gee.h>


#define UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET (unity_places_default_activity_widget_get_type ())
#define UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET, UnityPlacesDefaultActivityWidget))
#define UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET, UnityPlacesDefaultActivityWidgetClass))
#define UNITY_PLACES_DEFAULT_IS_ACTIVITY_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET))
#define UNITY_PLACES_DEFAULT_IS_ACTIVITY_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET))
#define UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET, UnityPlacesDefaultActivityWidgetClass))

typedef struct _UnityPlacesDefaultActivityWidget UnityPlacesDefaultActivityWidget;
typedef struct _UnityPlacesDefaultActivityWidgetClass UnityPlacesDefaultActivityWidgetClass;
typedef struct _UnityPlacesDefaultActivityWidgetPrivate UnityPlacesDefaultActivityWidgetPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_PLACES_DEFAULT_TYPE_VIEW (unity_places_default_view_get_type ())
#define UNITY_PLACES_DEFAULT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultView))
#define UNITY_PLACES_DEFAULT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultViewClass))
#define UNITY_PLACES_DEFAULT_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW))
#define UNITY_PLACES_DEFAULT_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_DEFAULT_TYPE_VIEW))
#define UNITY_PLACES_DEFAULT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultViewClass))

typedef struct _UnityPlacesDefaultView UnityPlacesDefaultView;
typedef struct _UnityPlacesDefaultViewClass UnityPlacesDefaultViewClass;
typedef struct _UnityPlacesDefaultViewPrivate UnityPlacesDefaultViewPrivate;

#define UNITY_PLACES_DEFAULT_TYPE_MODEL (unity_places_default_model_get_type ())
#define UNITY_PLACES_DEFAULT_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_DEFAULT_TYPE_MODEL, UnityPlacesDefaultModel))
#define UNITY_PLACES_DEFAULT_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_DEFAULT_TYPE_MODEL, UnityPlacesDefaultModelClass))
#define UNITY_PLACES_DEFAULT_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_DEFAULT_TYPE_MODEL))
#define UNITY_PLACES_DEFAULT_IS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_DEFAULT_TYPE_MODEL))
#define UNITY_PLACES_DEFAULT_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_DEFAULT_TYPE_MODEL, UnityPlacesDefaultModelClass))

typedef struct _UnityPlacesDefaultModel UnityPlacesDefaultModel;
typedef struct _UnityPlacesDefaultModelClass UnityPlacesDefaultModelClass;
typedef struct _UnityPlacesDefaultModelPrivate UnityPlacesDefaultModelPrivate;

struct _UnityPlacesDefaultActivityWidget {
	CtkBox parent_instance;
	UnityPlacesDefaultActivityWidgetPrivate * priv;
};

struct _UnityPlacesDefaultActivityWidgetClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesDefaultActivityWidgetPrivate {
	CtkImage* icon;
	ClutterText* primary_label;
	ClutterText* secondary_label;
};

struct _UnityPlacesDefaultView {
	CtkIconView parent_instance;
	UnityPlacesDefaultViewPrivate * priv;
};

struct _UnityPlacesDefaultViewClass {
	CtkIconViewClass parent_class;
};

struct _UnityPlacesDefaultViewPrivate {
	GeeArrayList* activities;
};

struct _UnityPlacesDefaultModel {
	GObject parent_instance;
	UnityPlacesDefaultModelPrivate * priv;
	char* icon_name;
	char* primary_text;
	char* secondary_text;
};

struct _UnityPlacesDefaultModelClass {
	GObjectClass parent_class;
};


static gpointer unity_places_default_activity_widget_parent_class = NULL;
static gpointer unity_places_default_view_parent_class = NULL;

GType unity_places_default_activity_widget_get_type (void);
#define UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET, UnityPlacesDefaultActivityWidgetPrivate))
enum  {
	UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET_DUMMY_PROPERTY
};
gboolean unity_places_default_activity_widget_on_enter (UnityPlacesDefaultActivityWidget* self);
static gboolean _unity_places_default_activity_widget_on_enter_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
gboolean unity_places_default_activity_widget_on_leave (UnityPlacesDefaultActivityWidget* self);
static gboolean _unity_places_default_activity_widget_on_leave_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
UnityPlacesDefaultActivityWidget* unity_places_default_activity_widget_new (gint spacing, gint size, const char* icon_name, const char* primary_text, const char* secondary_text);
UnityPlacesDefaultActivityWidget* unity_places_default_activity_widget_construct (GType object_type, gint spacing, gint size, const char* icon_name, const char* primary_text, const char* secondary_text);
gboolean unity_places_default_activity_widget_on_clicked (UnityPlacesDefaultActivityWidget* self);
static GObject * unity_places_default_activity_widget_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_default_activity_widget_finalize (GObject* obj);
GType unity_places_default_view_get_type (void);
GType unity_places_default_model_get_type (void);
#define UNITY_PLACES_DEFAULT_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultViewPrivate))
enum  {
	UNITY_PLACES_DEFAULT_VIEW_DUMMY_PROPERTY
};
static void unity_places_default_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
UnityPlacesDefaultModel* unity_places_default_model_new (const char* icon_name, const char* primary_text, const char* secondary_text);
UnityPlacesDefaultModel* unity_places_default_model_construct (GType object_type, const char* icon_name, const char* primary_text, const char* secondary_text);
UnityPlacesDefaultView* unity_places_default_view_new (void);
UnityPlacesDefaultView* unity_places_default_view_construct (GType object_type);
static GObject * unity_places_default_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_default_view_finalize (GObject* obj);



static gboolean _unity_places_default_activity_widget_on_enter_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_places_default_activity_widget_on_enter (self);
	return result;
}


static gboolean _unity_places_default_activity_widget_on_leave_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_places_default_activity_widget_on_leave (self);
	return result;
}


UnityPlacesDefaultActivityWidget* unity_places_default_activity_widget_construct (GType object_type, gint spacing, gint size, const char* icon_name, const char* primary_text, const char* secondary_text) {
	UnityPlacesDefaultActivityWidget * self;
	char* process_name;
	ClutterColor _tmp0_ = {0};
	ClutterColor color;
	CtkImage* _tmp1_;
	ClutterText* _tmp2_;
	ClutterText* _tmp3_;
	g_return_val_if_fail (icon_name != NULL, NULL);
	g_return_val_if_fail (primary_text != NULL, NULL);
	g_return_val_if_fail (secondary_text != NULL, NULL);
	self = g_object_newv (object_type, 0, NULL);
	process_name = g_strconcat ("activity_widget", icon_name, NULL);
	LOGGER_START_PROCESS (process_name);
	color = (_tmp0_.red = (guint8) 255, _tmp0_.green = (guint8) 255, _tmp0_.blue = (guint8) 255, _tmp0_.alpha = (guint8) 255, _tmp0_);
	ctk_box_set_homogeneous ((CtkBox*) self, FALSE);
	ctk_box_set_orientation ((CtkBox*) self, (gint) CTK_ORIENTATION_VERTICAL);
	clutter_actor_set_reactive ((ClutterActor*) self, TRUE);
	ctk_box_set_spacing ((CtkBox*) self, spacing);
	self->priv->icon = (_tmp1_ = g_object_ref_sink ((CtkImage*) ctk_image_new_from_stock ((guint) size, icon_name)), _g_object_unref0 (self->priv->icon), _tmp1_);
	clutter_actor_set_reactive ((ClutterActor*) self->priv->icon, TRUE);
	self->priv->primary_label = (_tmp2_ = g_object_ref_sink ((ClutterText*) clutter_text_new ()), _g_object_unref0 (self->priv->primary_label), _tmp2_);
	clutter_actor_set_reactive ((ClutterActor*) self->priv->primary_label, TRUE);
	clutter_actor_set_width ((ClutterActor*) self->priv->primary_label, (float) size);
	clutter_text_set_markup (self->priv->primary_label, primary_text);
	clutter_text_set_justify (self->priv->primary_label, TRUE);
	clutter_text_set_color (self->priv->primary_label, &color);
	clutter_text_set_ellipsize (self->priv->primary_label, PANGO_ELLIPSIZE_NONE);
	clutter_text_set_line_wrap (self->priv->primary_label, TRUE);
	clutter_text_set_line_alignment (self->priv->primary_label, PANGO_ALIGN_CENTER);
	self->priv->secondary_label = (_tmp3_ = g_object_ref_sink ((ClutterText*) clutter_text_new ()), _g_object_unref0 (self->priv->secondary_label), _tmp3_);
	clutter_actor_set_reactive ((ClutterActor*) self->priv->secondary_label, TRUE);
	clutter_actor_set_width ((ClutterActor*) self->priv->secondary_label, (float) (size + spacing));
	clutter_text_set_text (self->priv->secondary_label, secondary_text);
	clutter_text_set_justify (self->priv->secondary_label, FALSE);
	clutter_text_set_color (self->priv->secondary_label, &color);
	clutter_text_set_line_wrap (self->priv->secondary_label, TRUE);
	clutter_text_set_line_alignment (self->priv->secondary_label, PANGO_ALIGN_CENTER);
	clutter_text_set_line_wrap_mode (self->priv->secondary_label, PANGO_WRAP_WORD_CHAR);
	g_signal_connect_object ((ClutterActor*) self, "enter-event", (GCallback) _unity_places_default_activity_widget_on_enter_clutter_actor_enter_event, self, 0);
	g_signal_connect_object ((ClutterActor*) self, "leave-event", (GCallback) _unity_places_default_activity_widget_on_leave_clutter_actor_leave_event, self, 0);
	clutter_actor_set_opacity ((ClutterActor*) self->priv->secondary_label, (guint8) 0);
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->icon, FALSE, FALSE);
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->primary_label, FALSE, FALSE);
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->secondary_label, FALSE, FALSE);
	LOGGER_END_PROCESS (process_name);
	_g_free0 (process_name);
	return self;
}


UnityPlacesDefaultActivityWidget* unity_places_default_activity_widget_new (gint spacing, gint size, const char* icon_name, const char* primary_text, const char* secondary_text) {
	return unity_places_default_activity_widget_construct (UNITY_PLACES_DEFAULT_TYPE_ACTIVITY_WIDGET, spacing, size, icon_name, primary_text, secondary_text);
}


gboolean unity_places_default_activity_widget_on_enter (UnityPlacesDefaultActivityWidget* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	clutter_actor_set_opacity ((ClutterActor*) self->priv->secondary_label, (guint8) 255);
	result = FALSE;
	return result;
}


gboolean unity_places_default_activity_widget_on_leave (UnityPlacesDefaultActivityWidget* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	clutter_actor_set_opacity ((ClutterActor*) self->priv->secondary_label, (guint8) 0);
	result = FALSE;
	return result;
}


gboolean unity_places_default_activity_widget_on_clicked (UnityPlacesDefaultActivityWidget* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	fprintf (stdout, "on_clicked() called\n");
	result = FALSE;
	return result;
}


static GObject * unity_places_default_activity_widget_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesDefaultActivityWidget * self;
	parent_class = G_OBJECT_CLASS (unity_places_default_activity_widget_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET (obj);
	{
	}
	return obj;
}


static void unity_places_default_activity_widget_class_init (UnityPlacesDefaultActivityWidgetClass * klass) {
	unity_places_default_activity_widget_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesDefaultActivityWidgetPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_places_default_activity_widget_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_default_activity_widget_finalize;
}


static void unity_places_default_activity_widget_instance_init (UnityPlacesDefaultActivityWidget * self) {
	self->priv = UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET_GET_PRIVATE (self);
}


static void unity_places_default_activity_widget_finalize (GObject* obj) {
	UnityPlacesDefaultActivityWidget * self;
	self = UNITY_PLACES_DEFAULT_ACTIVITY_WIDGET (obj);
	_g_object_unref0 (self->priv->icon);
	_g_object_unref0 (self->priv->primary_label);
	_g_object_unref0 (self->priv->secondary_label);
	G_OBJECT_CLASS (unity_places_default_activity_widget_parent_class)->finalize (obj);
}


GType unity_places_default_activity_widget_get_type (void) {
	static volatile gsize unity_places_default_activity_widget_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_default_activity_widget_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesDefaultActivityWidgetClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_default_activity_widget_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesDefaultActivityWidget), 0, (GInstanceInitFunc) unity_places_default_activity_widget_instance_init, NULL };
		GType unity_places_default_activity_widget_type_id;
		unity_places_default_activity_widget_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesDefaultActivityWidget", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_default_activity_widget_type_id__volatile, unity_places_default_activity_widget_type_id);
	}
	return unity_places_default_activity_widget_type_id__volatile;
}


static void unity_places_default_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesDefaultView * self;
	CtkPadding _tmp0_ = {0};
	CtkPadding padding;
	float real_width = 0.0F;
	float real_height = 0.0F;
	float min_height_p = 0.0F;
	float natural_height_p = 0.0F;
	gint hor_spacing = 0;
	self = (UnityPlacesDefaultView*) base;
	padding = (_tmp0_.top = 0.0f, _tmp0_.right = 0.0f, _tmp0_.bottom = 0.0f, _tmp0_.left = 0.0f, _tmp0_);
	hor_spacing = ctk_icon_view_get_spacing ((CtkIconView*) self);
	real_width = (*box).x2 - (*box).x1;
	real_height = (*box).y2 - (*box).y1;
	padding.left = ((real_width - (4 * 128)) - (3 * hor_spacing)) / 2.0f;
	padding.right = padding.left;
	clutter_actor_get_preferred_height ((ClutterActor*) self, real_width, &min_height_p, &natural_height_p);
	padding.top = (real_height - 400) / 2.0f;
	padding.bottom = padding.top;
	ctk_actor_set_padding ((CtkActor*) self, &padding);
	CLUTTER_ACTOR_CLASS (unity_places_default_view_parent_class)->allocate ((ClutterActor*) CTK_ICON_VIEW (self), box, flags);
}


UnityPlacesDefaultView* unity_places_default_view_construct (GType object_type) {
	UnityPlacesDefaultView * self;
	UnityPlacesDefaultModel* activity;
	gint i = 0;
	UnityPlacesDefaultActivityWidget* widget;
	gint widget_size;
	GeeArrayList* _tmp0_;
	UnityPlacesDefaultModel* _tmp1_;
	UnityPlacesDefaultModel* _tmp2_;
	UnityPlacesDefaultModel* _tmp3_;
	UnityPlacesDefaultModel* _tmp4_;
	UnityPlacesDefaultModel* _tmp5_;
	UnityPlacesDefaultModel* _tmp6_;
	UnityPlacesDefaultModel* _tmp7_;
	UnityPlacesDefaultModel* _tmp8_;
	self = g_object_newv (object_type, 0, NULL);
	START_FUNCTION ();
	activity = NULL;
	widget = NULL;
	widget_size = 128;
	self->priv->activities = (_tmp0_ = gee_array_list_new (UNITY_PLACES_DEFAULT_TYPE_MODEL, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->activities), _tmp0_);
	activity = (_tmp1_ = unity_places_default_model_new ("applications-internet", "<b>Web</b>", "Search, Suft & Download"), _g_object_unref0 (activity), _tmp1_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp2_ = unity_places_default_model_new ("rhythmbox", "<b>Music</b>", "Jukebox, Radio & Podcasts"), _g_object_unref0 (activity), _tmp2_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp3_ = unity_places_default_model_new ("applications-multimedia", "<b>Videos</b>", "YouTube & More"), _g_object_unref0 (activity), _tmp3_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp4_ = unity_places_default_model_new ("applications-graphics", "<b>Photos</b>", "Organize, Edit & Share"), _g_object_unref0 (activity), _tmp4_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp5_ = unity_places_default_model_new ("applications-office", "<b>Work</b>", "Office Documents, Spreadsheets & Presentations"), _g_object_unref0 (activity), _tmp5_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp6_ = unity_places_default_model_new ("evolution", "<b>Email</b>", "Read & Write Email"), _g_object_unref0 (activity), _tmp6_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp7_ = unity_places_default_model_new ("empathy", "<b>Chat</b>", "AIM, Yahoo, Skype & MSN"), _g_object_unref0 (activity), _tmp7_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	activity = (_tmp8_ = unity_places_default_model_new ("softwarecenter", "<b>Get New Apps</b>", "Ubuntu Software Center"), _g_object_unref0 (activity), _tmp8_);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->activities, activity);
	{
		gboolean _tmp9_;
		i = 0;
		_tmp9_ = TRUE;
		while (TRUE) {
			UnityPlacesDefaultActivityWidget* _tmp13_;
			UnityPlacesDefaultModel* _tmp12_;
			UnityPlacesDefaultModel* _tmp11_;
			UnityPlacesDefaultModel* _tmp10_;
			if (!_tmp9_) {
				i++;
			}
			_tmp9_ = FALSE;
			if (!(i < gee_collection_get_size ((GeeCollection*) self->priv->activities))) {
				break;
			}
			widget = (_tmp13_ = g_object_ref_sink (unity_places_default_activity_widget_new (0, widget_size, (_tmp10_ = (UnityPlacesDefaultModel*) gee_abstract_list_get ((GeeAbstractList*) self->priv->activities, i))->icon_name, (_tmp11_ = (UnityPlacesDefaultModel*) gee_abstract_list_get ((GeeAbstractList*) self->priv->activities, i))->primary_text, (_tmp12_ = (UnityPlacesDefaultModel*) gee_abstract_list_get ((GeeAbstractList*) self->priv->activities, i))->secondary_text)), _g_object_unref0 (widget), _tmp13_);
			_g_object_unref0 (_tmp12_);
			_g_object_unref0 (_tmp11_);
			_g_object_unref0 (_tmp10_);
			clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) widget);
		}
	}
	clutter_actor_show_all ((ClutterActor*) self);
	END_FUNCTION ();
	_g_object_unref0 (activity);
	_g_object_unref0 (widget);
	return self;
}


UnityPlacesDefaultView* unity_places_default_view_new (void) {
	return unity_places_default_view_construct (UNITY_PLACES_DEFAULT_TYPE_VIEW);
}


static GObject * unity_places_default_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesDefaultView * self;
	parent_class = G_OBJECT_CLASS (unity_places_default_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_DEFAULT_VIEW (obj);
	{
	}
	return obj;
}


static void unity_places_default_view_class_init (UnityPlacesDefaultViewClass * klass) {
	unity_places_default_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesDefaultViewPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_default_view_real_allocate;
	G_OBJECT_CLASS (klass)->constructor = unity_places_default_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_default_view_finalize;
}


static void unity_places_default_view_instance_init (UnityPlacesDefaultView * self) {
	self->priv = UNITY_PLACES_DEFAULT_VIEW_GET_PRIVATE (self);
}


static void unity_places_default_view_finalize (GObject* obj) {
	UnityPlacesDefaultView * self;
	self = UNITY_PLACES_DEFAULT_VIEW (obj);
	_g_object_unref0 (self->priv->activities);
	G_OBJECT_CLASS (unity_places_default_view_parent_class)->finalize (obj);
}


GType unity_places_default_view_get_type (void) {
	static volatile gsize unity_places_default_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_default_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesDefaultViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_default_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesDefaultView), 0, (GInstanceInitFunc) unity_places_default_view_instance_init, NULL };
		GType unity_places_default_view_type_id;
		unity_places_default_view_type_id = g_type_register_static (CTK_TYPE_ICON_VIEW, "UnityPlacesDefaultView", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_default_view_type_id__volatile, unity_places_default_view_type_id);
	}
	return unity_places_default_view_type_id__volatile;
}




