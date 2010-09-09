/* places-place-home-renderer.c generated by valac, the Vala compiler
 * generated from places-place-home-renderer.vala, do not modify */

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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <dee.h>
#include <gee.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <glib/gi18n-lib.h>
#include <gconf/gconf-client.h>


#define UNITY_PLACES_TYPE_HOME_RENDERER (unity_places_home_renderer_get_type ())
#define UNITY_PLACES_HOME_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRenderer))
#define UNITY_PLACES_HOME_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRendererClass))
#define UNITY_PLACES_IS_HOME_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_HOME_RENDERER))
#define UNITY_PLACES_IS_HOME_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_HOME_RENDERER))
#define UNITY_PLACES_HOME_RENDERER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRendererClass))

typedef struct _UnityPlacesHomeRenderer UnityPlacesHomeRenderer;
typedef struct _UnityPlacesHomeRendererClass UnityPlacesHomeRendererClass;
typedef struct _UnityPlacesHomeRendererPrivate UnityPlacesHomeRendererPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TESTING_TYPE_OBJECT_REGISTRY (unity_testing_object_registry_get_type ())
#define UNITY_TESTING_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistry))
#define UNITY_TESTING_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))
#define UNITY_TESTING_IS_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_IS_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_OBJECT_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))

typedef struct _UnityTestingObjectRegistry UnityTestingObjectRegistry;
typedef struct _UnityTestingObjectRegistryClass UnityTestingObjectRegistryClass;

#define UNITY_PLACES_TYPE_CONTROLLER (unity_places_controller_get_type ())
#define UNITY_PLACES_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesController))
#define UNITY_PLACES_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))
#define UNITY_PLACES_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))

typedef struct _UnityPlacesController UnityPlacesController;
typedef struct _UnityPlacesControllerClass UnityPlacesControllerClass;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_PLACES_TYPE_HOME_BUTTON (unity_places_home_button_get_type ())
#define UNITY_PLACES_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_HOME_BUTTON, UnityPlacesHomeButton))
#define UNITY_PLACES_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_HOME_BUTTON, UnityPlacesHomeButtonClass))
#define UNITY_PLACES_IS_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_HOME_BUTTON))
#define UNITY_PLACES_IS_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_HOME_BUTTON))
#define UNITY_PLACES_HOME_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_HOME_BUTTON, UnityPlacesHomeButtonClass))

typedef struct _UnityPlacesHomeButton UnityPlacesHomeButton;
typedef struct _UnityPlacesHomeButtonClass UnityPlacesHomeButtonClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityPlacesHomeButtonPrivate UnityPlacesHomeButtonPrivate;

struct _UnityPlacesHomeRenderer {
	CtkBin parent_instance;
	UnityPlacesHomeRendererPrivate * priv;
};

struct _UnityPlacesHomeRendererClass {
	CtkBinClass parent_class;
};

struct _UnityPlacesHomeRendererPrivate {
	GtkIconTheme* theme;
	CtkIconView* icon_view;
};

struct _UnityPlacesHomeButton {
	CtkButton parent_instance;
	UnityPlacesHomeButtonPrivate * priv;
};

struct _UnityPlacesHomeButtonClass {
	CtkButtonClass parent_class;
};

struct _UnityPlacesHomeButtonPrivate {
	char* _name;
	char* _icon;
	char* _exec;
};


static gpointer unity_places_home_renderer_parent_class = NULL;
static UnityPlaceRendererIface* unity_places_home_renderer_unity_place_renderer_parent_iface = NULL;
static gpointer unity_places_home_button_parent_class = NULL;

