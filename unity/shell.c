/* shell.c generated by valac 0.9.5, the Vala compiler
 * generated from shell.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>


#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

#define UNITY_TYPE_DND_TARGETS (unity_dnd_targets_get_type ())

#define UNITY_TYPE_WINDOW_ACTION (unity_window_action_get_type ())

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

typedef enum  {
	UNITY_SHELL_MODE_MINIMIZED,
	UNITY_SHELL_MODE_DASH,
	UNITY_SHELL_MODE_EXPOSE
} UnityShellMode;

typedef enum  {
	UNITY_DND_TARGETS_TARGET_INT32,
	UNITY_DND_TARGETS_TARGET_STRING,
	UNITY_DND_TARGETS_TARGET_URL,
	UNITY_DND_TARGETS_TARGET_OTHER
} Unitydnd_targets;

typedef enum  {
	UNITY_WINDOW_ACTION_CLOSE,
	UNITY_WINDOW_ACTION_MINIMIZE,
	UNITY_WINDOW_ACTION_MAXIMIZE,
	UNITY_WINDOW_ACTION_UNMAXIMIZE
} UnityWindowAction;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	guint32 (*get_current_time) (UnityShell* self);
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	void (*hide_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	gint (*get_launcher_width_foobar) (UnityShell* self);
	gint (*get_panel_height_foobar) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*about_to_show_places) (UnityShell* self);
	void (*close_xids) (UnityShell* self, GArray* xids);
	void (*show_window) (UnityShell* self, guint32 xid);
	void (*expose_xids) (UnityShell* self, GArray* xids);
	void (*stop_expose) (UnityShell* self);
	void (*get_window_details) (UnityShell* self, guint32 xid, gboolean* allows_resize, gboolean* is_maximised);
	void (*do_window_action) (UnityShell* self, guint32 xid, UnityWindowAction action);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
	gboolean (*get_super_key_active) (UnityShell* self);
	void (*set_super_key_active) (UnityShell* self, gboolean value);
};


extern UnityShell* unity_global_shell;
UnityShell* unity_global_shell = NULL;

GType unity_shell_mode_get_type (void) G_GNUC_CONST;
GType unity_dnd_targets_get_type (void) G_GNUC_CONST;
GType unity_window_action_get_type (void) G_GNUC_CONST;
GType unity_shell_get_type (void) G_GNUC_CONST;
guint32 unity_shell_get_current_time (UnityShell* self);
UnityShellMode unity_shell_get_mode (UnityShell* self);
ClutterStage* unity_shell_get_stage (UnityShell* self);
void unity_shell_show_unity (UnityShell* self);
void unity_shell_hide_unity (UnityShell* self);
gint unity_shell_get_indicators_width (UnityShell* self);
gint unity_shell_get_launcher_width_foobar (UnityShell* self);
gint unity_shell_get_panel_height_foobar (UnityShell* self);
void unity_shell_ensure_input_region (UnityShell* self);
void unity_shell_add_fullscreen_request (UnityShell* self, GObject* o);
gboolean unity_shell_remove_fullscreen_request (UnityShell* self, GObject* o);
void unity_shell_grab_keyboard (UnityShell* self, gboolean grab, guint32 timestamp);
void unity_shell_about_to_show_places (UnityShell* self);
void unity_shell_close_xids (UnityShell* self, GArray* xids);
void unity_shell_show_window (UnityShell* self, guint32 xid);
void unity_shell_expose_xids (UnityShell* self, GArray* xids);
void unity_shell_stop_expose (UnityShell* self);
void unity_shell_get_window_details (UnityShell* self, guint32 xid, gboolean* allows_resize, gboolean* is_maximised);
void unity_shell_do_window_action (UnityShell* self, guint32 xid, UnityWindowAction action);
gboolean unity_shell_get_menus_swallow_events (UnityShell* self);
gboolean unity_shell_get_super_key_active (UnityShell* self);
void unity_shell_set_super_key_active (UnityShell* self, gboolean value);



GType unity_shell_mode_get_type (void) {
	static volatile gsize unity_shell_mode_type_id__volatile = 0;
	if (g_once_init_enter (&unity_shell_mode_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_SHELL_MODE_MINIMIZED, "UNITY_SHELL_MODE_MINIMIZED", "minimized"}, {UNITY_SHELL_MODE_DASH, "UNITY_SHELL_MODE_DASH", "dash"}, {UNITY_SHELL_MODE_EXPOSE, "UNITY_SHELL_MODE_EXPOSE", "expose"}, {0, NULL, NULL}};
		GType unity_shell_mode_type_id;
		unity_shell_mode_type_id = g_enum_register_static ("UnityShellMode", values);
		g_once_init_leave (&unity_shell_mode_type_id__volatile, unity_shell_mode_type_id);
	}
	return unity_shell_mode_type_id__volatile;
}


GType unity_dnd_targets_get_type (void) {
	static volatile gsize unity_dnd_targets_type_id__volatile = 0;
	if (g_once_init_enter (&unity_dnd_targets_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_DND_TARGETS_TARGET_INT32, "UNITY_DND_TARGETS_TARGET_INT32", "target-int32"}, {UNITY_DND_TARGETS_TARGET_STRING, "UNITY_DND_TARGETS_TARGET_STRING", "target-string"}, {UNITY_DND_TARGETS_TARGET_URL, "UNITY_DND_TARGETS_TARGET_URL", "target-url"}, {UNITY_DND_TARGETS_TARGET_OTHER, "UNITY_DND_TARGETS_TARGET_OTHER", "target-other"}, {0, NULL, NULL}};
		GType unity_dnd_targets_type_id;
		unity_dnd_targets_type_id = g_enum_register_static ("Unitydnd_targets", values);
		g_once_init_leave (&unity_dnd_targets_type_id__volatile, unity_dnd_targets_type_id);
	}
	return unity_dnd_targets_type_id__volatile;
}


GType unity_window_action_get_type (void) {
	static volatile gsize unity_window_action_type_id__volatile = 0;
	if (g_once_init_enter (&unity_window_action_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_WINDOW_ACTION_CLOSE, "UNITY_WINDOW_ACTION_CLOSE", "close"}, {UNITY_WINDOW_ACTION_MINIMIZE, "UNITY_WINDOW_ACTION_MINIMIZE", "minimize"}, {UNITY_WINDOW_ACTION_MAXIMIZE, "UNITY_WINDOW_ACTION_MAXIMIZE", "maximize"}, {UNITY_WINDOW_ACTION_UNMAXIMIZE, "UNITY_WINDOW_ACTION_UNMAXIMIZE", "unmaximize"}, {0, NULL, NULL}};
		GType unity_window_action_type_id;
		unity_window_action_type_id = g_enum_register_static ("UnityWindowAction", values);
		g_once_init_leave (&unity_window_action_type_id__volatile, unity_window_action_type_id);
	}
	return unity_window_action_type_id__volatile;
}


guint32 unity_shell_get_current_time (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_current_time (self);
}


UnityShellMode unity_shell_get_mode (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_mode (self);
}


ClutterStage* unity_shell_get_stage (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_stage (self);
}


void unity_shell_show_unity (UnityShell* self) {
	UNITY_SHELL_GET_INTERFACE (self)->show_unity (self);
}


void unity_shell_hide_unity (UnityShell* self) {
	UNITY_SHELL_GET_INTERFACE (self)->hide_unity (self);
}


gint unity_shell_get_indicators_width (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_indicators_width (self);
}


gint unity_shell_get_launcher_width_foobar (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_launcher_width_foobar (self);
}


gint unity_shell_get_panel_height_foobar (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_panel_height_foobar (self);
}


void unity_shell_ensure_input_region (UnityShell* self) {
	UNITY_SHELL_GET_INTERFACE (self)->ensure_input_region (self);
}


void unity_shell_add_fullscreen_request (UnityShell* self, GObject* o) {
	UNITY_SHELL_GET_INTERFACE (self)->add_fullscreen_request (self, o);
}


gboolean unity_shell_remove_fullscreen_request (UnityShell* self, GObject* o) {
	return UNITY_SHELL_GET_INTERFACE (self)->remove_fullscreen_request (self, o);
}


void unity_shell_grab_keyboard (UnityShell* self, gboolean grab, guint32 timestamp) {
	UNITY_SHELL_GET_INTERFACE (self)->grab_keyboard (self, grab, timestamp);
}


void unity_shell_about_to_show_places (UnityShell* self) {
	UNITY_SHELL_GET_INTERFACE (self)->about_to_show_places (self);
}


void unity_shell_close_xids (UnityShell* self, GArray* xids) {
	UNITY_SHELL_GET_INTERFACE (self)->close_xids (self, xids);
}


void unity_shell_show_window (UnityShell* self, guint32 xid) {
	UNITY_SHELL_GET_INTERFACE (self)->show_window (self, xid);
}


void unity_shell_expose_xids (UnityShell* self, GArray* xids) {
	UNITY_SHELL_GET_INTERFACE (self)->expose_xids (self, xids);
}


void unity_shell_stop_expose (UnityShell* self) {
	UNITY_SHELL_GET_INTERFACE (self)->stop_expose (self);
}


void unity_shell_get_window_details (UnityShell* self, guint32 xid, gboolean* allows_resize, gboolean* is_maximised) {
	UNITY_SHELL_GET_INTERFACE (self)->get_window_details (self, xid, allows_resize, is_maximised);
}


void unity_shell_do_window_action (UnityShell* self, guint32 xid, UnityWindowAction action) {
	UNITY_SHELL_GET_INTERFACE (self)->do_window_action (self, xid, action);
}


gboolean unity_shell_get_menus_swallow_events (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_menus_swallow_events (self);
}


gboolean unity_shell_get_super_key_active (UnityShell* self) {
	return UNITY_SHELL_GET_INTERFACE (self)->get_super_key_active (self);
}


void unity_shell_set_super_key_active (UnityShell* self, gboolean value) {
	UNITY_SHELL_GET_INTERFACE (self)->set_super_key_active (self, value);
}


static void unity_shell_base_init (UnityShellIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_object_interface_install_property (iface, g_param_spec_boolean ("menus-swallow-events", "menus-swallow-events", "menus-swallow-events", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
		g_object_interface_install_property (iface, g_param_spec_boolean ("super-key-active", "super-key-active", "super-key-active", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
		g_signal_new ("need_new_icon_cache", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
		g_signal_new ("indicators_changed", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__INT, G_TYPE_NONE, 1, G_TYPE_INT);
		g_signal_new ("mode_changed", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__ENUM, G_TYPE_NONE, 1, UNITY_TYPE_SHELL_MODE);
		g_signal_new ("active_window_state_changed", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
		g_signal_new ("super_key_modifier_release", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__UINT, G_TYPE_NONE, 1, G_TYPE_UINT);
		g_signal_new ("super_key_modifier_press", UNITY_TYPE_SHELL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__UINT, G_TYPE_NONE, 1, G_TYPE_UINT);
	}
}


GType unity_shell_get_type (void) {
	static volatile gsize unity_shell_type_id__volatile = 0;
	if (g_once_init_enter (&unity_shell_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityShellIface), (GBaseInitFunc) unity_shell_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_shell_type_id;
		unity_shell_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityShell", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_shell_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&unity_shell_type_id__volatile, unity_shell_type_id);
	}
	return unity_shell_type_id__volatile;
}




