/* places-trash-controller.c generated by valac 0.9.8, the Vala compiler
 * generated from places-trash-controller.vala, do not modify */

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
#include <unity.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <float.h>
#include <math.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>
#include <gtk/gtk.h>
#include <clutter/clutter.h>
#include <glib/gi18n-lib.h>


#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER (unity_launcher_scroller_child_controller_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildController))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))

typedef struct _UnityLauncherScrollerChildController UnityLauncherScrollerChildController;
typedef struct _UnityLauncherScrollerChildControllerClass UnityLauncherScrollerChildControllerClass;
typedef struct _UnityLauncherScrollerChildControllerPrivate UnityLauncherScrollerChildControllerPrivate;

#define UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER (unity_launcher_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistController))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))

typedef struct _UnityLauncherQuicklistController UnityLauncherQuicklistController;
typedef struct _UnityLauncherQuicklistControllerClass UnityLauncherQuicklistControllerClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER_MENU_STATE (unity_launcher_scroller_child_controller_menu_state_get_type ())

#define UNITY_PLACES_TYPE_TRASH_CONTROLLER (unity_places_trash_controller_get_type ())
#define UNITY_PLACES_TRASH_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashController))
#define UNITY_PLACES_TRASH_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashControllerClass))
#define UNITY_PLACES_IS_TRASH_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER))
#define UNITY_PLACES_IS_TRASH_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_TRASH_CONTROLLER))
#define UNITY_PLACES_TRASH_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashControllerClass))

typedef struct _UnityPlacesTrashController UnityPlacesTrashController;
typedef struct _UnityPlacesTrashControllerClass UnityPlacesTrashControllerClass;
typedef struct _UnityPlacesTrashControllerPrivate UnityPlacesTrashControllerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER (unity_launcher_application_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistController))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))

typedef struct _UnityLauncherApplicationQuicklistController UnityLauncherApplicationQuicklistController;
typedef struct _UnityLauncherApplicationQuicklistControllerClass UnityLauncherApplicationQuicklistControllerClass;
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
typedef struct _UnityPlacesTrashControllerRecursivelyDeleteContentsData UnityPlacesTrashControllerRecursivelyDeleteContentsData;

#define UNITY_LAUNCHER_SCROLLER_CHILD_TYPE_GROUP_TYPE (unity_launcher_scroller_child_group_type_get_type ())

typedef void (*UnityLauncherScrollerChildControllermenu_cb) (DbusmenuMenuitem* menu, void* user_data);
typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU_CLOSE_WHEN_LEAVE
} UnityLauncherScrollerChildControllerMenuState;

struct _UnityLauncherScrollerChildController {
	GObject parent_instance;
	UnityLauncherScrollerChildControllerPrivate * priv;
	UnityLauncherScrollerChildControllerMenuState menu_state;
	guint32 last_press_time;
	gboolean button_down;
	float click_start_pos_x;
	float click_start_pos_y;
	gint drag_sensitivity;
};

struct _UnityLauncherScrollerChildControllerClass {
	GObjectClass parent_class;
	void (*get_menu_actions) (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
	void (*get_menu_navigation) (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
	void (*activate) (UnityLauncherScrollerChildController* self);
	UnityLauncherQuicklistController* (*get_menu_controller) (UnityLauncherScrollerChildController* self);
	gboolean (*can_drag) (UnityLauncherScrollerChildController* self);
};

struct _UnityPlacesTrashController {
	UnityLauncherScrollerChildController parent_instance;
	UnityPlacesTrashControllerPrivate * priv;
};

struct _UnityPlacesTrashControllerClass {
	UnityLauncherScrollerChildControllerClass parent_class;
};

struct _UnityPlacesTrashControllerPrivate {
	GFile* trash_dir;
	guint n_items;
};

struct _UnityPlacesTrashControllerRecursivelyDeleteContentsData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityPlacesTrashController* self;
	GFile* dir;
	GFileEnumerator* e;
	GList* files;
	GFile* child;
	char* _tmp0_;
	char* _tmp1_;
	GError * error_;
	GList* info_collection;
	GList* info_it;
	GFileInfo* info;
	char* _tmp2_;
	char* _tmp3_;
	GError * _error_;
	GError * _inner_error_;
};

typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_APPLICATION,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_PLACE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_DEVICE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_SYSTEM
} UnityLauncherScrollerChildGroupType;