GType unity_places_home_renderer_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_HOME_RENDERER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRendererPrivate))
enum  {
	UNITY_PLACES_HOME_RENDERER_DUMMY_PROPERTY
};
#define UNITY_PLACES_HOME_RENDERER_SPACING 60
#define UNITY_PLACES_HOME_RENDERER_FILES_PLACE "/com/canonical/unity/filesplace/files"
#define UNITY_PLACES_HOME_RENDERER_APPS_PLACE "/com/canonical/unity/applicationsplace/applications"
UnityPlacesHomeRenderer* unity_places_home_renderer_new (void);
UnityPlacesHomeRenderer* unity_places_home_renderer_construct (GType object_type);
static void unity_places_home_renderer_real_set_models (UnityPlaceRenderer* base, DeeModel* groups, DeeModel* results, GeeHashMap* hints);
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void) G_GNUC_CONST;
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
GeeArrayList* unity_testing_object_registry_lookup (UnityTestingObjectRegistry* self, const char* name);
GType unity_places_controller_get_type (void) G_GNUC_CONST;
void unity_places_controller_activate_entry_by_dbus_path (UnityPlacesController* self, const char* entry_path, gint section_id);
static void unity_places_home_renderer_activate_place (UnityPlacesHomeRenderer* self, const char* place_path, gint section_id);
static void unity_places_home_renderer_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static char* unity_places_home_renderer_filename_for_icon (UnityPlacesHomeRenderer* self, const char* icon);
UnityPlacesHomeButton* unity_places_home_button_new (const char* name, const char* icon, const char* exec);
UnityPlacesHomeButton* unity_places_home_button_construct (GType object_type, const char* name, const char* icon, const char* exec);
GType unity_places_home_button_get_type (void) G_GNUC_CONST;
static void _lambda56_ (UnityPlacesHomeRenderer* self);
static void __lambda56__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda57_ (UnityPlacesHomeRenderer* self);
static void __lambda57__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda58_ (UnityPlacesHomeRenderer* self);
static void __lambda58__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda59_ (UnityPlacesHomeRenderer* self);
static void __lambda59__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda60_ (UnityPlacesHomeRenderer* self);
static void __lambda60__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda61_ (UnityPlacesHomeRenderer* self);
static void __lambda61__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda62_ (UnityPlacesHomeRenderer* self);
static void __lambda62__ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _lambda63_ (UnityPlacesHomeRenderer* self);
static void __lambda63__ctk_button_clicked (CtkButton* _sender, gpointer self);
static GObject * unity_places_home_renderer_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_home_renderer_finalize (GObject* obj);
#define UNITY_PLACES_HOME_BUTTON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_HOME_BUTTON, UnityPlacesHomeButtonPrivate))
enum  {
	UNITY_PLACES_HOME_BUTTON_DUMMY_PROPERTY,
	UNITY_PLACES_HOME_BUTTON_NAME,
	UNITY_PLACES_HOME_BUTTON_ICON,
	UNITY_PLACES_HOME_BUTTON_EXEC
};
#define UNITY_PLACES_HOME_BUTTON_ICON_SIZE 128
static void unity_places_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth);
const char* unity_places_home_button_get_name (UnityPlacesHomeButton* self);
static void unity_places_home_button_set_name (UnityPlacesHomeButton* self, const char* value);
const char* unity_places_home_button_get_icon (UnityPlacesHomeButton* self);
static void unity_places_home_button_set_icon (UnityPlacesHomeButton* self, const char* value);
const char* unity_places_home_button_get_exec (UnityPlacesHomeButton* self);
static void unity_places_home_button_set_exec (UnityPlacesHomeButton* self, const char* value);
static GObject * unity_places_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_home_button_finalize (GObject* obj);
static void unity_places_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesHomeRenderer* unity_places_home_renderer_construct (GType object_type) {
	UnityPlacesHomeRenderer * self;
	self = (UnityPlacesHomeRenderer*) g_object_new (object_type, NULL);
	return self;
}


UnityPlacesHomeRenderer* unity_places_home_renderer_new (void) {
	return unity_places_home_renderer_construct (UNITY_PLACES_TYPE_HOME_RENDERER);
}


static void unity_places_home_renderer_real_set_models (UnityPlaceRenderer* base, DeeModel* groups, DeeModel* results, GeeHashMap* hints) {
	UnityPlacesHomeRenderer * self;
	self = (UnityPlacesHomeRenderer*) base;
	g_return_if_fail (groups != NULL);
	g_return_if_fail (results != NULL);
	g_return_if_fail (hints != NULL);
}


