/* places-place-view.c generated by valac 0.9.7, the Vala compiler
 * generated from places-place-view.vala, do not modify */

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
#include <clutter/clutter.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <dee.h>


#define UNITY_PLACES_TYPE_PLACE_VIEW (unity_places_place_view_get_type ())
#define UNITY_PLACES_PLACE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceView))
#define UNITY_PLACES_PLACE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceViewClass))
#define UNITY_PLACES_IS_PLACE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_VIEW))
#define UNITY_PLACES_IS_PLACE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_VIEW))
#define UNITY_PLACES_PLACE_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceViewClass))

typedef struct _UnityPlacesPlaceView UnityPlacesPlaceView;
typedef struct _UnityPlacesPlaceViewClass UnityPlacesPlaceViewClass;
typedef struct _UnityPlacesPlaceViewPrivate UnityPlacesPlaceViewPrivate;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW (unity_places_place_entry_view_get_type ())
#define UNITY_PLACES_PLACE_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryView))
#define UNITY_PLACES_PLACE_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryViewClass))
#define UNITY_PLACES_IS_PLACE_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW))
#define UNITY_PLACES_IS_PLACE_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW))
#define UNITY_PLACES_PLACE_ENTRY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryViewClass))

typedef struct _UnityPlacesPlaceEntryView UnityPlacesPlaceEntryView;
typedef struct _UnityPlacesPlaceEntryViewClass UnityPlacesPlaceEntryViewClass;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

struct _UnityPlacesPlaceView {
	CtkBox parent_instance;
	UnityPlacesPlaceViewPrivate * priv;
};

struct _UnityPlacesPlaceViewClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesPlaceViewPrivate {
	UnityPlacesPlace* _place;
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


static gpointer unity_places_place_view_parent_class = NULL;

GType unity_places_place_view_get_type (void) G_GNUC_CONST;
GType unity_places_place_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_PLACE_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceViewPrivate))
enum  {
	UNITY_PLACES_PLACE_VIEW_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_VIEW_PLACE
};
UnityPlacesPlaceView* unity_places_place_view_new (UnityPlacesPlace* place);
UnityPlacesPlaceView* unity_places_place_view_construct (GType object_type, UnityPlacesPlace* place);
static gboolean unity_places_place_view_on_entry_clicked (UnityPlacesPlaceView* self, ClutterActor* view, ClutterEvent* e);
GType unity_places_place_entry_view_get_type (void) G_GNUC_CONST;
UnityPlacesPlace* unity_places_place_view_get_place (UnityPlacesPlaceView* self);
static void unity_places_place_view_set_place (UnityPlacesPlaceView* self, UnityPlacesPlace* value);
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
GeeArrayList* unity_places_place_get_entries (UnityPlacesPlace* self);
UnityPlacesPlaceEntryView* unity_places_place_entry_view_new (UnityPlacesPlaceEntry* entry);
UnityPlacesPlaceEntryView* unity_places_place_entry_view_construct (GType object_type, UnityPlacesPlaceEntry* entry);
static gboolean _unity_places_place_view_on_entry_clicked_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static GObject * unity_places_place_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_view_finalize (GObject* obj);
static void unity_places_place_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlaceView* unity_places_place_view_construct (GType object_type, UnityPlacesPlace* place) {
	UnityPlacesPlaceView * self;
	g_return_val_if_fail (place != NULL, NULL);
	self = (UnityPlacesPlaceView*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "place", place, "spacing", 0, NULL);
	return self;
}


UnityPlacesPlaceView* unity_places_place_view_new (UnityPlacesPlace* place) {
	return unity_places_place_view_construct (UNITY_PLACES_TYPE_PLACE_VIEW, place);
}


static gboolean unity_places_place_view_on_entry_clicked (UnityPlacesPlaceView* self, ClutterActor* view, ClutterEvent* e) {
	gboolean result = FALSE;
	ClutterActor* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (view != NULL, FALSE);
	if ((*e).button.button != 1) {
		result = TRUE;
		return result;
	}
	g_signal_emit_by_name (self, "entry-activated", (_tmp0_ = view, UNITY_PLACES_IS_PLACE_ENTRY_VIEW (_tmp0_) ? ((UnityPlacesPlaceEntryView*) _tmp0_) : NULL));
	result = FALSE;
	return result;
}


UnityPlacesPlace* unity_places_place_view_get_place (UnityPlacesPlaceView* self) {
	UnityPlacesPlace* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_place;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_places_place_view_set_place (UnityPlacesPlaceView* self, UnityPlacesPlace* value) {
	UnityPlacesPlace* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_place = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_place), _tmp0_);
	g_object_notify ((GObject *) self, "place");
}


static gboolean _unity_places_place_view_on_entry_clicked_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_places_place_view_on_entry_clicked (self, _sender, event);
	return result;
}


static GObject * unity_places_place_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceView * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_VIEW (obj);
	{
		{
			GeeIterator* _entry_it;
			_entry_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) unity_places_place_get_entries (self->priv->_place));
			while (TRUE) {
				UnityPlacesPlaceEntry* entry;
				UnityPlacesPlaceEntryView* view;
				if (!gee_iterator_next (_entry_it)) {
					break;
				}
				entry = (UnityPlacesPlaceEntry*) gee_iterator_get (_entry_it);
				view = g_object_ref_sink (unity_places_place_entry_view_new (entry));
				clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) view);
				clutter_actor_show ((ClutterActor*) view);
				g_signal_connect_object ((ClutterActor*) view, "button-release-event", (GCallback) _unity_places_place_view_on_entry_clicked_clutter_actor_button_release_event, self, 0);
				_g_object_unref0 (view);
				_g_object_unref0 (entry);
			}
			_g_object_unref0 (_entry_it);
		}
	}
	return obj;
}


static void unity_places_place_view_class_init (UnityPlacesPlaceViewClass * klass) {
	unity_places_place_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_VIEW_PLACE, g_param_spec_object ("place", "place", "place", UNITY_PLACES_TYPE_PLACE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("entry_activated", UNITY_PLACES_TYPE_PLACE_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW);
}


static void unity_places_place_view_instance_init (UnityPlacesPlaceView * self) {
	self->priv = UNITY_PLACES_PLACE_VIEW_GET_PRIVATE (self);
}


static void unity_places_place_view_finalize (GObject* obj) {
	UnityPlacesPlaceView * self;
	self = UNITY_PLACES_PLACE_VIEW (obj);
	_g_object_unref0 (self->priv->_place);
	G_OBJECT_CLASS (unity_places_place_view_parent_class)->finalize (obj);
}


GType unity_places_place_view_get_type (void) {
	static volatile gsize unity_places_place_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceView), 0, (GInstanceInitFunc) unity_places_place_view_instance_init, NULL };
		GType unity_places_place_view_type_id;
		unity_places_place_view_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesPlaceView", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_view_type_id__volatile, unity_places_place_view_type_id);
	}
	return unity_places_place_view_type_id__volatile;
}


static void unity_places_place_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceView * self;
	self = UNITY_PLACES_PLACE_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_VIEW_PLACE:
		g_value_set_object (value, unity_places_place_view_get_place (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceView * self;
	self = UNITY_PLACES_PLACE_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_VIEW_PLACE:
		unity_places_place_view_set_place (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