static gpointer unity_places_trash_controller_parent_class = NULL;

GType unity_launcher_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_quicklist_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_child_controller_menu_state_get_type (void) G_GNUC_CONST;
GType unity_places_trash_controller_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_TRASH_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashControllerPrivate))
enum  {
	UNITY_PLACES_TRASH_CONTROLLER_DUMMY_PROPERTY
};
#define UNITY_PLACES_TRASH_CONTROLLER_ICON "/usr/share/unity/trash.png"
UnityPlacesTrashController* unity_places_trash_controller_new (void);
UnityPlacesTrashController* unity_places_trash_controller_construct (GType object_type);
UnityLauncherScrollerChild* unity_launcher_scroller_child_new (void);
UnityLauncherScrollerChild* unity_launcher_scroller_child_construct (GType object_type);
GType unity_launcher_scroller_child_get_type (void) G_GNUC_CONST;
static void unity_places_trash_controller_real_activate (UnityLauncherScrollerChildController* base);
static UnityLauncherQuicklistController* unity_places_trash_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_new (UnityLauncherScrollerChildController* scroller_child);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_construct (GType object_type, UnityLauncherScrollerChildController* scroller_child);
GType unity_launcher_application_quicklist_controller_get_type (void) G_GNUC_CONST;
static void unity_places_trash_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
static void unity_places_trash_controller_real_get_menu_navigation (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
static void _lambda74_ (UnityPlacesTrashController* self);
static void __lambda74__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
static void _lambda75_ (UnityPlacesTrashController* self);
static void unity_places_trash_controller_recursively_delete_contents (UnityPlacesTrashController* self, GFile* dir, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void unity_places_trash_controller_recursively_delete_contents_finish (UnityPlacesTrashController* self, GAsyncResult* _res_);
static void __lambda75__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
static void unity_places_trash_controller_recursively_delete_contents_data_free (gpointer _data);
static void unity_places_trash_controller_recursively_delete_contents_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean unity_places_trash_controller_recursively_delete_contents_co (UnityPlacesTrashControllerRecursivelyDeleteContentsData* data);
static void _g_list_free_g_object_unref (GList* self);
static gboolean unity_places_trash_controller_real_can_drag (UnityLauncherScrollerChildController* base);
void unity_launcher_scroller_child_controller_set_name (UnityLauncherScrollerChildController* self, const char* value);
void unity_launcher_scroller_child_controller_load_icon_from_icon_name (UnityLauncherScrollerChildController* self, const char* icon_name);
UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self);
GType unity_launcher_scroller_child_group_type_get_type (void) G_GNUC_CONST;
void unity_launcher_scroller_child_set_group_type (UnityLauncherScrollerChild* self, UnityLauncherScrollerChildGroupType value);
static GObject * unity_places_trash_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_trash_controller_finalize (GObject* obj);



UnityPlacesTrashController* unity_places_trash_controller_construct (GType object_type) {
	UnityPlacesTrashController * self;
	UnityLauncherScrollerChild* _tmp0_;
	self = (UnityPlacesTrashController*) g_object_new (object_type, "child", _tmp0_ = g_object_ref_sink (g_object_ref_sink (unity_launcher_scroller_child_new ())), NULL);
	_g_object_unref0 (_tmp0_);
	return self;
}


UnityPlacesTrashController* unity_places_trash_controller_new (void) {
	return unity_places_trash_controller_construct (UNITY_PLACES_TYPE_TRASH_CONTROLLER);
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void unity_places_trash_controller_real_activate (UnityLauncherScrollerChildController* base) {
	UnityPlacesTrashController * self;
	GError * _inner_error_ = NULL;
	self = (UnityPlacesTrashController*) base;
	{
		gtk_show_uri (NULL, "trash://", clutter_get_current_event_time (), &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch37_g_error;
		}
	}
	goto __finally37;
	__catch37_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("places-trash-controller.vala:56: %s", _tmp0_ = g_strconcat ("Unable to show Trash: ", string_to_string (e->message), NULL));
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally37:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static UnityLauncherQuicklistController* unity_places_trash_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base) {
	UnityPlacesTrashController * self;
	UnityLauncherQuicklistController* result = NULL;
	self = (UnityPlacesTrashController*) base;
	result = (UnityLauncherQuicklistController*) unity_launcher_application_quicklist_controller_new ((UnityLauncherScrollerChildController*) self);
	return result;
}


static void unity_places_trash_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target) {
	UnityPlacesTrashController * self;
	DbusmenuMenuitem* root;
	GError * _inner_error_ = NULL;
	self = (UnityPlacesTrashController*) base;
	self->priv->n_items = (guint) 0;
	root = dbusmenu_menuitem_new ();
	dbusmenu_menuitem_set_root (root, TRUE);
	{
		GFileEnumerator* e;
		GFileInfo* info;
		e = g_file_enumerate_children (self->priv->trash_dir, G_FILE_ATTRIBUTE_STANDARD_NAME, 0, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch38_g_error;
		}
		info = NULL;
		while (TRUE) {
			GFileInfo* _tmp0_;
			GFileInfo* _tmp1_;
			_tmp0_ = g_file_enumerator_next_file (e, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (info);
				_g_object_unref0 (e);
				goto __catch38_g_error;
			}
			if (!((info = (_tmp1_ = _tmp0_, _g_object_unref0 (info), _tmp1_)) != NULL)) {
				break;
			}
			self->priv->n_items++;
		}
		_g_object_unref0 (info);
		_g_object_unref0 (e);
	}
	goto __finally38;
	__catch38_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("places-trash-controller.vala:79: Unable to enumerate trash: %s", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally38:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (root);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (self->priv->n_items != 0) {
		DbusmenuMenuitem* item;
		char* label;
		DbusmenuMenuitem* _tmp2_;
		char* _tmp3_;
		item = NULL;
		label = g_strdup (ngettext ("%d item", "%d items", (gulong) self->priv->n_items));
		item = (_tmp2_ = dbusmenu_menuitem_new (), _g_object_unref0 (item), _tmp2_);
		dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, _tmp3_ = g_strdup_printf (label, self->priv->n_items));
		_g_free0 (_tmp3_);
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, FALSE);
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
		dbusmenu_menuitem_child_append (root, item);
		_g_free0 (label);
		_g_object_unref0 (item);
	}
	callback (root, callback_target);
	_g_object_unref0 (root);
}


