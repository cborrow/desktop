/* quicklist-controller.c generated by valac, the Vala compiler
 * generated from quicklist-controller.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>
#include <gee.h>
#include <unity.h>
#include <float.h>
#include <math.h>


#define UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER (unity_quicklauncher_quicklist_controller_get_type ())
#define UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityQuicklauncherQuicklistController))
#define UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityQuicklauncherQuicklistControllerClass))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityQuicklauncherQuicklistControllerClass))

typedef struct _UnityQuicklauncherQuicklistController UnityQuicklauncherQuicklistController;
typedef struct _UnityQuicklauncherQuicklistControllerClass UnityQuicklauncherQuicklistControllerClass;
typedef struct _UnityQuicklauncherQuicklistControllerPrivate UnityQuicklauncherQuicklistControllerPrivate;

#define UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM (unity_quicklauncher_models_shortcut_item_get_type ())
#define UNITY_QUICKLAUNCHER_MODELS_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM, UnityQuicklauncherModelsShortcutItem))
#define UNITY_QUICKLAUNCHER_MODELS_IS_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM))
#define UNITY_QUICKLAUNCHER_MODELS_SHORTCUT_ITEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM, UnityQuicklauncherModelsShortcutItemIface))

typedef struct _UnityQuicklauncherModelsShortcutItem UnityQuicklauncherModelsShortcutItem;
typedef struct _UnityQuicklauncherModelsShortcutItemIface UnityQuicklauncherModelsShortcutItemIface;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU (unity_quicklauncher_quicklist_menu_get_type ())
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU, UnityQuicklauncherQuicklistMenu))
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU, UnityQuicklauncherQuicklistMenuClass))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU))
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU, UnityQuicklauncherQuicklistMenuClass))

typedef struct _UnityQuicklauncherQuicklistMenu UnityQuicklauncherQuicklistMenu;
typedef struct _UnityQuicklauncherQuicklistMenuClass UnityQuicklauncherQuicklistMenuClass;

#define UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM (unity_quicklauncher_quicklist_menu_item_get_type ())
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityQuicklauncherQuicklistMenuItem))
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityQuicklauncherQuicklistMenuItemClass))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_QUICKLAUNCHER_IS_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_QUICKLAUNCHER_QUICKLIST_MENU_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityQuicklauncherQuicklistMenuItemClass))

typedef struct _UnityQuicklauncherQuicklistMenuItem UnityQuicklauncherQuicklistMenuItem;
typedef struct _UnityQuicklauncherQuicklistMenuItemClass UnityQuicklauncherQuicklistMenuItemClass;

struct _UnityQuicklauncherQuicklistController {
	GObject parent_instance;
	UnityQuicklauncherQuicklistControllerPrivate * priv;
	char* label;
	CtkMenu* menu;
	gboolean is_label;
};

struct _UnityQuicklauncherQuicklistControllerClass {
	GObjectClass parent_class;
};

struct _UnityQuicklauncherModelsShortcutItemIface {
	GTypeInterface parent_iface;
	char* (*get_name) (UnityQuicklauncherModelsShortcutItem* self);
	void (*activated) (UnityQuicklauncherModelsShortcutItem* self);
};

struct _UnityQuicklauncherQuicklistControllerPrivate {
	ClutterStage* stage;
	CtkActor* attached_widget;
	GeeLinkedList* prefix_actions;
	GeeLinkedList* append_actions;
	gboolean _hide_on_leave;
};


extern UnityQuicklauncherQuicklistController* unity_quicklauncher_active_menu;
UnityQuicklauncherQuicklistController* unity_quicklauncher_active_menu = NULL;
static gpointer unity_quicklauncher_quicklist_controller_parent_class = NULL;

GType unity_quicklauncher_quicklist_controller_get_type (void);
GType unity_quicklauncher_models_shortcut_item_get_type (void);
#define UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityQuicklauncherQuicklistControllerPrivate))
enum  {
	UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_DUMMY_PROPERTY,
	UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_HIDE_ON_LEAVE
};
static void unity_quicklauncher_quicklist_controller_on_unity_drag_start (UnityQuicklauncherQuicklistController* self, UnityDragModel* model);
static void _unity_quicklauncher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start (UnityDragController* _sender, UnityDragModel* model, gpointer self);
UnityQuicklauncherQuicklistController* unity_quicklauncher_quicklist_controller_new (const char* label, CtkActor* attached_to, ClutterStage* stage);
UnityQuicklauncherQuicklistController* unity_quicklauncher_quicklist_controller_construct (GType object_type, const char* label, CtkActor* attached_to, ClutterStage* stage);
void unity_quicklauncher_quicklist_controller_add_action (UnityQuicklauncherQuicklistController* self, UnityQuicklauncherModelsShortcutItem* shortcut, gboolean is_secondary);
UnityQuicklauncherQuicklistMenu* unity_quicklauncher_quicklist_menu_new (void);
UnityQuicklauncherQuicklistMenu* unity_quicklauncher_quicklist_menu_construct (GType object_type);
GType unity_quicklauncher_quicklist_menu_get_type (void);
UnityQuicklauncherQuicklistMenuItem* unity_quicklauncher_quicklist_menu_item_new (const char* label);
UnityQuicklauncherQuicklistMenuItem* unity_quicklauncher_quicklist_menu_item_construct (GType object_type, const char* label);
GType unity_quicklauncher_quicklist_menu_item_get_type (void);
void unity_quicklauncher_quicklist_controller_close_menu (UnityQuicklauncherQuicklistController* self);
static void _unity_quicklauncher_quicklist_controller_close_menu_ctk_menu_item_activated (CtkMenuItem* _sender, gpointer self);
static void unity_quicklauncher_quicklist_controller_build_menu (UnityQuicklauncherQuicklistController* self);
void unity_quicklauncher_quicklist_controller_show_label (UnityQuicklauncherQuicklistController* self);
void unity_quicklauncher_quicklist_controller_hide_label (UnityQuicklauncherQuicklistController* self);
char* unity_quicklauncher_models_shortcut_item_get_name (UnityQuicklauncherModelsShortcutItem* self);
void unity_quicklauncher_models_shortcut_item_activated (UnityQuicklauncherModelsShortcutItem* self);
static void _unity_quicklauncher_models_shortcut_item_activated_ctk_menu_item_activated (CtkMenuItem* _sender, gpointer self);
static void unity_quicklauncher_quicklist_controller_on_menu_close (UnityQuicklauncherQuicklistController* self);
static void _unity_quicklauncher_quicklist_controller_on_menu_close_ctk_menu_closed (CtkMenu* _sender, gpointer self);
void unity_quicklauncher_quicklist_controller_show_menu (UnityQuicklauncherQuicklistController* self);
gboolean unity_quicklauncher_quicklist_controller_get_hide_on_leave (UnityQuicklauncherQuicklistController* self);
void unity_quicklauncher_quicklist_controller_set_hide_on_leave (UnityQuicklauncherQuicklistController* self, gboolean value);
static GObject * unity_quicklauncher_quicklist_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_quicklauncher_quicklist_controller_finalize (GObject* obj);
static void unity_quicklauncher_quicklist_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_quicklauncher_quicklist_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 80 "quicklist-controller.vala"
static void _unity_quicklauncher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start (UnityDragController* _sender, UnityDragModel* model, gpointer self) {
#line 154 "quicklist-controller.c"
	unity_quicklauncher_quicklist_controller_on_unity_drag_start (self, model);
}


#line 49 "quicklist-controller.vala"
UnityQuicklauncherQuicklistController* unity_quicklauncher_quicklist_controller_construct (GType object_type, const char* label, CtkActor* attached_to, ClutterStage* stage) {
#line 161 "quicklist-controller.c"
	UnityQuicklauncherQuicklistController * self;
	char* _tmp0_;
	ClutterStage* _tmp1_;
	CtkMenu* _tmp2_;
	GeeLinkedList* _tmp3_;
	GeeLinkedList* _tmp4_;
	CtkActor* _tmp5_;
	UnityDragController* drag_controller;
#line 49 "quicklist-controller.vala"
	g_return_val_if_fail (label != NULL, NULL);
#line 49 "quicklist-controller.vala"
	g_return_val_if_fail (attached_to != NULL, NULL);
#line 49 "quicklist-controller.vala"
	g_return_val_if_fail (stage != NULL, NULL);
#line 176 "quicklist-controller.c"
	self = g_object_newv (object_type, 0, NULL);
#line 52 "quicklist-controller.vala"
	self->label = (_tmp0_ = g_strdup (label), _g_free0 (self->label), _tmp0_);
#line 53 "quicklist-controller.vala"
	self->priv->stage = (_tmp1_ = _g_object_ref0 (stage), _g_object_unref0 (self->priv->stage), _tmp1_);
#line 54 "quicklist-controller.vala"
	self->menu = (_tmp2_ = NULL, _g_object_unref0 (self->menu), _tmp2_);
#line 55 "quicklist-controller.vala"
	self->priv->prefix_actions = (_tmp3_ = gee_linked_list_new (UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->prefix_actions), _tmp3_);
#line 56 "quicklist-controller.vala"
	self->priv->append_actions = (_tmp4_ = gee_linked_list_new (UNITY_QUICKLAUNCHER_MODELS_TYPE_SHORTCUT_ITEM, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->append_actions), _tmp4_);
#line 57 "quicklist-controller.vala"
	self->priv->attached_widget = (_tmp5_ = _g_object_ref0 (attached_to), _g_object_unref0 (self->priv->attached_widget), _tmp5_);
#line 58 "quicklist-controller.vala"
	drag_controller = _g_object_ref0 (unity_drag_controller_get_default ());
#line 59 "quicklist-controller.vala"
	g_signal_connect_object (drag_controller, "drag-start", (GCallback) _unity_quicklauncher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start, self, 0);
#line 194 "quicklist-controller.c"
	_g_object_unref0 (drag_controller);
	return self;
}


#line 49 "quicklist-controller.vala"
UnityQuicklauncherQuicklistController* unity_quicklauncher_quicklist_controller_new (const char* label, CtkActor* attached_to, ClutterStage* stage) {
#line 49 "quicklist-controller.vala"
	return unity_quicklauncher_quicklist_controller_construct (UNITY_QUICKLAUNCHER_TYPE_QUICKLIST_CONTROLLER, label, attached_to, stage);
#line 204 "quicklist-controller.c"
}


#line 80 "quicklist-controller.vala"
static void unity_quicklauncher_quicklist_controller_on_unity_drag_start (UnityQuicklauncherQuicklistController* self, UnityDragModel* model) {
#line 210 "quicklist-controller.c"
	CtkMenu* menu;
	CtkMenu* _tmp1_;
#line 80 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 80 "quicklist-controller.vala"
	g_return_if_fail (model != NULL);
#line 82 "quicklist-controller.vala"
	if (unity_quicklauncher_active_menu == self) {
#line 219 "quicklist-controller.c"
		UnityQuicklauncherQuicklistController* _tmp0_;
#line 84 "quicklist-controller.vala"
		unity_quicklauncher_active_menu = (_tmp0_ = NULL, _g_object_unref0 (unity_quicklauncher_active_menu), _tmp0_);
#line 223 "quicklist-controller.c"
	}
#line 86 "quicklist-controller.vala"
	menu = _g_object_ref0 (self->menu);
#line 87 "quicklist-controller.vala"
	self->menu = (_tmp1_ = NULL, _g_object_unref0 (self->menu), _tmp1_);
#line 88 "quicklist-controller.vala"
	if (CTK_IS_MENU (menu)) {
#line 90 "quicklist-controller.vala"
		clutter_actor_destroy ((ClutterActor*) menu);
#line 233 "quicklist-controller.c"
	}
	_g_object_unref0 (menu);
}


#line 94 "quicklist-controller.vala"
void unity_quicklauncher_quicklist_controller_add_action (UnityQuicklauncherQuicklistController* self, UnityQuicklauncherModelsShortcutItem* shortcut, gboolean is_secondary) {
#line 94 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 94 "quicklist-controller.vala"
	g_return_if_fail (shortcut != NULL);
#line 99 "quicklist-controller.vala"
	if (is_secondary) {
#line 100 "quicklist-controller.vala"
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->prefix_actions, shortcut);
#line 249 "quicklist-controller.c"
	} else {
#line 102 "quicklist-controller.vala"
		gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->append_actions, shortcut);
#line 253 "quicklist-controller.c"
	}
}


#line 197 "quicklist-controller.vala"
static void _unity_quicklauncher_quicklist_controller_close_menu_ctk_menu_item_activated (CtkMenuItem* _sender, gpointer self) {
#line 260 "quicklist-controller.c"
	unity_quicklauncher_quicklist_controller_close_menu (self);
}


#line 105 "quicklist-controller.vala"
static void unity_quicklauncher_quicklist_controller_build_menu (UnityQuicklauncherQuicklistController* self) {
#line 267 "quicklist-controller.c"
	CtkMenu* _tmp1_;
	UnityQuicklauncherQuicklistMenu* _tmp0_;
	UnityQuicklauncherQuicklistMenuItem* menuitem;
	float x = 0.0F;
	float y = 0.0F;
#line 105 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 107 "quicklist-controller.vala"
	self->menu = (_tmp1_ = (_tmp0_ = g_object_ref_sink (unity_quicklauncher_quicklist_menu_new ()), CTK_IS_MENU (_tmp0_) ? ((CtkMenu*) _tmp0_) : NULL), _g_object_unref0 (self->menu), _tmp1_);
#line 108 "quicklist-controller.vala"
	ctk_menu_set_swallow_clicks (self->menu, unity_shell_get_menus_swallow_events (unity_global_shell));
#line 109 "quicklist-controller.vala"
	ctk_menu_set_detect_clicks (self->menu, FALSE);
#line 110 "quicklist-controller.vala"
	menuitem = g_object_ref_sink (unity_quicklauncher_quicklist_menu_item_new (self->label));
#line 111 "quicklist-controller.vala"
	g_signal_connect_object ((CtkMenuItem*) menuitem, "activated", (GCallback) _unity_quicklauncher_quicklist_controller_close_menu_ctk_menu_item_activated, self, 0);
#line 112 "quicklist-controller.vala"
	ctk_menu_append (self->menu, (ClutterActor*) menuitem, TRUE);
#line 113 "quicklist-controller.vala"
	ctk_menu_attach_to_actor (self->menu, self->priv->attached_widget);
#line 114 "quicklist-controller.vala"
	clutter_container_add_actor ((ClutterContainer*) self->priv->stage, (ClutterActor*) self->menu);
#line 118 "quicklist-controller.vala"
	clutter_actor_get_position ((ClutterActor*) self->menu, &x, &y);
#line 119 "quicklist-controller.vala"
	clutter_actor_set_position ((ClutterActor*) self->menu, x - ((float) ctk_em_to_pixel ((double) 1.5f)), y);
#line 295 "quicklist-controller.c"
	_g_object_unref0 (menuitem);
}


#line 122 "quicklist-controller.vala"
void unity_quicklauncher_quicklist_controller_show_label (UnityQuicklauncherQuicklistController* self) {
#line 122 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 125 "quicklist-controller.vala"
	if (unity_quicklauncher_active_menu != NULL) {
#line 126 "quicklist-controller.vala"
		return;
#line 308 "quicklist-controller.c"
	}
#line 128 "quicklist-controller.vala"
	unity_quicklauncher_quicklist_controller_build_menu (self);
#line 130 "quicklist-controller.vala"
	clutter_actor_show ((ClutterActor*) self->menu);
#line 131 "quicklist-controller.vala"
	self->is_label = TRUE;
#line 132 "quicklist-controller.vala"
	ctk_menu_set_detect_clicks (self->menu, FALSE);
#line 318 "quicklist-controller.c"
}


#line 135 "quicklist-controller.vala"
void unity_quicklauncher_quicklist_controller_hide_label (UnityQuicklauncherQuicklistController* self) {
#line 324 "quicklist-controller.c"
	gboolean _tmp0_ = FALSE;
#line 135 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 137 "quicklist-controller.vala"
	if (!self->is_label) {
#line 137 "quicklist-controller.vala"
		_tmp0_ = TRUE;
#line 332 "quicklist-controller.c"
	} else {
#line 137 "quicklist-controller.vala"
		_tmp0_ = self->menu == NULL;
#line 336 "quicklist-controller.c"
	}
#line 137 "quicklist-controller.vala"
	if (_tmp0_) {
#line 138 "quicklist-controller.vala"
		return;
#line 342 "quicklist-controller.c"
	}
#line 140 "quicklist-controller.vala"
	ctk_menu_set_detect_clicks (self->menu, FALSE);
#line 141 "quicklist-controller.vala"
	clutter_actor_hide ((ClutterActor*) self->menu);
#line 348 "quicklist-controller.c"
}


#line 57 "launcher-model.vala"
static void _unity_quicklauncher_models_shortcut_item_activated_ctk_menu_item_activated (CtkMenuItem* _sender, gpointer self) {
#line 354 "quicklist-controller.c"
	unity_quicklauncher_models_shortcut_item_activated (self);
}


#line 192 "quicklist-controller.vala"
static void _unity_quicklauncher_quicklist_controller_on_menu_close_ctk_menu_closed (CtkMenu* _sender, gpointer self) {
#line 361 "quicklist-controller.c"
	unity_quicklauncher_quicklist_controller_on_menu_close (self);
}


#line 144 "quicklist-controller.vala"
void unity_quicklauncher_quicklist_controller_show_menu (UnityQuicklauncherQuicklistController* self) {
#line 368 "quicklist-controller.c"
	UnityQuicklauncherQuicklistController* _tmp2_;
#line 144 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 146 "quicklist-controller.vala"
	if (unity_quicklauncher_active_menu != NULL) {
#line 374 "quicklist-controller.c"
		UnityQuicklauncherQuicklistController* _tmp0_;
#line 149 "quicklist-controller.vala"
		clutter_actor_destroy ((ClutterActor*) unity_quicklauncher_active_menu->menu);
#line 150 "quicklist-controller.vala"
		unity_quicklauncher_active_menu = (_tmp0_ = NULL, _g_object_unref0 (unity_quicklauncher_active_menu), _tmp0_);
#line 380 "quicklist-controller.c"
	}
#line 153 "quicklist-controller.vala"
	if (self->menu == NULL) {
#line 155 "quicklist-controller.vala"
		unity_quicklauncher_quicklist_controller_show_label (self);
#line 386 "quicklist-controller.c"
	}
#line 158 "quicklist-controller.vala"
	self->is_label = FALSE;
#line 390 "quicklist-controller.c"
	{
		GeeIterator* _shortcut_it;
		_shortcut_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->prefix_actions);
#line 160 "quicklist-controller.vala"
		while (TRUE) {
#line 396 "quicklist-controller.c"
			UnityQuicklauncherModelsShortcutItem* shortcut;
			char* label;
			UnityQuicklauncherQuicklistMenuItem* menuitem;
#line 160 "quicklist-controller.vala"
			if (!gee_iterator_next (_shortcut_it)) {
#line 160 "quicklist-controller.vala"
				break;
#line 404 "quicklist-controller.c"
			}
#line 160 "quicklist-controller.vala"
			shortcut = (UnityQuicklauncherModelsShortcutItem*) gee_iterator_get (_shortcut_it);
#line 162 "quicklist-controller.vala"
			label = unity_quicklauncher_models_shortcut_item_get_name (shortcut);
#line 163 "quicklist-controller.vala"
			menuitem = g_object_ref_sink (unity_quicklauncher_quicklist_menu_item_new (label));
#line 164 "quicklist-controller.vala"
			ctk_menu_prepend (self->menu, (ClutterActor*) menuitem, FALSE);
#line 165 "quicklist-controller.vala"
			g_signal_connect_object ((CtkMenuItem*) menuitem, "activated", (GCallback) _unity_quicklauncher_models_shortcut_item_activated_ctk_menu_item_activated, shortcut, 0);
#line 166 "quicklist-controller.vala"
			g_signal_connect_object ((CtkMenuItem*) menuitem, "activated", (GCallback) _unity_quicklauncher_quicklist_controller_close_menu_ctk_menu_item_activated, self, 0);
#line 418 "quicklist-controller.c"
			_g_object_unref0 (shortcut);
			_g_free0 (label);
			_g_object_unref0 (menuitem);
		}
		_g_object_unref0 (_shortcut_it);
	}
	{
		GeeIterator* _shortcut_it;
		_shortcut_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->append_actions);
#line 169 "quicklist-controller.vala"
		while (TRUE) {
#line 430 "quicklist-controller.c"
			UnityQuicklauncherModelsShortcutItem* shortcut;
			char* label;
			UnityQuicklauncherQuicklistMenuItem* menuitem;
#line 169 "quicklist-controller.vala"
			if (!gee_iterator_next (_shortcut_it)) {
#line 169 "quicklist-controller.vala"
				break;
#line 438 "quicklist-controller.c"
			}
#line 169 "quicklist-controller.vala"
			shortcut = (UnityQuicklauncherModelsShortcutItem*) gee_iterator_get (_shortcut_it);
#line 171 "quicklist-controller.vala"
			label = unity_quicklauncher_models_shortcut_item_get_name (shortcut);
#line 172 "quicklist-controller.vala"
			menuitem = g_object_ref_sink (unity_quicklauncher_quicklist_menu_item_new (label));
#line 173 "quicklist-controller.vala"
			ctk_menu_append (self->menu, (ClutterActor*) menuitem, FALSE);
#line 174 "quicklist-controller.vala"
			g_signal_connect_object ((CtkMenuItem*) menuitem, "activated", (GCallback) _unity_quicklauncher_models_shortcut_item_activated_ctk_menu_item_activated, shortcut, 0);
#line 175 "quicklist-controller.vala"
			g_signal_connect_object ((CtkMenuItem*) menuitem, "activated", (GCallback) _unity_quicklauncher_quicklist_controller_close_menu_ctk_menu_item_activated, self, 0);
#line 452 "quicklist-controller.c"
			_g_object_unref0 (shortcut);
			_g_free0 (label);
			_g_object_unref0 (menuitem);
		}
		_g_object_unref0 (_shortcut_it);
	}
#line 178 "quicklist-controller.vala"
	if (UNITY_QUICKLAUNCHER_IS_QUICKLIST_CONTROLLER (unity_quicklauncher_active_menu)) {
#line 461 "quicklist-controller.c"
		gboolean _tmp1_ = FALSE;
#line 180 "quicklist-controller.vala"
		if (unity_quicklauncher_active_menu->menu != self->menu) {
#line 181 "quicklist-controller.vala"
			_tmp1_ = CTK_IS_MENU (unity_quicklauncher_active_menu->menu);
#line 467 "quicklist-controller.c"
		} else {
#line 180 "quicklist-controller.vala"
			_tmp1_ = FALSE;
#line 471 "quicklist-controller.c"
		}
#line 180 "quicklist-controller.vala"
		if (_tmp1_) {
#line 182 "quicklist-controller.vala"
			clutter_actor_destroy ((ClutterActor*) unity_quicklauncher_active_menu->menu);
#line 477 "quicklist-controller.c"
		}
	}
#line 184 "quicklist-controller.vala"
	unity_quicklauncher_active_menu = (_tmp2_ = _g_object_ref0 (self), _g_object_unref0 (unity_quicklauncher_active_menu), _tmp2_);
#line 185 "quicklist-controller.vala"
	g_signal_connect_object (self->menu, "closed", (GCallback) _unity_quicklauncher_quicklist_controller_on_menu_close_ctk_menu_closed, self, 0);
#line 186 "quicklist-controller.vala"
	self->is_label = FALSE;
#line 187 "quicklist-controller.vala"
	ctk_menu_set_detect_clicks (self->menu, TRUE);
#line 189 "quicklist-controller.vala"
	unity_shell_ensure_input_region (unity_global_shell);
#line 490 "quicklist-controller.c"
}


#line 192 "quicklist-controller.vala"
static void unity_quicklauncher_quicklist_controller_on_menu_close (UnityQuicklauncherQuicklistController* self) {
#line 192 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 194 "quicklist-controller.vala"
	unity_quicklauncher_quicklist_controller_close_menu (self);
#line 500 "quicklist-controller.c"
}


#line 197 "quicklist-controller.vala"
void unity_quicklauncher_quicklist_controller_close_menu (UnityQuicklauncherQuicklistController* self) {
#line 197 "quicklist-controller.vala"
	g_return_if_fail (self != NULL);
#line 199 "quicklist-controller.vala"
	if (unity_quicklauncher_active_menu == self) {
#line 510 "quicklist-controller.c"
		UnityQuicklauncherQuicklistController* _tmp0_;
#line 201 "quicklist-controller.vala"
		unity_quicklauncher_active_menu = (_tmp0_ = NULL, _g_object_unref0 (unity_quicklauncher_active_menu), _tmp0_);
#line 514 "quicklist-controller.c"
	}
#line 204 "quicklist-controller.vala"
	if (self->menu == NULL) {
#line 206 "quicklist-controller.vala"
		return;
#line 520 "quicklist-controller.c"
	}
#line 208 "quicklist-controller.vala"
	clutter_actor_destroy ((ClutterActor*) self->menu);
#line 209 "quicklist-controller.vala"
	self->is_label = FALSE;
#line 211 "quicklist-controller.vala"
	unity_shell_ensure_input_region (unity_global_shell);
#line 528 "quicklist-controller.c"
}


gboolean unity_quicklauncher_quicklist_controller_get_hide_on_leave (UnityQuicklauncherQuicklistController* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_hide_on_leave;
#line 39 "quicklist-controller.vala"
	return result;
#line 538 "quicklist-controller.c"
}


void unity_quicklauncher_quicklist_controller_set_hide_on_leave (UnityQuicklauncherQuicklistController* self, gboolean value) {
	g_return_if_fail (self != NULL);
#line 41 "quicklist-controller.vala"
	self->priv->_hide_on_leave = value;
#line 42 "quicklist-controller.vala"
	if (CTK_IS_MENU (self->menu)) {
#line 44 "quicklist-controller.vala"
		ctk_menu_set_close_on_leave (self->menu, value);
#line 550 "quicklist-controller.c"
	}
	g_object_notify ((GObject *) self, "hide-on-leave");
}


static GObject * unity_quicklauncher_quicklist_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityQuicklauncherQuicklistController * self;
	parent_class = G_OBJECT_CLASS (unity_quicklauncher_quicklist_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER (obj);
	{
	}
	return obj;
}


static void unity_quicklauncher_quicklist_controller_class_init (UnityQuicklauncherQuicklistControllerClass * klass) {
	unity_quicklauncher_quicklist_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityQuicklauncherQuicklistControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_quicklauncher_quicklist_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_quicklauncher_quicklist_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_quicklauncher_quicklist_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_quicklauncher_quicklist_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_HIDE_ON_LEAVE, g_param_spec_boolean ("hide-on-leave", "hide-on-leave", "hide-on-leave", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_quicklauncher_quicklist_controller_instance_init (UnityQuicklauncherQuicklistController * self) {
	self->priv = UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_GET_PRIVATE (self);
	self->is_label = FALSE;
	self->priv->_hide_on_leave = FALSE;
}


static void unity_quicklauncher_quicklist_controller_finalize (GObject* obj) {
	UnityQuicklauncherQuicklistController * self;
	self = UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER (obj);
	{
		CtkMenu* menu;
		CtkMenu* _tmp1_;
#line 64 "quicklist-controller.vala"
		if (unity_quicklauncher_active_menu == self) {
#line 595 "quicklist-controller.c"
			UnityQuicklauncherQuicklistController* _tmp0_;
#line 66 "quicklist-controller.vala"
			unity_quicklauncher_active_menu = (_tmp0_ = NULL, _g_object_unref0 (unity_quicklauncher_active_menu), _tmp0_);
#line 599 "quicklist-controller.c"
		}
#line 68 "quicklist-controller.vala"
		menu = _g_object_ref0 (self->menu);
#line 69 "quicklist-controller.vala"
		self->menu = (_tmp1_ = NULL, _g_object_unref0 (self->menu), _tmp1_);
#line 70 "quicklist-controller.vala"
		if (CTK_IS_MENU (menu)) {
#line 72 "quicklist-controller.vala"
			clutter_actor_destroy ((ClutterActor*) menu);
#line 609 "quicklist-controller.c"
		}
		_g_object_unref0 (menu);
	}
	_g_free0 (self->label);
	_g_object_unref0 (self->menu);
	_g_object_unref0 (self->priv->stage);
	_g_object_unref0 (self->priv->attached_widget);
	_g_object_unref0 (self->priv->prefix_actions);
	_g_object_unref0 (self->priv->append_actions);
	G_OBJECT_CLASS (unity_quicklauncher_quicklist_controller_parent_class)->finalize (obj);
}


GType unity_quicklauncher_quicklist_controller_get_type (void) {
	static GType unity_quicklauncher_quicklist_controller_type_id = 0;
	if (unity_quicklauncher_quicklist_controller_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityQuicklauncherQuicklistControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_quicklauncher_quicklist_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityQuicklauncherQuicklistController), 0, (GInstanceInitFunc) unity_quicklauncher_quicklist_controller_instance_init, NULL };
		unity_quicklauncher_quicklist_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityQuicklauncherQuicklistController", &g_define_type_info, 0);
	}
	return unity_quicklauncher_quicklist_controller_type_id;
}


static void unity_quicklauncher_quicklist_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityQuicklauncherQuicklistController * self;
	self = UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER (object);
	switch (property_id) {
		case UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_HIDE_ON_LEAVE:
		g_value_set_boolean (value, unity_quicklauncher_quicklist_controller_get_hide_on_leave (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_quicklauncher_quicklist_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityQuicklauncherQuicklistController * self;
	self = UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER (object);
	switch (property_id) {
		case UNITY_QUICKLAUNCHER_QUICKLIST_CONTROLLER_HIDE_ON_LEAVE:
		unity_quicklauncher_quicklist_controller_set_hide_on_leave (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