static void unity_places_home_renderer_activate_place (UnityPlacesHomeRenderer* self, const char* place_path, gint section_id) {
	GeeArrayList* _tmp1_;
	UnityTestingObjectRegistry* _tmp0_;
	GObject* _tmp2_;
	UnityPlacesController* _tmp3_;
	UnityPlacesController* cont;
	g_return_if_fail (self != NULL);
	g_return_if_fail (place_path != NULL);
	cont = (_tmp3_ = (_tmp2_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp1_ = unity_testing_object_registry_lookup (_tmp0_ = unity_testing_object_registry_get_default (), "UnityPlacesController")), 0), UNITY_PLACES_IS_CONTROLLER (_tmp2_) ? ((UnityPlacesController*) _tmp2_) : NULL), _g_object_unref0 (_tmp1_), _unity_testing_object_registry_unref0 (_tmp0_), _tmp3_);
	if (UNITY_PLACES_IS_CONTROLLER (cont)) {
		unity_places_controller_activate_entry_by_dbus_path (cont, place_path, section_id);
	}
	_g_object_unref0 (cont);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_places_home_renderer_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesHomeRenderer * self;
	float icon_width = 0.0F;
	float icon_height = 0.0F;
	GList* children;
	ClutterActor* _tmp0_;
	ClutterActor* child;
	float left;
	float top;
	ClutterActorBox child_box = {0};
	self = (UnityPlacesHomeRenderer*) base;
	CLUTTER_ACTOR_CLASS (unity_places_home_renderer_parent_class)->allocate ((ClutterActor*) CTK_BIN (self), box, flags);
	children = clutter_container_get_children ((ClutterContainer*) self->priv->icon_view);
	child = _g_object_ref0 ((_tmp0_ = (ClutterActor*) g_list_nth_data (children, (guint) 0), CLUTTER_IS_ACTOR (_tmp0_) ? ((ClutterActor*) _tmp0_) : NULL));
	clutter_actor_get_preferred_size (child, &icon_width, NULL, &icon_height, NULL);
	left = ((((*box).x2 - (*box).x1) - (3 * UNITY_PLACES_HOME_RENDERER_SPACING)) - (4 * icon_width)) / 2.0f;
	top = ((((*box).y2 - (*box).y1) - (1 * UNITY_PLACES_HOME_RENDERER_SPACING)) - (2 * icon_height)) / 2.0f;
	top = top - (UNITY_PLACES_HOME_RENDERER_SPACING / 2.0f);
	memset (&child_box, 0, sizeof (ClutterActorBox));
	child_box.x1 = left;
	child_box.x2 = (*box).x2 - (*box).x1;
	child_box.y1 = top;
	child_box.y2 = (*box).y2 - (*box).y1;
	clutter_actor_allocate ((ClutterActor*) self->priv->icon_view, &child_box, flags);
	_g_object_unref0 (child);
	_g_list_free0 (children);
}


static char* unity_places_home_renderer_filename_for_icon (UnityPlacesHomeRenderer* self, const char* icon) {
	char* result = NULL;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (icon != NULL, NULL);
	result = (_tmp1_ = g_strconcat (_tmp0_ = g_strconcat ("/usr/share/icons/unity-icon-theme/apps/128/", icon, NULL), ".svg", NULL), _g_free0 (_tmp0_), _tmp1_);
	return result;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _lambda56_ (UnityPlacesHomeRenderer* self) {
	GError * _inner_error_;
	GConfClient* client;
	_inner_error_ = NULL;
	client = _g_object_ref0 (gconf_client_get_default ());
	{
		char* exec;
		exec = gconf_client_get_string (client, "/desktop/gnome/applications/browser/exec", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		if (exec != NULL) {
			g_spawn_command_line_async (exec, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_free0 (exec);
				goto __catch16_g_error;
			}
		}
		_g_free0 (exec);
	}
	goto __finally16;
	__catch16_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("places-place-home-renderer.vala:60: %s", _tmp0_ = g_strconcat ("Unable to start web browser: ", string_to_string (e->message), NULL));
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally16:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (client);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	unity_shell_hide_unity (unity_global_shell);
	_g_object_unref0 (client);
}


static void __lambda56__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda56_ (self);
}


static void _lambda57_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_APPS_PLACE, 4);
}


static void __lambda57__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda57_ (self);
}


static void _lambda58_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_APPS_PLACE, 4);
}


static void __lambda58__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda58_ (self);
}


static void _lambda59_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_APPS_PLACE, 2);
}


static void __lambda59__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda59_ (self);
}