static void _lambda74_ (UnityPlacesTrashController* self) {
	GError * _inner_error_ = NULL;
	{
		gtk_show_uri (NULL, "trash://", clutter_get_current_event_time (), &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch39_g_error;
		}
	}
	goto __finally39;
	__catch39_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("places-trash-controller.vala:114: %s", _tmp0_ = g_strconcat ("Unable to show Trash: ", string_to_string (e->message), NULL));
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally39:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void __lambda74__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	_lambda74_ (self);
}


static void _lambda75_ (UnityPlacesTrashController* self) {
	unity_places_trash_controller_recursively_delete_contents (self, self->priv->trash_dir, NULL, NULL);
}


static void __lambda75__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	_lambda75_ (self);
}


static void unity_places_trash_controller_real_get_menu_navigation (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target) {
	UnityPlacesTrashController * self;
	DbusmenuMenuitem* root;
	DbusmenuMenuitem* item;
	DbusmenuMenuitem* _tmp0_;
	self = (UnityPlacesTrashController*) base;
	root = dbusmenu_menuitem_new ();
	dbusmenu_menuitem_set_root (root, TRUE);
	item = NULL;
	item = (_tmp0_ = dbusmenu_menuitem_new (), _g_object_unref0 (item), _tmp0_);
	dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, "Open");
	dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
	dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
	dbusmenu_menuitem_child_append (root, item);
	g_signal_connect_object (item, "item-activated", (GCallback) __lambda74__dbusmenu_menuitem_item_activated, self, 0);
	if (self->priv->n_items != 0) {
		DbusmenuMenuitem* _tmp1_;
		item = (_tmp1_ = dbusmenu_menuitem_new (), _g_object_unref0 (item), _tmp1_);
		dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, "Empty Trash");
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
		dbusmenu_menuitem_child_append (root, item);
		g_signal_connect_object (item, "item-activated", (GCallback) __lambda75__dbusmenu_menuitem_item_activated, self, 0);
	}
	callback (root, callback_target);
	_g_object_unref0 (item);
	_g_object_unref0 (root);
}


