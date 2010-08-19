/* places-folder-browser-renderer.c generated by valac 0.9.5, the Vala compiler
 * generated from places-folder-browser-renderer.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <dee.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <gee.h>


#define UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER (unity_places_folder_browser_renderer_get_type ())
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRenderer))
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRendererClass))
#define UNITY_PLACES_IS_FOLDER_BROWSER_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER))
#define UNITY_PLACES_IS_FOLDER_BROWSER_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER))
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRendererClass))

typedef struct _UnityPlacesFolderBrowserRenderer UnityPlacesFolderBrowserRenderer;
typedef struct _UnityPlacesFolderBrowserRendererClass UnityPlacesFolderBrowserRendererClass;
typedef struct _UnityPlacesFolderBrowserRendererPrivate UnityPlacesFolderBrowserRendererPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP (unity_places_default_renderer_group_get_type ())
#define UNITY_PLACES_DEFAULT_RENDERER_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP, UnityPlacesDefaultRendererGroup))
#define UNITY_PLACES_DEFAULT_RENDERER_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP, UnityPlacesDefaultRendererGroupClass))
#define UNITY_PLACES_IS_DEFAULT_RENDERER_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP))
#define UNITY_PLACES_IS_DEFAULT_RENDERER_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP))
#define UNITY_PLACES_DEFAULT_RENDERER_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER_GROUP, UnityPlacesDefaultRendererGroupClass))

typedef struct _UnityPlacesDefaultRendererGroup UnityPlacesDefaultRendererGroup;
typedef struct _UnityPlacesDefaultRendererGroupClass UnityPlacesDefaultRendererGroupClass;

struct _UnityPlacesFolderBrowserRenderer {
	CtkScrollView parent_instance;
	UnityPlacesFolderBrowserRendererPrivate * priv;
};

struct _UnityPlacesFolderBrowserRendererClass {
	CtkScrollViewClass parent_class;
};

struct _UnityPlacesFolderBrowserRendererPrivate {
	CtkVBox* box;
	DeeModel* results_model;
};


static gpointer unity_places_folder_browser_renderer_parent_class = NULL;
static UnityPlaceRendererIface* unity_places_folder_browser_renderer_unity_place_renderer_parent_iface = NULL;

GType unity_places_folder_browser_renderer_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRendererPrivate))
enum  {
	UNITY_PLACES_FOLDER_BROWSER_RENDERER_DUMMY_PROPERTY
};
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_PADDING 12.0f
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_SPACING 0
UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_new (void);
UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_construct (GType object_type);
UnityPlacesDefaultRendererGroup* unity_places_default_renderer_group_new (guint group_id, const char* group_renderer, const char* display_name, const char* icon_hint, DeeModel* results);
UnityPlacesDefaultRendererGroup* unity_places_default_renderer_group_construct (GType object_type, guint group_id, const char* group_renderer, const char* display_name, const char* icon_hint, DeeModel* results);
GType unity_places_default_renderer_group_get_type (void) G_GNUC_CONST;
static void _lambda42_ (const char* u, const char* m, UnityPlacesFolderBrowserRenderer* self);
static void __lambda42__unity_places_default_renderer_group_activated (UnityPlacesDefaultRendererGroup* _sender, const char* uri, const char* mimetype, gpointer self);
static void unity_places_folder_browser_renderer_real_set_models (UnityPlaceRenderer* base, DeeModel* model, DeeModel* results, GeeHashMap* hints);
static GObject * unity_places_folder_browser_renderer_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_folder_browser_renderer_finalize (GObject* obj);



UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_construct (GType object_type) {
	UnityPlacesFolderBrowserRenderer * self;
	self = (UnityPlacesFolderBrowserRenderer*) g_object_new (object_type, NULL);
	return self;
}


UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_new (void) {
	return unity_places_folder_browser_renderer_construct (UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _lambda42_ (const char* u, const char* m, UnityPlacesFolderBrowserRenderer* self) {
	g_return_if_fail (u != NULL);
	g_return_if_fail (m != NULL);
	g_signal_emit_by_name ((UnityPlaceRenderer*) self, "activated", u, m);
}


static void __lambda42__unity_places_default_renderer_group_activated (UnityPlacesDefaultRendererGroup* _sender, const char* uri, const char* mimetype, gpointer self) {
	_lambda42_ (uri, mimetype, self);
}


static void unity_places_folder_browser_renderer_real_set_models (UnityPlaceRenderer* base, DeeModel* model, DeeModel* results, GeeHashMap* hints) {
	UnityPlacesFolderBrowserRenderer * self;
	DeeModel* _tmp0_;
	UnityPlacesDefaultRendererGroup* group;
	self = (UnityPlacesFolderBrowserRenderer*) base;
	g_return_if_fail (model != NULL);
	g_return_if_fail (results != NULL);
	g_return_if_fail (hints != NULL);
	self->priv->results_model = (_tmp0_ = _g_object_ref0 (results), _g_object_unref0 (self->priv->results_model), _tmp0_);
	group = g_object_ref_sink (unity_places_default_renderer_group_new ((guint) 0, "UnityFolderGroupRenderer", "__you_cant_see_me__", "gtk-apply", results));
	g_signal_connect_object (group, "activated", (GCallback) __lambda42__unity_places_default_renderer_group_activated, self, 0);
	ctk_box_pack ((CtkBox*) self->priv->box, (ClutterActor*) group, FALSE, TRUE);
	_g_object_unref0 (group);
}


static GObject * unity_places_folder_browser_renderer_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesFolderBrowserRenderer * self;
	parent_class = G_OBJECT_CLASS (unity_places_folder_browser_renderer_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_FOLDER_BROWSER_RENDERER (obj);
	{
		CtkPadding _tmp0_ = {0};
		CtkPadding _tmp1_;
		CtkVBox* _tmp2_;
		CtkPadding _tmp3_ = {0};
		CtkPadding _tmp4_;
		ctk_actor_set_padding ((CtkActor*) self, (_tmp1_ = (_tmp0_.top = 0.0f, _tmp0_.right = 0.0f, _tmp0_.bottom = 0.0f, _tmp0_.left = 0.0f, _tmp0_), &_tmp1_));
		self->priv->box = (_tmp2_ = g_object_ref_sink ((CtkVBox*) ctk_vbox_new ((guint) UNITY_PLACES_FOLDER_BROWSER_RENDERER_SPACING)), _g_object_unref0 (self->priv->box), _tmp2_);
		ctk_actor_set_padding ((CtkActor*) self->priv->box, (_tmp4_ = (_tmp3_.top = 0.0f, _tmp3_.right = UNITY_PLACES_FOLDER_BROWSER_RENDERER_PADDING, _tmp3_.bottom = 0.0f, _tmp3_.left = UNITY_PLACES_FOLDER_BROWSER_RENDERER_PADDING, _tmp3_), &_tmp4_));
		ctk_box_set_homogeneous ((CtkBox*) self->priv->box, FALSE);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->box);
		clutter_actor_show ((ClutterActor*) self->priv->box);
	}
	return obj;
}


static void unity_places_folder_browser_renderer_class_init (UnityPlacesFolderBrowserRendererClass * klass) {
	unity_places_folder_browser_renderer_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesFolderBrowserRendererPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_places_folder_browser_renderer_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_folder_browser_renderer_finalize;
}


static void unity_places_folder_browser_renderer_unity_place_renderer_interface_init (UnityPlaceRendererIface * iface) {
	unity_places_folder_browser_renderer_unity_place_renderer_parent_iface = g_type_interface_peek_parent (iface);
	iface->set_models = unity_places_folder_browser_renderer_real_set_models;
}


static void unity_places_folder_browser_renderer_instance_init (UnityPlacesFolderBrowserRenderer * self) {
	self->priv = UNITY_PLACES_FOLDER_BROWSER_RENDERER_GET_PRIVATE (self);
}


static void unity_places_folder_browser_renderer_finalize (GObject* obj) {
	UnityPlacesFolderBrowserRenderer * self;
	self = UNITY_PLACES_FOLDER_BROWSER_RENDERER (obj);
	_g_object_unref0 (self->priv->box);
	_g_object_unref0 (self->priv->results_model);
	G_OBJECT_CLASS (unity_places_folder_browser_renderer_parent_class)->finalize (obj);
}


GType unity_places_folder_browser_renderer_get_type (void) {
	static volatile gsize unity_places_folder_browser_renderer_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_folder_browser_renderer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesFolderBrowserRendererClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_folder_browser_renderer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesFolderBrowserRenderer), 0, (GInstanceInitFunc) unity_places_folder_browser_renderer_instance_init, NULL };
		static const GInterfaceInfo unity_place_renderer_info = { (GInterfaceInitFunc) unity_places_folder_browser_renderer_unity_place_renderer_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType unity_places_folder_browser_renderer_type_id;
		unity_places_folder_browser_renderer_type_id = g_type_register_static (CTK_TYPE_SCROLL_VIEW, "UnityPlacesFolderBrowserRenderer", &g_define_type_info, 0);
		g_type_add_interface_static (unity_places_folder_browser_renderer_type_id, UNITY_PLACE_TYPE_RENDERER, &unity_place_renderer_info);
		g_once_init_leave (&unity_places_folder_browser_renderer_type_id__volatile, unity_places_folder_browser_renderer_type_id);
	}
	return unity_places_folder_browser_renderer_type_id__volatile;
}




