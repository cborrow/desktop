/* places-place-search-navigation.c generated by valac, the Vala compiler
 * generated from places-place-search-navigation.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <dee.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <cairo.h>


#define UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION (unity_places_place_search_navigation_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION, UnityPlacesPlaceSearchNavigation))
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION, UnityPlacesPlaceSearchNavigationClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_NAVIGATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION))
#define UNITY_PLACES_IS_PLACE_SEARCH_NAVIGATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION))
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION, UnityPlacesPlaceSearchNavigationClass))

typedef struct _UnityPlacesPlaceSearchNavigation UnityPlacesPlaceSearchNavigation;
typedef struct _UnityPlacesPlaceSearchNavigationClass UnityPlacesPlaceSearchNavigationClass;
typedef struct _UnityPlacesPlaceSearchNavigationPrivate UnityPlacesPlaceSearchNavigationPrivate;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityPlacesPlaceSearchNavigation {
	CtkBox parent_instance;
	UnityPlacesPlaceSearchNavigationPrivate * priv;
};

struct _UnityPlacesPlaceSearchNavigationClass {
	CtkBoxClass parent_class;
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

struct _UnityPlacesPlaceSearchNavigationPrivate {
	UnityCairoCanvas* back;
	UnityCairoCanvas* forward;
	gboolean back_sensitive;
	gboolean forward_sensitive;
	UnityPlacesPlaceEntry* active_entry;
	CtkEffectGlow* glow;
	DBusGProxy* service;
};


static gpointer unity_places_place_search_navigation_parent_class = NULL;

GType unity_places_place_search_navigation_get_type (void) G_GNUC_CONST;
GType unity_places_place_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION, UnityPlacesPlaceSearchNavigationPrivate))
enum  {
	UNITY_PLACES_PLACE_SEARCH_NAVIGATION_DUMMY_PROPERTY
};
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION_SPACING 1
#define UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE 5
UnityPlacesPlaceSearchNavigation* unity_places_place_search_navigation_new (void);
UnityPlacesPlaceSearchNavigation* unity_places_place_search_navigation_construct (GType object_type);
GeeHashMap* unity_places_place_entry_get_hints (UnityPlacesPlaceEntry* self);
UnityPlacesPlace* unity_places_place_entry_get_parent (UnityPlacesPlaceEntry* self);
const char* unity_places_place_get_dbus_name (UnityPlacesPlace* self);
static GValueArray** _dynamic_get_state6 (DBusGProxy* self, int* result_length1, GError** error);
static void unity_places_place_search_navigation_refresh_state (UnityPlacesPlaceSearchNavigation* self, GValueArray** entries, int entries_length1);
void unity_places_place_search_navigation_set_active_entry (UnityPlacesPlaceSearchNavigation* self, UnityPlacesPlaceEntry* entry);
static void unity_places_place_search_navigation_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth);
static void unity_places_place_search_navigation_draw_back_arrow (UnityPlacesPlaceSearchNavigation* self, cairo_t* cr, gint width, gint height);
static void unity_places_place_search_navigation_draw_forward_arrow (UnityPlacesPlaceSearchNavigation* self, cairo_t* cr, gint width, gint height);
static void _unity_places_place_search_navigation_draw_back_arrow_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self);
static GValueArray** _dynamic_go_back7 (DBusGProxy* self, int* result_length1, GError** error);
static gboolean _lambda18_ (UnityPlacesPlaceSearchNavigation* self);
static gboolean __lambda18__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void _unity_places_place_search_navigation_draw_forward_arrow_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self);
static GValueArray** _dynamic_go_back8 (DBusGProxy* self, int* result_length1, GError** error);
static gboolean _lambda19_ (UnityPlacesPlaceSearchNavigation* self);
static gboolean __lambda19__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static GObject * unity_places_place_search_navigation_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_search_navigation_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



UnityPlacesPlaceSearchNavigation* unity_places_place_search_navigation_construct (GType object_type) {
	UnityPlacesPlaceSearchNavigation * self;
	self = (UnityPlacesPlaceSearchNavigation*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "homogeneous", FALSE, "spacing", UNITY_PLACES_PLACE_SEARCH_NAVIGATION_SPACING, NULL);
	return self;
}


UnityPlacesPlaceSearchNavigation* unity_places_place_search_navigation_new (void) {
	return unity_places_place_search_navigation_construct (UNITY_PLACES_TYPE_PLACE_SEARCH_NAVIGATION);
}


static GValueArray** _dynamic_get_state6 (DBusGProxy* self, int* result_length1, GError** error) {
	GPtrArray* result;
	dbus_g_proxy_call (self, "GetState", error, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_VALUE_ARRAY), &result, G_TYPE_INVALID);
	if (*error) {
		return NULL;
	}
	*result_length1 = result->len;
	return (GValueArray**) result->pdata;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void unity_places_place_search_navigation_set_active_entry (UnityPlacesPlaceSearchNavigation* self, UnityPlacesPlaceEntry* entry) {
	GError * _inner_error_;
	UnityPlacesPlaceEntry* _tmp0_;
	DBusGProxy* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	_inner_error_ = NULL;
	self->priv->active_entry = (_tmp0_ = NULL, _g_object_unref0 (self->priv->active_entry), _tmp0_);
	self->priv->service = (_tmp1_ = NULL, _g_object_unref0 (self->priv->service), _tmp1_);
	if (unity_places_place_entry_get_hints (entry) == NULL) {
		self->priv->back_sensitive = FALSE;
		self->priv->forward_sensitive = FALSE;
	} else {
		char* path;
		path = (char*) gee_abstract_map_get ((GeeAbstractMap*) unity_places_place_entry_get_hints (entry), "UnityPlaceBrowserPath");
		if (path != NULL) {
			{
				DBusGConnection* connection;
				DBusGProxy* _tmp2_;
				GValueArray** _tmp4_;
				gint _entries_size_;
				gint entries_length1;
				gint _tmp3_;
				GValueArray** entries;
				connection = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
				if (_inner_error_ != NULL) {
					goto __catch25_g_error;
				}
				self->priv->service = (_tmp2_ = dbus_g_proxy_new_for_name (connection, unity_places_place_get_dbus_name (unity_places_place_entry_get_parent (entry)), path, "com.canonical.Unity.PlaceBrowser"), _g_object_unref0 (self->priv->service), _tmp2_);
				entries = (_tmp4_ = _dynamic_get_state6 (self->priv->service, &_tmp3_, &_inner_error_), entries_length1 = _tmp3_, _entries_size_ = entries_length1, _tmp4_);
				if (_inner_error_ != NULL) {
					_dbus_g_connection_unref0 (connection);
					goto __catch25_g_error;
				}
				unity_places_place_search_navigation_refresh_state (self, entries, entries_length1);
				entries = (_vala_array_free (entries, entries_length1, (GDestroyNotify) g_value_array_free), NULL);
				_dbus_g_connection_unref0 (connection);
			}
			goto __finally25;
			__catch25_g_error:
			{
				GError * e;
				e = _inner_error_;
				_inner_error_ = NULL;
				{
					char* _tmp5_;
					g_warning (_tmp5_ = g_strconcat ("Unable to connect to ", string_to_string (path), ": %s", NULL), e->message);
					_g_free0 (_tmp5_);
					self->priv->back_sensitive = FALSE;
					self->priv->forward_sensitive = FALSE;
					_g_error_free0 (e);
				}
			}
			__finally25:
			if (_inner_error_ != NULL) {
				_g_free0 (path);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		} else {
			self->priv->back_sensitive = FALSE;
			self->priv->forward_sensitive = FALSE;
		}
		_g_free0 (path);
	}
	unity_cairo_canvas_update (self->priv->back);
	unity_cairo_canvas_update (self->priv->forward);
	clutter_actor_queue_relayout ((ClutterActor*) self);
	ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
}


static void unity_places_place_search_navigation_refresh_state (UnityPlacesPlaceSearchNavigation* self, GValueArray** entries, int entries_length1) {
	GValueArray* array;
	g_return_if_fail (self != NULL);
	array = NULL;
	array = entries[0];
	self->priv->back_sensitive = g_value_get_boolean (g_value_array_get_nth (array, (guint) 0));
	array = entries[1];
	self->priv->forward_sensitive = g_value_get_boolean (g_value_array_get_nth (array, (guint) 0));
}


static void unity_places_place_search_navigation_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth) {
	UnityPlacesPlaceSearchNavigation * self;
	self = (UnityPlacesPlaceSearchNavigation*) base;
	*mwidth = 54.0f;
	*nwidth = 54.0f;
}


static void unity_places_place_search_navigation_draw_back_arrow (UnityPlacesPlaceSearchNavigation* self, cairo_t* cr, gint width, gint height) {
	float _tmp0_ = 0.0F;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_line_width (cr, (double) 1.0f);
	cairo_translate (cr, (double) (-0.5f), (double) (-0.5f));
	if (self->priv->back_sensitive) {
		_tmp0_ = 1.0f;
	} else {
		_tmp0_ = 0.5f;
	}
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) _tmp0_);
	cairo_move_to (cr, (double) ((width / 2) - UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) (height / 2));
	cairo_line_to (cr, (double) ((width / 2) + UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) ((height / 2) - UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE));
	cairo_line_to (cr, (double) ((width / 2) + UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) ((height / 2) + UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE));
	cairo_close_path (cr);
	cairo_fill (cr);
}


static void unity_places_place_search_navigation_draw_forward_arrow (UnityPlacesPlaceSearchNavigation* self, cairo_t* cr, gint width, gint height) {
	float _tmp0_ = 0.0F;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_line_width (cr, (double) 1.0f);
	cairo_translate (cr, (double) 0.5f, (double) (-0.5f));
	if (self->priv->forward_sensitive) {
		_tmp0_ = 1.0f;
	} else {
		_tmp0_ = 0.5f;
	}
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) _tmp0_);
	cairo_move_to (cr, (double) ((width / 2) + UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) (height / 2));
	cairo_line_to (cr, (double) ((width / 2) - UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) ((height / 2) - UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE));
	cairo_line_to (cr, (double) ((width / 2) - UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE), (double) ((height / 2) + UNITY_PLACES_PLACE_SEARCH_NAVIGATION_ARROW_SIZE));
	cairo_close_path (cr);
	cairo_fill (cr);
}


static void _unity_places_place_search_navigation_draw_back_arrow_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self) {
	unity_places_place_search_navigation_draw_back_arrow (self, cr, width, height);
}


static GValueArray** _dynamic_go_back7 (DBusGProxy* self, int* result_length1, GError** error) {
	GPtrArray* result;
	dbus_g_proxy_call (self, "GoBack", error, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_VALUE_ARRAY), &result, G_TYPE_INVALID);
	if (*error) {
		return NULL;
	}
	*result_length1 = result->len;
	return (GValueArray**) result->pdata;
}


static gboolean _lambda18_ (UnityPlacesPlaceSearchNavigation* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	gboolean _tmp0_ = FALSE;
	_inner_error_ = NULL;
	if (self->priv->service != NULL) {
		_tmp0_ = self->priv->back_sensitive;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GValueArray** _tmp2_;
		gint _a_size_;
		gint a_length1;
		gint _tmp1_;
		GValueArray** a;
		a = (_tmp2_ = _dynamic_go_back7 (self->priv->service, &_tmp1_, &_inner_error_), a_length1 = _tmp1_, _a_size_ = a_length1, _tmp2_);
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
		unity_places_place_search_navigation_refresh_state (self, a, a_length1);
		a = (_vala_array_free (a, a_length1, (GDestroyNotify) g_value_array_free), NULL);
	}
	result = TRUE;
	return result;
}


static gboolean __lambda18__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _lambda18_ (self);
	return result;
}


static void _unity_places_place_search_navigation_draw_forward_arrow_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self) {
	unity_places_place_search_navigation_draw_forward_arrow (self, cr, width, height);
}


static GValueArray** _dynamic_go_back8 (DBusGProxy* self, int* result_length1, GError** error) {
	GPtrArray* result;
	dbus_g_proxy_call (self, "GoBack", error, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_VALUE_ARRAY), &result, G_TYPE_INVALID);
	if (*error) {
		return NULL;
	}
	*result_length1 = result->len;
	return (GValueArray**) result->pdata;
}


static gboolean _lambda19_ (UnityPlacesPlaceSearchNavigation* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	gboolean _tmp0_ = FALSE;
	_inner_error_ = NULL;
	if (self->priv->service != NULL) {
		_tmp0_ = self->priv->forward_sensitive;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GValueArray** _tmp2_;
		gint _a_size_;
		gint a_length1;
		gint _tmp1_;
		GValueArray** a;
		a = (_tmp2_ = _dynamic_go_back8 (self->priv->service, &_tmp1_, &_inner_error_), a_length1 = _tmp1_, _a_size_ = a_length1, _tmp2_);
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
		unity_places_place_search_navigation_refresh_state (self, a, a_length1);
		a = (_vala_array_free (a, a_length1, (GDestroyNotify) g_value_array_free), NULL);
	}
	result = TRUE;
	return result;
}


static gboolean __lambda19__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _lambda19_ (self);
	return result;
}


static GObject * unity_places_place_search_navigation_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceSearchNavigation * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_search_navigation_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_SEARCH_NAVIGATION (obj);
	{
		UnityCairoCanvas* _tmp0_;
		UnityCairoCanvas* _tmp1_;
		CtkEffectGlow* _tmp2_;
		ClutterColor _tmp4_;
		ClutterColor _tmp3_ = {0};
		self->priv->back = (_tmp0_ = g_object_ref_sink (unity_cairo_canvas_new (_unity_places_place_search_navigation_draw_back_arrow_unity_cairo_canvas_cairo_canvas_paint, self)), _g_object_unref0 (self->priv->back), _tmp0_);
		clutter_actor_set_reactive ((ClutterActor*) self->priv->back, TRUE);
		g_signal_connect_object ((ClutterActor*) self->priv->back, "button-release-event", (GCallback) __lambda18__clutter_actor_button_release_event, self, 0);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->back, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->back);
		self->priv->forward = (_tmp1_ = g_object_ref_sink (unity_cairo_canvas_new (_unity_places_place_search_navigation_draw_forward_arrow_unity_cairo_canvas_cairo_canvas_paint, self)), _g_object_unref0 (self->priv->forward), _tmp1_);
		g_signal_connect_object ((ClutterActor*) self->priv->forward, "button-release-event", (GCallback) __lambda19__clutter_actor_button_release_event, self, 0);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->forward, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->forward);
		self->priv->glow = (_tmp2_ = g_object_ref_sink ((CtkEffectGlow*) ctk_effect_glow_new ()), _g_object_unref0 (self->priv->glow), _tmp2_);
		ctk_effect_glow_set_color (self->priv->glow, (_tmp4_ = (_tmp3_.red = (guint8) 255, _tmp3_.green = (guint8) 255, _tmp3_.blue = (guint8) 255, _tmp3_.alpha = (guint8) 255, _tmp3_), &_tmp4_));
		ctk_effect_glow_set_factor (self->priv->glow, 1.0f);
		ctk_effect_set_margin ((CtkEffect*) self->priv->glow, 5);
		ctk_actor_add_effect ((CtkActor*) self, (CtkEffect*) self->priv->glow);
	}
	return obj;
}


static void unity_places_place_search_navigation_class_init (UnityPlacesPlaceSearchNavigationClass * klass) {
	unity_places_place_search_navigation_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceSearchNavigationPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_places_place_search_navigation_real_get_preferred_width;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_search_navigation_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_search_navigation_finalize;
}


static void unity_places_place_search_navigation_instance_init (UnityPlacesPlaceSearchNavigation * self) {
	self->priv = UNITY_PLACES_PLACE_SEARCH_NAVIGATION_GET_PRIVATE (self);
	self->priv->back_sensitive = FALSE;
	self->priv->forward_sensitive = FALSE;
	self->priv->active_entry = NULL;
}


static void unity_places_place_search_navigation_finalize (GObject* obj) {
	UnityPlacesPlaceSearchNavigation * self;
	self = UNITY_PLACES_PLACE_SEARCH_NAVIGATION (obj);
	_g_object_unref0 (self->priv->back);
	_g_object_unref0 (self->priv->forward);
	_g_object_unref0 (self->priv->active_entry);
	_g_object_unref0 (self->priv->glow);
	_g_object_unref0 (self->priv->service);
	G_OBJECT_CLASS (unity_places_place_search_navigation_parent_class)->finalize (obj);
}


GType unity_places_place_search_navigation_get_type (void) {
	static volatile gsize unity_places_place_search_navigation_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_search_navigation_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceSearchNavigationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_search_navigation_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceSearchNavigation), 0, (GInstanceInitFunc) unity_places_place_search_navigation_instance_init, NULL };
		GType unity_places_place_search_navigation_type_id;
		unity_places_place_search_navigation_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesPlaceSearchNavigation", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_search_navigation_type_id__volatile, unity_places_place_search_navigation_type_id);
	}
	return unity_places_place_search_navigation_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}