static void _lambda60_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_APPS_PLACE, 3);
}


static void __lambda60__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda60_ (self);
}


static void _lambda61_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_APPS_PLACE, 5);
}


static void __lambda61__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda61_ (self);
}


static void _lambda62_ (UnityPlacesHomeRenderer* self) {
	unity_places_home_renderer_activate_place (self, UNITY_PLACES_HOME_RENDERER_FILES_PLACE, 0);
}


static void __lambda62__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda62_ (self);
}


static void _lambda63_ (UnityPlacesHomeRenderer* self) {
	GError * _inner_error_;
	_inner_error_ = NULL;
	{
		g_spawn_command_line_async ("software-center", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch17_g_error;
		}
	}
	goto __finally17;
	__catch17_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("places-place-home-renderer.vala:116: %s", _tmp0_ = g_strconcat ("Unable to start software centre: ", string_to_string (e->message), NULL));
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally17:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	unity_shell_hide_unity (unity_global_shell);
}


static void __lambda63__ctk_button_clicked (CtkButton* _sender, gpointer self) {
	_lambda63_ (self);
}


static GObject * unity_places_home_renderer_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesHomeRenderer * self;
	parent_class = G_OBJECT_CLASS (unity_places_home_renderer_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_HOME_RENDERER (obj);
	{
		CtkPadding _tmp0_ = {0};
		CtkPadding _tmp1_;
		CtkIconView* _tmp2_;
		char* _tmp3_;
		UnityPlacesHomeButton* _tmp4_;
		UnityPlacesHomeButton* icon;
		UnityPlacesHomeButton* _tmp6_;
		char* _tmp5_;
		UnityPlacesHomeButton* _tmp8_;
		char* _tmp7_;
		UnityPlacesHomeButton* _tmp10_;
		char* _tmp9_;
		UnityPlacesHomeButton* _tmp12_;
		char* _tmp11_;
		UnityPlacesHomeButton* _tmp14_;
		char* _tmp13_;
		UnityPlacesHomeButton* _tmp16_;
		char* _tmp15_;
		UnityPlacesHomeButton* _tmp18_;
		char* _tmp17_;
		ctk_actor_set_padding ((CtkActor*) self, (_tmp1_ = (_tmp0_.top = 0.0f, _tmp0_.right = 0.0f, _tmp0_.bottom = 0.0f, _tmp0_.left = 0.0f, _tmp0_), &_tmp1_));
		self->priv->icon_view = (_tmp2_ = g_object_ref_sink ((CtkIconView*) ctk_icon_view_new ()), _g_object_unref0 (self->priv->icon_view), _tmp2_);
		ctk_icon_view_set_spacing (self->priv->icon_view, UNITY_PLACES_HOME_RENDERER_SPACING);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->icon_view);
		clutter_actor_show ((ClutterActor*) self->priv->icon_view);
		icon = (_tmp4_ = g_object_ref_sink (unity_places_home_button_new (_ ("Web"), _tmp3_ = unity_places_home_renderer_filename_for_icon (self, "web"), "")), _g_free0 (_tmp3_), _tmp4_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda56__ctk_button_clicked, self, 0);
		icon = (_tmp6_ = g_object_ref_sink (unity_places_home_button_new (_ ("Music"), _tmp5_ = unity_places_home_renderer_filename_for_icon (self, "music"), "")), _g_object_unref0 (icon), _tmp6_);
		_g_free0 (_tmp5_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda57__ctk_button_clicked, self, 0);
		icon = (_tmp8_ = g_object_ref_sink (unity_places_home_button_new (_ ("Photos & Videos"), _tmp7_ = unity_places_home_renderer_filename_for_icon (self, "photos"), "")), _g_object_unref0 (icon), _tmp8_);
		_g_free0 (_tmp7_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda58__ctk_button_clicked, self, 0);
		icon = (_tmp10_ = g_object_ref_sink (unity_places_home_button_new (_ ("Games"), _tmp9_ = unity_places_home_renderer_filename_for_icon (self, "games"), "")), _g_object_unref0 (icon), _tmp10_);
		_g_free0 (_tmp9_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda59__ctk_button_clicked, self, 0);
		icon = (_tmp12_ = g_object_ref_sink (unity_places_home_button_new (_ ("Email & Chat"), _tmp11_ = unity_places_home_renderer_filename_for_icon (self, "email_and_chat"), "")), _g_object_unref0 (icon), _tmp12_);
		_g_free0 (_tmp11_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda60__ctk_button_clicked, self, 0);
		icon = (_tmp14_ = g_object_ref_sink (unity_places_home_button_new (_ ("Office"), _tmp13_ = unity_places_home_renderer_filename_for_icon (self, "work"), "")), _g_object_unref0 (icon), _tmp14_);
		_g_free0 (_tmp13_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda61__ctk_button_clicked, self, 0);
		icon = (_tmp16_ = g_object_ref_sink (unity_places_home_button_new (_ ("Files & Folders"), _tmp15_ = unity_places_home_renderer_filename_for_icon (self, "filesandfolders"), "")), _g_object_unref0 (icon), _tmp16_);
		_g_free0 (_tmp15_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda62__ctk_button_clicked, self, 0);
		icon = (_tmp18_ = g_object_ref_sink (unity_places_home_button_new (_ ("Get New Apps"), _tmp17_ = unity_places_home_renderer_filename_for_icon (self, "softwarecentre"), "")), _g_object_unref0 (icon), _tmp18_);
		_g_free0 (_tmp17_);
		clutter_container_add_actor ((ClutterContainer*) self->priv->icon_view, (ClutterActor*) icon);
		clutter_actor_show ((ClutterActor*) icon);
		g_signal_connect_object ((CtkButton*) icon, "clicked", (GCallback) __lambda63__ctk_button_clicked, self, 0);
		_g_object_unref0 (icon);
	}
	return obj;
}


