/* panel-tray.c generated by valac, the Vala compiler
 * generated from panel-tray.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
#include <unity-misc/unity-misc.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_PANEL_TYPE_SYSTEM_TRAY (unity_panel_system_tray_get_type ())
#define UNITY_PANEL_SYSTEM_TRAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTray))
#define UNITY_PANEL_SYSTEM_TRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTrayClass))
#define UNITY_PANEL_IS_SYSTEM_TRAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY))
#define UNITY_PANEL_IS_SYSTEM_TRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_SYSTEM_TRAY))
#define UNITY_PANEL_SYSTEM_TRAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTrayClass))

typedef struct _UnityPanelSystemTray UnityPanelSystemTray;
typedef struct _UnityPanelSystemTrayClass UnityPanelSystemTrayClass;
typedef struct _UnityPanelSystemTrayPrivate UnityPanelSystemTrayPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TESTING_TYPE_OBJECT_REGISTRY (unity_testing_object_registry_get_type ())
#define UNITY_TESTING_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistry))
#define UNITY_TESTING_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))
#define UNITY_TESTING_IS_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_IS_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_OBJECT_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))

typedef struct _UnityTestingObjectRegistry UnityTestingObjectRegistry;
typedef struct _UnityTestingObjectRegistryClass UnityTestingObjectRegistryClass;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _UnityPanelSystemTray {
	CtkBox parent_instance;
	UnityPanelSystemTrayPrivate * priv;
};

struct _UnityPanelSystemTrayClass {
	CtkBoxClass parent_class;
};

struct _UnityPanelSystemTrayPrivate {
	UnityTrayManager* manager;
	ClutterStage* stage;
	gint n_icons;
};


static gpointer unity_panel_system_tray_parent_class = NULL;

GType unity_panel_system_tray_get_type (void);
#define UNITY_PANEL_SYSTEM_TRAY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTrayPrivate))
enum  {
	UNITY_PANEL_SYSTEM_TRAY_DUMMY_PROPERTY
};
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void);
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
UnityPanelSystemTray* unity_panel_system_tray_new (void);
UnityPanelSystemTray* unity_panel_system_tray_construct (GType object_type);
static gboolean unity_panel_system_tray_manage_tray_idle (UnityPanelSystemTray* self);
static gboolean _unity_panel_system_tray_manage_tray_idle_gsource_func (gpointer self);
void unity_panel_system_tray_manage_stage (UnityPanelSystemTray* self, ClutterStage* stage);
static gint unity_panel_system_tray_order_icons (ClutterActor* a, ClutterActor* b);
static void unity_panel_system_tray_on_tray_icon_added (UnityPanelSystemTray* self, ClutterActor* icon);
static void unity_panel_system_tray_on_tray_icon_removed (UnityPanelSystemTray* self, ClutterActor* icon);
static void _unity_panel_system_tray_on_tray_icon_added_unity_tray_manager_tray_icon_added (UnityTrayManager* _sender, ClutterActor* icon, gpointer self);
static void _unity_panel_system_tray_on_tray_icon_removed_unity_tray_manager_tray_icon_removed (UnityTrayManager* _sender, ClutterActor* icon, gpointer self);
static GObject * unity_panel_system_tray_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_system_tray_finalize (GObject* obj);



UnityPanelSystemTray* unity_panel_system_tray_construct (GType object_type) {
	UnityPanelSystemTray * self;
	UnityTestingObjectRegistry* _tmp0_;
	self = (UnityPanelSystemTray*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "spacing", 8, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "PanelSystemTray", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityPanelSystemTray* unity_panel_system_tray_new (void) {
	return unity_panel_system_tray_construct (UNITY_PANEL_TYPE_SYSTEM_TRAY);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _unity_panel_system_tray_manage_tray_idle_gsource_func (gpointer self) {
	gboolean result;
	result = unity_panel_system_tray_manage_tray_idle (self);
	return result;
}


void unity_panel_system_tray_manage_stage (UnityPanelSystemTray* self, ClutterStage* stage) {
	ClutterStage* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stage != NULL);
	self->priv->stage = (_tmp0_ = _g_object_ref0 (stage), _g_object_unref0 (self->priv->stage), _tmp0_);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _unity_panel_system_tray_manage_tray_idle_gsource_func, g_object_ref (self), g_object_unref);
}


static gboolean unity_panel_system_tray_manage_tray_idle (UnityPanelSystemTray* self) {
	gboolean result = FALSE;
	char* disable_tray;
	g_return_val_if_fail (self != NULL, FALSE);
	disable_tray = g_strdup (g_getenv ("UNITY_DISABLE_TRAY"));
	if (disable_tray == NULL) {
		unity_tray_manager_manage_stage (self->priv->manager, self->priv->stage);
	}
	result = FALSE;
	_g_free0 (disable_tray);
	return result;
}


static gint unity_panel_system_tray_order_icons (ClutterActor* a, ClutterActor* b) {
	gint result = 0;
	const char* stra;
	const char* strb;
	const char* _tmp0_;
	const char* _tmp1_;
	g_return_val_if_fail (a != NULL, 0);
	g_return_val_if_fail (b != NULL, 0);
	stra = (const char*) ((const char*) g_object_get_data ((GObject*) a, "n_icon"));
	strb = (const char*) ((const char*) g_object_get_data ((GObject*) b, "n_icon"));
	_tmp0_ = NULL;
	if (stra != NULL) {
		_tmp0_ = stra;
	} else {
		_tmp0_ = "";
	}
	_tmp1_ = NULL;
	if (strb != NULL) {
		_tmp1_ = strb;
	} else {
		_tmp1_ = "";
	}
	result = g_strcmp0 (_tmp0_, _tmp1_);
	return result;
}


static void unity_panel_system_tray_on_tray_icon_added (UnityPanelSystemTray* self, ClutterActor* icon) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon != NULL);
	clutter_container_add_actor ((ClutterContainer*) self, icon);
	clutter_actor_set_size (icon, (float) 22, (float) 22);
	clutter_actor_show (icon);
	clutter_actor_set_opacity (icon, (guint8) 0);
	clutter_actor_animate (icon, (gulong) CLUTTER_EASE_IN_OUT_SINE, (guint) 1000, "opacity", 255, NULL);
	g_object_set_data_full ((GObject*) icon, "n_icon", (void*) g_strdup_printf ("%d", self->priv->n_icons), NULL);
	ctk_box_sort_children ((CtkBox*) self, (GCompareFunc) unity_panel_system_tray_order_icons);
	self->priv->n_icons++;
}


static void unity_panel_system_tray_on_tray_icon_removed (UnityPanelSystemTray* self, ClutterActor* icon) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon != NULL);
	clutter_container_remove_actor ((ClutterContainer*) self, icon);
}


static void _unity_panel_system_tray_on_tray_icon_added_unity_tray_manager_tray_icon_added (UnityTrayManager* _sender, ClutterActor* icon, gpointer self) {
	unity_panel_system_tray_on_tray_icon_added (self, icon);
}


static void _unity_panel_system_tray_on_tray_icon_removed_unity_tray_manager_tray_icon_removed (UnityTrayManager* _sender, ClutterActor* icon, gpointer self) {
	unity_panel_system_tray_on_tray_icon_removed (self, icon);
}


static GObject * unity_panel_system_tray_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelSystemTray * self;
	parent_class = G_OBJECT_CLASS (unity_panel_system_tray_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_SYSTEM_TRAY (obj);
	{
		UnityTrayManager* _tmp0_;
		self->priv->manager = (_tmp0_ = unity_tray_manager_new (), _g_object_unref0 (self->priv->manager), _tmp0_);
		g_signal_connect_object (self->priv->manager, "tray-icon-added", (GCallback) _unity_panel_system_tray_on_tray_icon_added_unity_tray_manager_tray_icon_added, self, 0);
		g_signal_connect_object (self->priv->manager, "tray-icon-removed", (GCallback) _unity_panel_system_tray_on_tray_icon_removed_unity_tray_manager_tray_icon_removed, self, 0);
	}
	return obj;
}


static void unity_panel_system_tray_class_init (UnityPanelSystemTrayClass * klass) {
	unity_panel_system_tray_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelSystemTrayPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_panel_system_tray_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_system_tray_finalize;
}


static void unity_panel_system_tray_instance_init (UnityPanelSystemTray * self) {
	self->priv = UNITY_PANEL_SYSTEM_TRAY_GET_PRIVATE (self);
	self->priv->n_icons = 1;
}


static void unity_panel_system_tray_finalize (GObject* obj) {
	UnityPanelSystemTray * self;
	self = UNITY_PANEL_SYSTEM_TRAY (obj);
	_g_object_unref0 (self->priv->manager);
	_g_object_unref0 (self->priv->stage);
	G_OBJECT_CLASS (unity_panel_system_tray_parent_class)->finalize (obj);
}


GType unity_panel_system_tray_get_type (void) {
	static volatile gsize unity_panel_system_tray_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_system_tray_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelSystemTrayClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_system_tray_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelSystemTray), 0, (GInstanceInitFunc) unity_panel_system_tray_instance_init, NULL };
		GType unity_panel_system_tray_type_id;
		unity_panel_system_tray_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPanelSystemTray", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_system_tray_type_id__volatile, unity_panel_system_tray_type_id);
	}
	return unity_panel_system_tray_type_id__volatile;
}