static void unity_places_trash_controller_recursively_delete_contents_data_free (gpointer _data) {
	UnityPlacesTrashControllerRecursivelyDeleteContentsData* data;
	data = _data;
	_g_object_unref0 (data->dir);
	g_object_unref (data->self);
	g_slice_free (UnityPlacesTrashControllerRecursivelyDeleteContentsData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_places_trash_controller_recursively_delete_contents (UnityPlacesTrashController* self, GFile* dir, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityPlacesTrashControllerRecursivelyDeleteContentsData* _data_;
	_data_ = g_slice_new0 (UnityPlacesTrashControllerRecursivelyDeleteContentsData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_places_trash_controller_recursively_delete_contents);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_places_trash_controller_recursively_delete_contents_data_free);
	_data_->self = g_object_ref (self);
	_data_->dir = _g_object_ref0 (dir);
	unity_places_trash_controller_recursively_delete_contents_co (_data_);
}


static void unity_places_trash_controller_recursively_delete_contents_finish (UnityPlacesTrashController* self, GAsyncResult* _res_) {
	UnityPlacesTrashControllerRecursivelyDeleteContentsData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_places_trash_controller_recursively_delete_contents_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityPlacesTrashControllerRecursivelyDeleteContentsData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_places_trash_controller_recursively_delete_contents_co (data);
}


static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


static gboolean unity_places_trash_controller_recursively_delete_contents_co (UnityPlacesTrashControllerRecursivelyDeleteContentsData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 6:
		goto _state_6;
		case 7:
		goto _state_7;
		case 8:
		goto _state_8;
	}
	_state_0:
	{
		data->_state_ = 6;
		g_file_enumerate_children_async (data->dir, G_FILE_ATTRIBUTE_STANDARD_NAME "," G_FILE_ATTRIBUTE_STANDARD_TYPE, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, G_PRIORITY_DEFAULT, NULL, unity_places_trash_controller_recursively_delete_contents_ready, data);
		return FALSE;
		_state_6:
		data->e = g_file_enumerate_children_finish (data->dir, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch40_g_error;
		}
		while (TRUE) {
			data->_state_ = 7;
			g_file_enumerator_next_files_async (data->e, 10, G_PRIORITY_DEFAULT, NULL, unity_places_trash_controller_recursively_delete_contents_ready, data);
			return FALSE;
			_state_7:
			data->files = g_file_enumerator_next_files_finish (data->e, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				_g_object_unref0 (data->e);
				goto __catch40_g_error;
			}
			if (data->files == NULL) {
				__g_list_free_g_object_unref0 (data->files);
				break;
			}
			{
				data->info_collection = data->files;
				for (data->info_it = data->info_collection; data->info_it != NULL; data->info_it = data->info_it->next) {
					data->info = _g_object_ref0 ((GFileInfo*) data->info_it->data);
					{
						data->child = g_file_get_child (data->dir, g_file_info_get_name (data->info));
						if (g_file_info_get_file_type (data->info) == G_FILE_TYPE_DIRECTORY) {
							data->_state_ = 8;
							unity_places_trash_controller_recursively_delete_contents (data->self, data->child, unity_places_trash_controller_recursively_delete_contents_ready, data);
							return FALSE;
							_state_8:
							unity_places_trash_controller_recursively_delete_contents_finish (data->self, data->_res_);
						}
						{
							g_file_delete (data->child, NULL, &data->_inner_error_);
							if (data->_inner_error_ != NULL) {
								goto __catch41_g_error;
							}
						}
						goto __finally41;
						__catch41_g_error:
						{
							data->error_ = data->_inner_error_;
							data->_inner_error_ = NULL;
							{
								g_warning ("places-trash-controller.vala:181: %s", data->_tmp1_ = g_strconcat ("Unable to delete file '", string_to_string (data->_tmp0_ = g_file_get_basename (data->child)), ": ", string_to_string (data->error_->message), NULL));
								_g_free0 (data->_tmp1_);
								_g_free0 (data->_tmp0_);
								_g_error_free0 (data->error_);
							}
						}
						__finally41:
						if (data->_inner_error_ != NULL) {
							_g_object_unref0 (data->child);
							_g_object_unref0 (data->info);
							__g_list_free_g_object_unref0 (data->files);
							_g_object_unref0 (data->e);
							goto __catch40_g_error;
						}
						_g_object_unref0 (data->child);
						_g_object_unref0 (data->info);
					}
				}
			}
			__g_list_free_g_object_unref0 (data->files);
		}
		_g_object_unref0 (data->e);
	}
	goto __finally40;
	__catch40_g_error:
	{
		data->_error_ = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_warning (data->_tmp3_ = g_strconcat ("Unable to read place files from directory '", string_to_string (data->_tmp2_ = g_file_get_basename (data->dir)), "': %s", NULL), data->_error_->message);
			_g_free0 (data->_tmp3_);
			_g_free0 (data->_tmp2_);
			_g_error_free0 (data->_error_);
		}
	}
	__finally40:
	if (data->_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static gboolean unity_places_trash_controller_real_can_drag (UnityLauncherScrollerChildController* base) {
	UnityPlacesTrashController * self;
	gboolean result = FALSE;
	self = (UnityPlacesTrashController*) base;
	result = TRUE;
	return result;
}


static GObject * unity_places_trash_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesTrashController * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_places_trash_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_TRASH_CONTROLLER (obj);
	_inner_error_ = NULL;
	{
		unity_launcher_scroller_child_controller_set_name ((UnityLauncherScrollerChildController*) self, _ ("Trash"));
		unity_launcher_scroller_child_controller_load_icon_from_icon_name ((UnityLauncherScrollerChildController*) self, UNITY_PLACES_TRASH_CONTROLLER_ICON);
		{
			GFile* _tmp0_;
			self->priv->trash_dir = (_tmp0_ = g_file_new_for_uri ("trash://"), _g_object_unref0 (self->priv->trash_dir), _tmp0_);
		}
		goto __finally42;
		__catch42_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp1_;
				g_warning ("places-trash-controller.vala:45: %s", _tmp1_ = g_strconcat ("Unable to monitor trash: ", string_to_string (e->message), NULL));
				_g_free0 (_tmp1_);
				_g_error_free0 (e);
			}
		}
		__finally42:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		unity_launcher_scroller_child_set_group_type (unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_SYSTEM);
	}
	return obj;
}