static void unity_places_home_renderer_class_init (UnityPlacesHomeRendererClass * klass) {
	unity_places_home_renderer_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesHomeRendererPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_home_renderer_real_allocate;
	G_OBJECT_CLASS (klass)->constructor = unity_places_home_renderer_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_home_renderer_finalize;
}


static void unity_places_home_renderer_unity_place_renderer_interface_init (UnityPlaceRendererIface * iface) {
	unity_places_home_renderer_unity_place_renderer_parent_iface = g_type_interface_peek_parent (iface);
	iface->set_models = unity_places_home_renderer_real_set_models;
}


static void unity_places_home_renderer_instance_init (UnityPlacesHomeRenderer * self) {
	self->priv = UNITY_PLACES_HOME_RENDERER_GET_PRIVATE (self);
	self->priv->theme = NULL;
}


static void unity_places_home_renderer_finalize (GObject* obj) {
	UnityPlacesHomeRenderer * self;
	self = UNITY_PLACES_HOME_RENDERER (obj);
	{
	}
	_g_object_unref0 (self->priv->theme);
	_g_object_unref0 (self->priv->icon_view);
	G_OBJECT_CLASS (unity_places_home_renderer_parent_class)->finalize (obj);
}


GType unity_places_home_renderer_get_type (void) {
	static volatile gsize unity_places_home_renderer_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_home_renderer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesHomeRendererClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_home_renderer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesHomeRenderer), 0, (GInstanceInitFunc) unity_places_home_renderer_instance_init, NULL };
		static const GInterfaceInfo unity_place_renderer_info = { (GInterfaceInitFunc) unity_places_home_renderer_unity_place_renderer_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType unity_places_home_renderer_type_id;
		unity_places_home_renderer_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityPlacesHomeRenderer", &g_define_type_info, 0);
		g_type_add_interface_static (unity_places_home_renderer_type_id, UNITY_PLACE_TYPE_RENDERER, &unity_place_renderer_info);
		g_once_init_leave (&unity_places_home_renderer_type_id__volatile, unity_places_home_renderer_type_id);
	}
	return unity_places_home_renderer_type_id__volatile;
}


UnityPlacesHomeButton* unity_places_home_button_construct (GType object_type, const char* name, const char* icon, const char* exec) {
	UnityPlacesHomeButton * self;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (icon != NULL, NULL);
	g_return_val_if_fail (exec != NULL, NULL);
	self = (UnityPlacesHomeButton*) g_object_new (object_type, "name", name, "icon", icon, "exec", exec, "orientation", CTK_ORIENTATION_VERTICAL, NULL);
	return self;
}


