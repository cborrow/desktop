/* places-controller.c generated by valac, the Vala compiler
 * generated from places-controller.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <unity.h>
#include <gee.h>
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <dee.h>
#include <clutter/clutter.h>


#define UNITY_PLACES_TYPE_CONTROLLER (unity_places_controller_get_type ())
#define UNITY_PLACES_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesController))
#define UNITY_PLACES_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))
#define UNITY_PLACES_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))

typedef struct _UnityPlacesController UnityPlacesController;
typedef struct _UnityPlacesControllerClass UnityPlacesControllerClass;
typedef struct _UnityPlacesControllerPrivate UnityPlacesControllerPrivate;

#define UNITY_PLACES_TYPE_PLACE_MODEL (unity_places_place_model_get_type ())
#define UNITY_PLACES_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModel))
#define UNITY_PLACES_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))
#define UNITY_PLACES_IS_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_IS_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_PLACE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))

typedef struct _UnityPlacesPlaceModel UnityPlacesPlaceModel;
typedef struct _UnityPlacesPlaceModelClass UnityPlacesPlaceModelClass;

#define UNITY_PLACES_TYPE_VOLUME_CONTROLLER (unity_places_volume_controller_get_type ())
#define UNITY_PLACES_VOLUME_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VOLUME_CONTROLLER, UnityPlacesVolumeController))
#define UNITY_PLACES_VOLUME_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VOLUME_CONTROLLER, UnityPlacesVolumeControllerClass))
#define UNITY_PLACES_IS_VOLUME_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VOLUME_CONTROLLER))
#define UNITY_PLACES_IS_VOLUME_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VOLUME_CONTROLLER))
#define UNITY_PLACES_VOLUME_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VOLUME_CONTROLLER, UnityPlacesVolumeControllerClass))

typedef struct _UnityPlacesVolumeController UnityPlacesVolumeController;
typedef struct _UnityPlacesVolumeControllerClass UnityPlacesVolumeControllerClass;

#define UNITY_PLACES_TYPE_VIEW (unity_places_view_get_type ())
#define UNITY_PLACES_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesView))
#define UNITY_PLACES_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))
#define UNITY_PLACES_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))

typedef struct _UnityPlacesView UnityPlacesView;
typedef struct _UnityPlacesViewClass UnityPlacesViewClass;
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

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

#define UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS (unity_places_place_entry_dbus_get_type ())
#define UNITY_PLACES_PLACE_ENTRY_DBUS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS, UnityPlacesPlaceEntryDbus))
#define UNITY_PLACES_PLACE_ENTRY_DBUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS, UnityPlacesPlaceEntryDbusClass))
#define UNITY_PLACES_IS_PLACE_ENTRY_DBUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS))
#define UNITY_PLACES_IS_PLACE_ENTRY_DBUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS))
#define UNITY_PLACES_PLACE_ENTRY_DBUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_DBUS, UnityPlacesPlaceEntryDbusClass))

typedef struct _UnityPlacesPlaceEntryDbus UnityPlacesPlaceEntryDbus;
typedef struct _UnityPlacesPlaceEntryDbusClass UnityPlacesPlaceEntryDbusClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_MODEL (unity_launcher_scroller_model_get_type ())
#define UNITY_LAUNCHER_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModel))
#define UNITY_LAUNCHER_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_SCROLLER_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))

typedef struct _UnityLauncherScrollerModel UnityLauncherScrollerModel;
typedef struct _UnityLauncherScrollerModelClass UnityLauncherScrollerModelClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER (unity_launcher_scroller_child_controller_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildController))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))

typedef struct _UnityLauncherScrollerChildController UnityLauncherScrollerChildController;
typedef struct _UnityLauncherScrollerChildControllerClass UnityLauncherScrollerChildControllerClass;

#define UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (unity_places_place_entry_scroller_child_controller_get_type ())
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildController))
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildControllerClass))
#define UNITY_PLACES_IS_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER))
#define UNITY_PLACES_IS_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER))
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildControllerClass))

typedef struct _UnityPlacesPlaceEntryScrollerChildController UnityPlacesPlaceEntryScrollerChildController;
typedef struct _UnityPlacesPlaceEntryScrollerChildControllerClass UnityPlacesPlaceEntryScrollerChildControllerClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;

#define UNITY_PLACES_TYPE_PLACE_FILE_MODEL (unity_places_place_file_model_get_type ())
#define UNITY_PLACES_PLACE_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModel))
#define UNITY_PLACES_PLACE_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModelClass))
#define UNITY_PLACES_IS_PLACE_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL))
#define UNITY_PLACES_IS_PLACE_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_FILE_MODEL))
#define UNITY_PLACES_PLACE_FILE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModelClass))

typedef struct _UnityPlacesPlaceFileModel UnityPlacesPlaceFileModel;
typedef struct _UnityPlacesPlaceFileModelClass UnityPlacesPlaceFileModelClass;

#define UNITY_PLACES_TYPE_TRASH_CONTROLLER (unity_places_trash_controller_get_type ())
#define UNITY_PLACES_TRASH_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashController))
#define UNITY_PLACES_TRASH_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashControllerClass))
#define UNITY_PLACES_IS_TRASH_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER))
#define UNITY_PLACES_IS_TRASH_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_TRASH_CONTROLLER))
#define UNITY_PLACES_TRASH_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_TRASH_CONTROLLER, UnityPlacesTrashControllerClass))

typedef struct _UnityPlacesTrashController UnityPlacesTrashController;
typedef struct _UnityPlacesTrashControllerClass UnityPlacesTrashControllerClass;

struct _UnityPlacesController {
	GObject parent_instance;
	UnityPlacesControllerPrivate * priv;
};

struct _UnityPlacesControllerClass {
	GObjectClass parent_class;
};

struct _UnityPlacesControllerPrivate {
	UnityShell* _shell;
	UnityPlacesPlaceModel* _model;
	UnityPlacesVolumeController* _volumes;
	UnityPlacesView* view;
};

struct _UnityPlacesPlaceEntryIface {
	GTypeInterface parent_iface;
	void (*connect) (UnityPlacesPlaceEntry* self);
	void (*set_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	void (*set_active_section) (UnityPlacesPlaceEntry* self, guint section_id);
	void (*set_global_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	const char* (*get_name) (UnityPlacesPlaceEntry* self);
	void (*set_name) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_icon) (UnityPlacesPlaceEntry* self);
	void (*set_icon) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_description) (UnityPlacesPlaceEntry* self);
	void (*set_description) (UnityPlacesPlaceEntry* self, const char* value);
	guint (*get_position) (UnityPlacesPlaceEntry* self);
	void (*set_position) (UnityPlacesPlaceEntry* self, guint value);
	char** (*get_mimetypes) (UnityPlacesPlaceEntry* self, int* result_length1);
	void (*set_mimetypes) (UnityPlacesPlaceEntry* self, char** value, int value_length1);
	gboolean (*get_sensitive) (UnityPlacesPlaceEntry* self);
	void (*set_sensitive) (UnityPlacesPlaceEntry* self, gboolean value);
	GeeHashMap* (*get_hints) (UnityPlacesPlaceEntry* self);
	void (*set_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	gboolean (*get_online) (UnityPlacesPlaceEntry* self);
	void (*set_online) (UnityPlacesPlaceEntry* self, gboolean value);
	gboolean (*get_active) (UnityPlacesPlaceEntry* self);
	void (*set_active) (UnityPlacesPlaceEntry* self, gboolean value);
	DeeModel* (*get_sections_model) (UnityPlacesPlaceEntry* self);
	void (*set_sections_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	const char* (*get_entry_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_entry_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_entry_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_entry_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	const char* (*get_global_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_global_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_global_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_global_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	UnityPlacesPlace* (*get_parent) (UnityPlacesPlaceEntry* self);
	void (*set_parent) (UnityPlacesPlaceEntry* self, UnityPlacesPlace* value);
};


static gpointer unity_places_controller_parent_class = NULL;

GType unity_places_controller_get_type (void) G_GNUC_CONST;
GType unity_places_place_model_get_type (void) G_GNUC_CONST;
GType unity_places_volume_controller_get_type (void) G_GNUC_CONST;
GType unity_places_view_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerPrivate))
enum  {
	UNITY_PLACES_CONTROLLER_DUMMY_PROPERTY,
	UNITY_PLACES_CONTROLLER_SHELL,
	UNITY_PLACES_CONTROLLER_MODEL,
	UNITY_PLACES_CONTROLLER_VOLUMES
};
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void) G_GNUC_CONST;
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
UnityPlacesController* unity_places_controller_new (UnityShell* shell);
UnityPlacesController* unity_places_controller_construct (GType object_type, UnityShell* shell);
UnityPlacesView* unity_places_controller_get_view (UnityPlacesController* self);
UnityPlacesPlaceModel* unity_places_controller_get_model (UnityPlacesController* self);
GType unity_places_place_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
GeeArrayList* unity_places_place_get_entries (UnityPlacesPlace* self);
const char* unity_places_place_entry_get_name (UnityPlacesPlaceEntry* self);
void unity_places_view_on_entry_view_activated (UnityPlacesView* self, UnityPlacesPlaceEntry* entry, guint section_id);
void unity_places_controller_activate_entry (UnityPlacesController* self, const char* entry_name, gint section_id);
GType unity_places_place_entry_dbus_get_type (void) G_GNUC_CONST;
const char* unity_places_place_entry_dbus_get_dbus_path (UnityPlacesPlaceEntryDbus* self);
void unity_places_controller_activate_entry_by_dbus_path (UnityPlacesController* self, const char* entry_path, gint section_id);
GeeArrayList* unity_testing_object_registry_lookup (UnityTestingObjectRegistry* self, const char* name);
GType unity_launcher_scroller_model_get_type (void) G_GNUC_CONST;
UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_new (UnityPlacesPlaceEntry* entry);
UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_construct (GType object_type, UnityPlacesPlaceEntry* entry);
GType unity_launcher_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_child_get_type (void) G_GNUC_CONST;
void unity_launcher_scroller_model_add (UnityLauncherScrollerModel* self, UnityLauncherScrollerChild* child);
UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self);
static void unity_places_controller_on_entry_clicked (UnityPlacesController* self, UnityPlacesPlaceEntryScrollerChildController* cont, guint section_id);
static void _unity_places_controller_on_entry_clicked_unity_places_place_entry_scroller_child_controller_clicked (UnityPlacesPlaceEntryScrollerChildController* _sender, guint section_id, gpointer self);
static void unity_places_controller_on_entry_added (UnityPlacesController* self, UnityPlacesPlaceEntry* entry);
UnityShell* unity_places_controller_get_shell (UnityPlacesController* self);
UnityPlacesPlaceEntry* unity_places_place_entry_scroller_child_controller_get_entry (UnityPlacesPlaceEntryScrollerChildController* self);
static void unity_places_controller_set_shell (UnityPlacesController* self, UnityShell* value);
void unity_places_controller_set_model (UnityPlacesController* self, UnityPlacesPlaceModel* value);
UnityPlacesVolumeController* unity_places_controller_get_volumes (UnityPlacesController* self);
void unity_places_controller_set_volumes (UnityPlacesController* self, UnityPlacesVolumeController* value);
UnityPlacesPlaceFileModel* unity_places_place_file_model_new (void);
UnityPlacesPlaceFileModel* unity_places_place_file_model_construct (GType object_type);
GType unity_places_place_file_model_get_type (void) G_GNUC_CONST;
static void _lambda69_ (UnityPlacesPlace* place, UnityPlacesController* self);
static void __lambda69__unity_places_place_model_place_added (UnityPlacesPlaceModel* _sender, UnityPlacesPlace* place, gpointer self);
UnityPlacesVolumeController* unity_places_volume_controller_new (void);
UnityPlacesVolumeController* unity_places_volume_controller_construct (GType object_type);
UnityPlacesTrashController* unity_places_trash_controller_new (void);
UnityPlacesTrashController* unity_places_trash_controller_construct (GType object_type);
GType unity_places_trash_controller_get_type (void) G_GNUC_CONST;
UnityPlacesView* unity_places_view_new (UnityShell* shell, UnityPlacesPlaceModel* model);
UnityPlacesView* unity_places_view_construct (GType object_type, UnityShell* shell, UnityPlacesPlaceModel* model);
static GObject * unity_places_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_controller_finalize (GObject* obj);
static void unity_places_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



UnityPlacesController* unity_places_controller_construct (GType object_type, UnityShell* shell) {
	UnityPlacesController * self;
	UnityTestingObjectRegistry* _tmp0_;
	g_return_val_if_fail (shell != NULL, NULL);
	self = (UnityPlacesController*) g_object_new (object_type, "shell", shell, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "UnityPlacesController", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityPlacesController* unity_places_controller_new (UnityShell* shell) {
	return unity_places_controller_construct (UNITY_PLACES_TYPE_CONTROLLER, shell);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


UnityPlacesView* unity_places_controller_get_view (UnityPlacesController* self) {
	UnityPlacesView* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 (self->priv->view);
	return result;
}


void unity_places_controller_activate_entry (UnityPlacesController* self, const char* entry_name, gint section_id) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry_name != NULL);
	{
		GeeIterator* _place_it;
		_place_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->_model);
		while (TRUE) {
			UnityPlacesPlace* place;
			if (!gee_iterator_next (_place_it)) {
				break;
			}
			place = _g_object_ref0 ((UnityPlacesPlace*) gee_iterator_get (_place_it));
			{
				GeeIterator* _entry_it;
				_entry_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) unity_places_place_get_entries (place));
				while (TRUE) {
					UnityPlacesPlaceEntry* entry;
					if (!gee_iterator_next (_entry_it)) {
						break;
					}
					entry = (UnityPlacesPlaceEntry*) gee_iterator_get (_entry_it);
					if (_vala_strcmp0 (unity_places_place_entry_get_name (entry), entry_name) == 0) {
						unity_places_view_on_entry_view_activated (self->priv->view, entry, (guint) section_id);
						_g_object_unref0 (entry);
						break;
					}
					_g_object_unref0 (entry);
				}
				_g_object_unref0 (_entry_it);
			}
			_g_object_unref0 (place);
		}
		_g_object_unref0 (_place_it);
	}
}


void unity_places_controller_activate_entry_by_dbus_path (UnityPlacesController* self, const char* entry_path, gint section_id) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry_path != NULL);
	{
		GeeIterator* _place_it;
		_place_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->_model);
		while (TRUE) {
			UnityPlacesPlace* place;
			if (!gee_iterator_next (_place_it)) {
				break;
			}
			place = _g_object_ref0 ((UnityPlacesPlace*) gee_iterator_get (_place_it));
			{
				GeeIterator* _ent_it;
				_ent_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) unity_places_place_get_entries (place));
				while (TRUE) {
					UnityPlacesPlaceEntry* ent;
					if (!gee_iterator_next (_ent_it)) {
						break;
					}
					ent = (UnityPlacesPlaceEntry*) gee_iterator_get (_ent_it);
					if (UNITY_PLACES_IS_PLACE_ENTRY_DBUS (ent)) {
						UnityPlacesPlaceEntry* _tmp0_;
						UnityPlacesPlaceEntryDbus* entry;
						entry = (_tmp0_ = ent, UNITY_PLACES_IS_PLACE_ENTRY_DBUS (_tmp0_) ? ((UnityPlacesPlaceEntryDbus*) _tmp0_) : NULL);
						if (_vala_strcmp0 (unity_places_place_entry_dbus_get_dbus_path (entry), entry_path) == 0) {
							unity_places_view_on_entry_view_activated (self->priv->view, (UnityPlacesPlaceEntry*) entry, (guint) section_id);
							_g_object_unref0 (ent);
							break;
						}
					}
					_g_object_unref0 (ent);
				}
				_g_object_unref0 (_ent_it);
			}
			_g_object_unref0 (place);
		}
		_g_object_unref0 (_place_it);
	}
}


static void _unity_places_controller_on_entry_clicked_unity_places_place_entry_scroller_child_controller_clicked (UnityPlacesPlaceEntryScrollerChildController* _sender, guint section_id, gpointer self) {
	unity_places_controller_on_entry_clicked (self, _sender, section_id);
}


static void unity_places_controller_on_entry_added (UnityPlacesController* self, UnityPlacesPlaceEntry* entry) {
	GeeArrayList* _tmp1_;
	UnityTestingObjectRegistry* _tmp0_;
	GObject* _tmp2_;
	UnityLauncherScrollerModel* _tmp3_;
	UnityLauncherScrollerModel* s;
	UnityPlacesPlaceEntryScrollerChildController* child;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	s = (_tmp3_ = (_tmp2_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp1_ = unity_testing_object_registry_lookup (_tmp0_ = unity_testing_object_registry_get_default (), "UnityScrollerModel")), 0), UNITY_LAUNCHER_IS_SCROLLER_MODEL (_tmp2_) ? ((UnityLauncherScrollerModel*) _tmp2_) : NULL), _g_object_unref0 (_tmp1_), _unity_testing_object_registry_unref0 (_tmp0_), _tmp3_);
	child = unity_places_place_entry_scroller_child_controller_new (entry);
	unity_launcher_scroller_model_add (s, unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) child));
	g_signal_connect_object (child, "clicked", (GCallback) _unity_places_controller_on_entry_clicked_unity_places_place_entry_scroller_child_controller_clicked, self, 0);
	_g_object_unref0 (child);
	_g_object_unref0 (s);
}


static void unity_places_controller_on_entry_clicked (UnityPlacesController* self, UnityPlacesPlaceEntryScrollerChildController* cont, guint section_id) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (cont != NULL);
	if (clutter_actor_get_opacity ((ClutterActor*) self->priv->view) == 0) {
		unity_shell_show_unity (self->priv->_shell);
	}
	unity_places_view_on_entry_view_activated (self->priv->view, unity_places_place_entry_scroller_child_controller_get_entry (cont), section_id);
}


UnityShell* unity_places_controller_get_shell (UnityPlacesController* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static void unity_places_controller_set_shell (UnityPlacesController* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


UnityPlacesPlaceModel* unity_places_controller_get_model (UnityPlacesController* self) {
	UnityPlacesPlaceModel* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_model;
	return result;
}


void unity_places_controller_set_model (UnityPlacesController* self, UnityPlacesPlaceModel* value) {
	UnityPlacesPlaceModel* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_model = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_model), _tmp0_);
	g_object_notify ((GObject *) self, "model");
}


UnityPlacesVolumeController* unity_places_controller_get_volumes (UnityPlacesController* self) {
	UnityPlacesVolumeController* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_volumes;
	return result;
}


void unity_places_controller_set_volumes (UnityPlacesController* self, UnityPlacesVolumeController* value) {
	UnityPlacesVolumeController* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_volumes = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_volumes), _tmp0_);
	g_object_notify ((GObject *) self, "volumes");
}


static void _lambda69_ (UnityPlacesPlace* place, UnityPlacesController* self) {
	g_return_if_fail (place != NULL);
	{
		GeeIterator* _e_it;
		_e_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) unity_places_place_get_entries (place));
		while (TRUE) {
			UnityPlacesPlaceEntry* e;
			if (!gee_iterator_next (_e_it)) {
				break;
			}
			e = (UnityPlacesPlaceEntry*) gee_iterator_get (_e_it);
			unity_places_controller_on_entry_added (self, e);
			_g_object_unref0 (e);
		}
		_g_object_unref0 (_e_it);
	}
}


static void __lambda69__unity_places_place_model_place_added (UnityPlacesPlaceModel* _sender, UnityPlacesPlace* place, gpointer self) {
	_lambda69_ (place, self);
}


static GObject * unity_places_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesController * self;
	parent_class = G_OBJECT_CLASS (unity_places_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_CONTROLLER (obj);
	{
		UnityPlacesPlaceModel* _tmp1_;
		UnityPlacesPlaceFileModel* _tmp0_;
		UnityPlacesVolumeController* _tmp2_;
		GeeArrayList* _tmp4_;
		UnityTestingObjectRegistry* _tmp3_;
		GObject* _tmp5_;
		UnityLauncherScrollerModel* _tmp6_;
		UnityLauncherScrollerModel* s;
		UnityPlacesTrashController* child;
		UnityPlacesView* _tmp7_;
		unity_places_controller_set_model (self, _tmp1_ = (_tmp0_ = unity_places_place_file_model_new (), UNITY_PLACES_IS_PLACE_MODEL (_tmp0_) ? ((UnityPlacesPlaceModel*) _tmp0_) : NULL));
		_g_object_unref0 (_tmp1_);
		g_signal_connect_object (self->priv->_model, "place-added", (GCallback) __lambda69__unity_places_place_model_place_added, self, 0);
		unity_places_controller_set_volumes (self, _tmp2_ = unity_places_volume_controller_new ());
		_g_object_unref0 (_tmp2_);
		s = (_tmp6_ = (_tmp5_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp4_ = unity_testing_object_registry_lookup (_tmp3_ = unity_testing_object_registry_get_default (), "UnityScrollerModel")), 0), UNITY_LAUNCHER_IS_SCROLLER_MODEL (_tmp5_) ? ((UnityLauncherScrollerModel*) _tmp5_) : NULL), _g_object_unref0 (_tmp4_), _unity_testing_object_registry_unref0 (_tmp3_), _tmp6_);
		child = unity_places_trash_controller_new ();
		unity_launcher_scroller_model_add (s, unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) child));
		self->priv->view = (_tmp7_ = g_object_ref_sink (unity_places_view_new (self->priv->_shell, self->priv->_model)), _g_object_unref0 (self->priv->view), _tmp7_);
		_g_object_unref0 (child);
		_g_object_unref0 (s);
	}
	return obj;
}


static void unity_places_controller_class_init (UnityPlacesControllerClass * klass) {
	unity_places_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_CONTROLLER_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_CONTROLLER_MODEL, g_param_spec_object ("model", "model", "model", UNITY_PLACES_TYPE_PLACE_MODEL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_CONTROLLER_VOLUMES, g_param_spec_object ("volumes", "volumes", "volumes", UNITY_PLACES_TYPE_VOLUME_CONTROLLER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_places_controller_instance_init (UnityPlacesController * self) {
	self->priv = UNITY_PLACES_CONTROLLER_GET_PRIVATE (self);
}


static void unity_places_controller_finalize (GObject* obj) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->_model);
	_g_object_unref0 (self->priv->_volumes);
	_g_object_unref0 (self->priv->view);
	G_OBJECT_CLASS (unity_places_controller_parent_class)->finalize (obj);
}


GType unity_places_controller_get_type (void) {
	static volatile gsize unity_places_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesController), 0, (GInstanceInitFunc) unity_places_controller_instance_init, NULL };
		GType unity_places_controller_type_id;
		unity_places_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPlacesController", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_controller_type_id__volatile, unity_places_controller_type_id);
	}
	return unity_places_controller_type_id__volatile;
}


static void unity_places_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_CONTROLLER_SHELL:
		g_value_set_object (value, unity_places_controller_get_shell (self));
		break;
		case UNITY_PLACES_CONTROLLER_MODEL:
		g_value_set_object (value, unity_places_controller_get_model (self));
		break;
		case UNITY_PLACES_CONTROLLER_VOLUMES:
		g_value_set_object (value, unity_places_controller_get_volumes (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_CONTROLLER_SHELL:
		unity_places_controller_set_shell (self, g_value_get_object (value));
		break;
		case UNITY_PLACES_CONTROLLER_MODEL:
		unity_places_controller_set_model (self, g_value_get_object (value));
		break;
		case UNITY_PLACES_CONTROLLER_VOLUMES:
		unity_places_controller_set_volumes (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