static void unity_places_trash_controller_class_init (UnityPlacesTrashControllerClass * klass) {
	unity_places_trash_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesTrashControllerPrivate));
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->activate = unity_places_trash_controller_real_activate;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_controller = unity_places_trash_controller_real_get_menu_controller;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_actions = unity_places_trash_controller_real_get_menu_actions;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_navigation = unity_places_trash_controller_real_get_menu_navigation;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->can_drag = unity_places_trash_controller_real_can_drag;
	G_OBJECT_CLASS (klass)->constructor = unity_places_trash_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_trash_controller_finalize;
}


static void unity_places_trash_controller_instance_init (UnityPlacesTrashController * self) {
	self->priv = UNITY_PLACES_TRASH_CONTROLLER_GET_PRIVATE (self);
	self->priv->n_items = (guint) 0;
}


static void unity_places_trash_controller_finalize (GObject* obj) {
	UnityPlacesTrashController * self;
	self = UNITY_PLACES_TRASH_CONTROLLER (obj);
	_g_object_unref0 (self->priv->trash_dir);
	G_OBJECT_CLASS (unity_places_trash_controller_parent_class)->finalize (obj);
}


GType unity_places_trash_controller_get_type (void) {
	static volatile gsize unity_places_trash_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_trash_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesTrashControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_trash_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesTrashController), 0, (GInstanceInitFunc) unity_places_trash_controller_instance_init, NULL };
		GType unity_places_trash_controller_type_id;
		unity_places_trash_controller_type_id = g_type_register_static (UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, "UnityPlacesTrashController", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_trash_controller_type_id__volatile, unity_places_trash_controller_type_id);
	}
	return unity_places_trash_controller_type_id__volatile;
}




