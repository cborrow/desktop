/* places-place.c generated by valac, the Vala compiler
 * generated from places-place.vala, do not modify */

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
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>


#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
typedef struct _UnityPlacesPlacePrivate UnityPlacesPlacePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _UnityPlacesPlace {
	GObject parent_instance;
	UnityPlacesPlacePrivate * priv;
};

struct _UnityPlacesPlaceClass {
	GObjectClass parent_class;
	ClutterActor* (*get_view) (UnityPlacesPlace* self);
};

struct _UnityPlacesPlacePrivate {
	char* _name;
	char* _icon_name;
	char* _comment;
	gboolean _active;
};


static gpointer unity_places_place_parent_class = NULL;

GType unity_places_place_get_type (void);
#define UNITY_PLACES_PLACE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlacePrivate))
enum  {
	UNITY_PLACES_PLACE_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_NAME,
	UNITY_PLACES_PLACE_ICON_NAME,
	UNITY_PLACES_PLACE_COMMENT,
	UNITY_PLACES_PLACE_ACTIVE
};
UnityPlacesPlace* unity_places_place_construct (GType object_type, const char* name, const char* icon_name);
ClutterActor* unity_places_place_get_view (UnityPlacesPlace* self);
static ClutterActor* unity_places_place_real_get_view (UnityPlacesPlace* self);
const char* unity_places_place_get_name (UnityPlacesPlace* self);
static void unity_places_place_set_name (UnityPlacesPlace* self, const char* value);
const char* unity_places_place_get_icon_name (UnityPlacesPlace* self);
static void unity_places_place_set_icon_name (UnityPlacesPlace* self, const char* value);
const char* unity_places_place_get_comment (UnityPlacesPlace* self);
static void unity_places_place_set_comment (UnityPlacesPlace* self, const char* value);
gboolean unity_places_place_get_active (UnityPlacesPlace* self);
void unity_places_place_set_active (UnityPlacesPlace* self, gboolean value);
static GObject * unity_places_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_finalize (GObject* obj);
static void unity_places_place_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlace* unity_places_place_construct (GType object_type, const char* name, const char* icon_name) {
	UnityPlacesPlace * self;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (icon_name != NULL, NULL);
	self = (UnityPlacesPlace*) g_object_new (object_type, "name", name, "icon-name", icon_name, NULL);
	return self;
}


static ClutterActor* unity_places_place_real_get_view (UnityPlacesPlace* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_places_place_get_view'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


ClutterActor* unity_places_place_get_view (UnityPlacesPlace* self) {
	return UNITY_PLACES_PLACE_GET_CLASS (self)->get_view (self);
}


const char* unity_places_place_get_name (UnityPlacesPlace* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_name;
	return result;
}


static void unity_places_place_set_name (UnityPlacesPlace* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_name), _tmp0_);
	g_object_notify ((GObject *) self, "name");
}


const char* unity_places_place_get_icon_name (UnityPlacesPlace* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon_name;
	return result;
}


static void unity_places_place_set_icon_name (UnityPlacesPlace* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon_name), _tmp0_);
	g_object_notify ((GObject *) self, "icon-name");
}


const char* unity_places_place_get_comment (UnityPlacesPlace* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_comment;
	return result;
}


static void unity_places_place_set_comment (UnityPlacesPlace* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_comment = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_comment), _tmp0_);
	g_object_notify ((GObject *) self, "comment");
}


gboolean unity_places_place_get_active (UnityPlacesPlace* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_active;
	return result;
}


void unity_places_place_set_active (UnityPlacesPlace* self, gboolean value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_active != value) {
		self->priv->_active = value;
		if (self->priv->_active) {
			g_signal_emit_by_name (self, "activated");
		}
	}
	g_object_notify ((GObject *) self, "active");
}


static GObject * unity_places_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlace * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE (obj);
	{
		self->priv->_active = FALSE;
	}
	return obj;
}


static void unity_places_place_class_init (UnityPlacesPlaceClass * klass) {
	unity_places_place_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlacePrivate));
	UNITY_PLACES_PLACE_CLASS (klass)->get_view = unity_places_place_real_get_view;
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_ICON_NAME, g_param_spec_string ("icon-name", "icon-name", "icon-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_COMMENT, g_param_spec_string ("comment", "comment", "comment", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_ACTIVE, g_param_spec_boolean ("active", "active", "active", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("activated", UNITY_PLACES_TYPE_PLACE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void unity_places_place_instance_init (UnityPlacesPlace * self) {
	self->priv = UNITY_PLACES_PLACE_GET_PRIVATE (self);
}


static void unity_places_place_finalize (GObject* obj) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (obj);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_icon_name);
	_g_free0 (self->priv->_comment);
	G_OBJECT_CLASS (unity_places_place_parent_class)->finalize (obj);
}


GType unity_places_place_get_type (void) {
	static volatile gsize unity_places_place_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlace), 0, (GInstanceInitFunc) unity_places_place_instance_init, NULL };
		GType unity_places_place_type_id;
		unity_places_place_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPlacesPlace", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&unity_places_place_type_id__volatile, unity_places_place_type_id);
	}
	return unity_places_place_type_id__volatile;
}


static void unity_places_place_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_NAME:
		g_value_set_string (value, unity_places_place_get_name (self));
		break;
		case UNITY_PLACES_PLACE_ICON_NAME:
		g_value_set_string (value, unity_places_place_get_icon_name (self));
		break;
		case UNITY_PLACES_PLACE_COMMENT:
		g_value_set_string (value, unity_places_place_get_comment (self));
		break;
		case UNITY_PLACES_PLACE_ACTIVE:
		g_value_set_boolean (value, unity_places_place_get_active (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_NAME:
		unity_places_place_set_name (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_ICON_NAME:
		unity_places_place_set_icon_name (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_COMMENT:
		unity_places_place_set_comment (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_ACTIVE:
		unity_places_place_set_active (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