UnityPlacesHomeButton* unity_places_home_button_new (const char* name, const char* icon, const char* exec) {
	return unity_places_home_button_construct (UNITY_PLACES_TYPE_HOME_BUTTON, name, icon, exec);
}


static void unity_places_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth) {
	UnityPlacesHomeButton * self;
	self = (UnityPlacesHomeButton*) base;
	*mwidth = (float) UNITY_PLACES_HOME_BUTTON_ICON_SIZE;
	*nwidth = (float) UNITY_PLACES_HOME_BUTTON_ICON_SIZE;
}


const char* unity_places_home_button_get_name (UnityPlacesHomeButton* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_name;
	return result;
}


static void unity_places_home_button_set_name (UnityPlacesHomeButton* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_name), _tmp0_);
	g_object_notify ((GObject *) self, "name");
}


const char* unity_places_home_button_get_icon (UnityPlacesHomeButton* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
	return result;
}


static void unity_places_home_button_set_icon (UnityPlacesHomeButton* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


const char* unity_places_home_button_get_exec (UnityPlacesHomeButton* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_exec;
	return result;
}


static void unity_places_home_button_set_exec (UnityPlacesHomeButton* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_exec = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_exec), _tmp0_);
	g_object_notify ((GObject *) self, "exec");
}


static GObject * unity_places_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesHomeButton * self;
	parent_class = G_OBJECT_CLASS (unity_places_home_button_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_HOME_BUTTON (obj);
	{
		ctk_image_set_size (ctk_button_get_image ((CtkButton*) self), 128);
		g_object_set (ctk_button_get_image ((CtkButton*) self), "filename", self->priv->_icon, NULL);
		clutter_text_set_text ((ClutterText*) ctk_button_get_text ((CtkButton*) self), self->priv->_name);
	}
	return obj;
}


static void unity_places_home_button_class_init (UnityPlacesHomeButtonClass * klass) {
	unity_places_home_button_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesHomeButtonPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_places_home_button_real_get_preferred_width;
	G_OBJECT_CLASS (klass)->get_property = unity_places_home_button_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_home_button_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_home_button_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_home_button_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_HOME_BUTTON_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_HOME_BUTTON_ICON, g_param_spec_string ("icon", "icon", "icon", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_HOME_BUTTON_EXEC, g_param_spec_string ("exec", "exec", "exec", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_home_button_instance_init (UnityPlacesHomeButton * self) {
	self->priv = UNITY_PLACES_HOME_BUTTON_GET_PRIVATE (self);
}


static void unity_places_home_button_finalize (GObject* obj) {
	UnityPlacesHomeButton * self;
	self = UNITY_PLACES_HOME_BUTTON (obj);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_icon);
	_g_free0 (self->priv->_exec);
	G_OBJECT_CLASS (unity_places_home_button_parent_class)->finalize (obj);
}


GType unity_places_home_button_get_type (void) {
	static volatile gsize unity_places_home_button_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_home_button_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesHomeButtonClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_home_button_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesHomeButton), 0, (GInstanceInitFunc) unity_places_home_button_instance_init, NULL };
		GType unity_places_home_button_type_id;
		unity_places_home_button_type_id = g_type_register_static (CTK_TYPE_BUTTON, "UnityPlacesHomeButton", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_home_button_type_id__volatile, unity_places_home_button_type_id);
	}
	return unity_places_home_button_type_id__volatile;
}


static void unity_places_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesHomeButton * self;
	self = UNITY_PLACES_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PLACES_HOME_BUTTON_NAME:
		g_value_set_string (value, unity_places_home_button_get_name (self));
		break;
		case UNITY_PLACES_HOME_BUTTON_ICON:
		g_value_set_string (value, unity_places_home_button_get_icon (self));
		break;
		case UNITY_PLACES_HOME_BUTTON_EXEC:
		g_value_set_string (value, unity_places_home_button_get_exec (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesHomeButton * self;
	self = UNITY_PLACES_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PLACES_HOME_BUTTON_NAME:
		unity_places_home_button_set_name (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_HOME_BUTTON_ICON:
		unity_places_home_button_set_icon (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_HOME_BUTTON_EXEC:
		unity_places_home_button_set_exec (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




