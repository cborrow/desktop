/* places-place-entry-view.c generated by valac, the Vala compiler
 * generated from places-place-entry-view.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW (unity_places_place_entry_view_get_type ())
#define UNITY_PLACES_PLACE_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryView))
#define UNITY_PLACES_PLACE_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryViewClass))
#define UNITY_PLACES_IS_PLACE_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW))
#define UNITY_PLACES_IS_PLACE_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW))
#define UNITY_PLACES_PLACE_ENTRY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryViewClass))

typedef struct _UnityPlacesPlaceEntryView UnityPlacesPlaceEntryView;
typedef struct _UnityPlacesPlaceEntryViewClass UnityPlacesPlaceEntryViewClass;
typedef struct _UnityPlacesPlaceEntryViewPrivate UnityPlacesPlaceEntryViewPrivate;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_PLACE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryClass))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_IS_PLACE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryClass))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryClass UnityPlacesPlaceEntryClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityPlacesPlaceEntryView {
	CtkImage parent_instance;
	UnityPlacesPlaceEntryViewPrivate * priv;
};

struct _UnityPlacesPlaceEntryViewClass {
	CtkImageClass parent_class;
};

struct _UnityPlacesPlaceEntryViewPrivate {
	UnityPlacesPlaceEntry* _entry;
};


static gpointer unity_places_place_entry_view_parent_class = NULL;

GType unity_places_place_entry_view_get_type (void);
GType unity_places_place_entry_get_type (void);
#define UNITY_PLACES_PLACE_ENTRY_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, UnityPlacesPlaceEntryViewPrivate))
enum  {
	UNITY_PLACES_PLACE_ENTRY_VIEW_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_ENTRY_VIEW_ENTRY
};
#define UNITY_PLACES_PLACE_ENTRY_VIEW_WIDTH 80
const char* unity_places_place_entry_get_icon (UnityPlacesPlaceEntry* self);
UnityPlacesPlaceEntryView* unity_places_place_entry_view_new (UnityPlacesPlaceEntry* entry);
UnityPlacesPlaceEntryView* unity_places_place_entry_view_construct (GType object_type, UnityPlacesPlaceEntry* entry);
static void unity_places_place_entry_view_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width);
UnityPlacesPlaceEntry* unity_places_place_entry_view_get_entry (UnityPlacesPlaceEntryView* self);
static void unity_places_place_entry_view_set_entry (UnityPlacesPlaceEntryView* self, UnityPlacesPlaceEntry* value);
static GObject * unity_places_place_entry_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_entry_view_finalize (GObject* obj);
static void unity_places_place_entry_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_entry_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlaceEntryView* unity_places_place_entry_view_construct (GType object_type, UnityPlacesPlaceEntry* entry) {
	UnityPlacesPlaceEntryView * self;
	g_return_val_if_fail (entry != NULL, NULL);
	self = (UnityPlacesPlaceEntryView*) g_object_new (object_type, "entry", entry, "size", 48, "reactive", TRUE, NULL);
	ctk_image_set_from_filename ((CtkImage*) self, unity_places_place_entry_get_icon (entry));
	return self;
}


UnityPlacesPlaceEntryView* unity_places_place_entry_view_new (UnityPlacesPlaceEntry* entry) {
	return unity_places_place_entry_view_construct (UNITY_PLACES_TYPE_PLACE_ENTRY_VIEW, entry);
}


static void unity_places_place_entry_view_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width) {
	UnityPlacesPlaceEntryView * self;
	self = (UnityPlacesPlaceEntryView*) base;
	*min_width = (float) UNITY_PLACES_PLACE_ENTRY_VIEW_WIDTH;
	*nat_width = (float) UNITY_PLACES_PLACE_ENTRY_VIEW_WIDTH;
}


UnityPlacesPlaceEntry* unity_places_place_entry_view_get_entry (UnityPlacesPlaceEntryView* self) {
	UnityPlacesPlaceEntry* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_entry;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_places_place_entry_view_set_entry (UnityPlacesPlaceEntryView* self, UnityPlacesPlaceEntry* value) {
	UnityPlacesPlaceEntry* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_entry = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_entry), _tmp0_);
	g_object_notify ((GObject *) self, "entry");
}


static GObject * unity_places_place_entry_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceEntryView * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_entry_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_ENTRY_VIEW (obj);
	{
	}
	return obj;
}


static void unity_places_place_entry_view_class_init (UnityPlacesPlaceEntryViewClass * klass) {
	unity_places_place_entry_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceEntryViewPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_places_place_entry_view_real_get_preferred_width;
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_entry_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_entry_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_entry_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_entry_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_ENTRY_VIEW_ENTRY, g_param_spec_object ("entry", "entry", "entry", UNITY_PLACES_TYPE_PLACE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_place_entry_view_instance_init (UnityPlacesPlaceEntryView * self) {
	self->priv = UNITY_PLACES_PLACE_ENTRY_VIEW_GET_PRIVATE (self);
}


static void unity_places_place_entry_view_finalize (GObject* obj) {
	UnityPlacesPlaceEntryView * self;
	self = UNITY_PLACES_PLACE_ENTRY_VIEW (obj);
	_g_object_unref0 (self->priv->_entry);
	G_OBJECT_CLASS (unity_places_place_entry_view_parent_class)->finalize (obj);
}


GType unity_places_place_entry_view_get_type (void) {
	static volatile gsize unity_places_place_entry_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_entry_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceEntryViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_entry_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceEntryView), 0, (GInstanceInitFunc) unity_places_place_entry_view_instance_init, NULL };
		GType unity_places_place_entry_view_type_id;
		unity_places_place_entry_view_type_id = g_type_register_static (CTK_TYPE_IMAGE, "UnityPlacesPlaceEntryView", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_entry_view_type_id__volatile, unity_places_place_entry_view_type_id);
	}
	return unity_places_place_entry_view_type_id__volatile;
}


static void unity_places_place_entry_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceEntryView * self;
	self = UNITY_PLACES_PLACE_ENTRY_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_ENTRY_VIEW_ENTRY:
		g_value_set_object (value, unity_places_place_entry_view_get_entry (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_entry_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceEntryView * self;
	self = UNITY_PLACES_PLACE_ENTRY_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_ENTRY_VIEW_ENTRY:
		unity_places_place_entry_view_set_entry (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




