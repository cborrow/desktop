/* theme.c generated by valac, the Vala compiler
 * generated from theme.vala, do not modify */

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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <gdk-pixbuf/gdk-pixdata.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TYPE_THEME_IMAGE (unity_theme_image_get_type ())
#define UNITY_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImage))
#define UNITY_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))
#define UNITY_IS_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_IMAGE))
#define UNITY_IS_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_IMAGE))
#define UNITY_THEME_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))

typedef struct _UnityThemeImage UnityThemeImage;
typedef struct _UnityThemeImageClass UnityThemeImageClass;
typedef struct _UnityThemeImagePrivate UnityThemeImagePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _gtk_icon_info_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_info_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityThemeImage {
	ClutterTexture parent_instance;
	UnityThemeImagePrivate * priv;
	GdkPixbuf* icon;
};

struct _UnityThemeImageClass {
	ClutterTextureClass parent_class;
};

struct _UnityThemeImagePrivate {
	char* _icon_name;
};


static GtkIconTheme* unity_theme_image_theme;
static GtkIconTheme* unity_theme_image_theme = NULL;
static gpointer unity_theme_image_parent_class = NULL;

gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme);
GType unity_theme_image_get_type (void);
#define UNITY_THEME_IMAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_THEME_IMAGE, UnityThemeImagePrivate))
enum  {
	UNITY_THEME_IMAGE_DUMMY_PROPERTY,
	UNITY_THEME_IMAGE_ICON_NAME
};
UnityThemeImage* unity_theme_image_new (const char* icon_name);
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name);
const char* unity_theme_image_get_icon_name (UnityThemeImage* self);
static gboolean unity_theme_image_try_load_icon_from_theme (UnityThemeImage* self);
static gboolean unity_theme_image_try_load_icon_from_dir (UnityThemeImage* self, const char* dir);
static gboolean unity_theme_image_try_load_icon_from_datadir (UnityThemeImage* self);
static void unity_theme_image_load_missing_icon (UnityThemeImage* self);
void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value);
static GObject * unity_theme_image_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_theme_image_finalize (GObject* obj);
static void unity_theme_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_theme_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 22 "theme.vala"
gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme) {
#line 91 "theme.c"
	gboolean result;
	GtkIconTheme* icontheme;
#line 22 "theme.vala"
	g_return_val_if_fail (icon_name != NULL, FALSE);
#line 22 "theme.vala"
	g_return_val_if_fail (theme != NULL, FALSE);
#line 24 "theme.vala"
	icontheme = gtk_icon_theme_new ();
#line 25 "theme.vala"
	gtk_icon_theme_set_custom_theme (icontheme, theme);
#line 102 "theme.c"
	result = gtk_icon_theme_has_icon (icontheme, icon_name);
	_g_object_unref0 (icontheme);
#line 26 "theme.vala"
	return result;
#line 107 "theme.c"
}


#line 42 "theme.vala"
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name) {
#line 113 "theme.c"
	UnityThemeImage * self;
#line 42 "theme.vala"
	g_return_val_if_fail (icon_name != NULL, NULL);
#line 44 "theme.vala"
	self = (UnityThemeImage*) g_object_new (object_type, "icon-name", icon_name, NULL);
#line 119 "theme.c"
	return self;
}


#line 42 "theme.vala"
UnityThemeImage* unity_theme_image_new (const char* icon_name) {
#line 42 "theme.vala"
	return unity_theme_image_construct (UNITY_TYPE_THEME_IMAGE, icon_name);
#line 128 "theme.c"
}


#line 60 "theme.vala"
static gboolean unity_theme_image_try_load_icon_from_theme (UnityThemeImage* self) {
#line 134 "theme.c"
	gboolean result;
	GError * _inner_error_;
	GtkIconInfo* info;
#line 60 "theme.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 140 "theme.c"
	_inner_error_ = NULL;
#line 63 "theme.vala"
	info = gtk_icon_theme_lookup_icon (unity_theme_image_theme, self->priv->_icon_name, 24, 0);
#line 66 "theme.vala"
	if (info != NULL) {
#line 146 "theme.c"
		char* filename;
#line 68 "theme.vala"
		filename = g_strdup (gtk_icon_info_get_filename (info));
#line 70 "theme.vala"
		if (strstr (filename, "unity-icon-theme") != NULL) {
#line 152 "theme.c"
			{
#line 74 "theme.vala"
				clutter_texture_set_from_file ((ClutterTexture*) self, filename, &_inner_error_);
#line 156 "theme.c"
				if (_inner_error_ != NULL) {
					goto __catch10_g_error;
				}
				result = TRUE;
				_g_free0 (filename);
				_gtk_icon_info_free0 (info);
#line 80 "theme.vala"
				return result;
#line 165 "theme.c"
			}
			goto __finally10;
			__catch10_g_error:
			{
				GError * e;
				e = _inner_error_;
				_inner_error_ = NULL;
				{
					result = FALSE;
					_g_error_free0 (e);
					_g_free0 (filename);
					_gtk_icon_info_free0 (info);
#line 84 "theme.vala"
					return result;
#line 180 "theme.c"
				}
			}
			__finally10:
			if (_inner_error_ != NULL) {
				_g_free0 (filename);
				_gtk_icon_info_free0 (info);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return FALSE;
			}
		}
		result = FALSE;
		_g_free0 (filename);
		_gtk_icon_info_free0 (info);
#line 87 "theme.vala"
		return result;
#line 197 "theme.c"
	}
	result = FALSE;
	_gtk_icon_info_free0 (info);
#line 89 "theme.vala"
	return result;
#line 203 "theme.c"
}


#line 92 "theme.vala"
static gboolean unity_theme_image_try_load_icon_from_dir (UnityThemeImage* self, const char* dir) {
#line 209 "theme.c"
	gboolean result;
	GError * _inner_error_;
	char* filename;
	char* _tmp1_;
	char* _tmp0_;
#line 92 "theme.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 92 "theme.vala"
	g_return_val_if_fail (dir != NULL, FALSE);
#line 219 "theme.c"
	_inner_error_ = NULL;
	filename = NULL;
#line 96 "theme.vala"
	filename = (_tmp1_ = g_build_filename (dir, _tmp0_ = g_strconcat (self->priv->_icon_name, ".png", NULL), NULL), _g_free0 (filename), _tmp1_);
#line 224 "theme.c"
	_g_free0 (_tmp0_);
	{
#line 100 "theme.vala"
		clutter_texture_set_from_file ((ClutterTexture*) self, filename, &_inner_error_);
#line 229 "theme.c"
		if (_inner_error_ != NULL) {
			goto __catch11_g_error;
		}
		result = TRUE;
		_g_free0 (filename);
#line 106 "theme.vala"
		return result;
#line 237 "theme.c"
	}
	goto __finally11;
	__catch11_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			result = FALSE;
			_g_error_free0 (e);
			_g_free0 (filename);
#line 110 "theme.vala"
			return result;
#line 251 "theme.c"
		}
	}
	__finally11:
	if (_inner_error_ != NULL) {
		_g_free0 (filename);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	_g_free0 (filename);
}


#line 114 "theme.vala"
static gboolean unity_theme_image_try_load_icon_from_datadir (UnityThemeImage* self) {
#line 267 "theme.c"
	gboolean result;
#line 114 "theme.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 116 "theme.vala"
	if (!unity_theme_image_try_load_icon_from_dir (self, PKGDATADIR)) {
#line 117 "theme.vala"
		if (!unity_theme_image_try_load_icon_from_dir (self, "/usr/share/unity/themes")) {
#line 118 "theme.vala"
			if (!unity_theme_image_try_load_icon_from_dir (self, "/usr/share/unity/themes/launcher")) {
#line 277 "theme.c"
				result = FALSE;
#line 119 "theme.vala"
				return result;
#line 281 "theme.c"
			}
		}
	}
	result = TRUE;
#line 121 "theme.vala"
	return result;
#line 288 "theme.c"
}


#line 124 "theme.vala"
static void unity_theme_image_load_missing_icon (UnityThemeImage* self) {
#line 124 "theme.vala"
	g_return_if_fail (self != NULL);
#line 296 "theme.c"
	;
#line 136 "theme.vala"
	g_warning ("theme.vala:136: Unable to load '%s' from Unity icon theme or Unity theme", self->priv->_icon_name);
#line 300 "theme.c"
}


const char* unity_theme_image_get_icon_name (UnityThemeImage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon_name;
#line 38 "theme.vala"
	return result;
#line 310 "theme.c"
}


void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon_name), _tmp0_);
	g_object_notify ((GObject *) self, "icon-name");
}


static GObject * unity_theme_image_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityThemeImage * self;
	parent_class = G_OBJECT_CLASS (unity_theme_image_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_THEME_IMAGE (obj);
	{
#line 49 "theme.vala"
		if (unity_theme_image_theme == NULL) {
#line 332 "theme.c"
			GtkIconTheme* _tmp0_;
#line 51 "theme.vala"
			unity_theme_image_theme = (_tmp0_ = gtk_icon_theme_new (), _g_object_unref0 (unity_theme_image_theme), _tmp0_);
#line 52 "theme.vala"
			gtk_icon_theme_set_custom_theme (unity_theme_image_theme, "unity-icon-theme");
#line 338 "theme.c"
		}
#line 55 "theme.vala"
		if (!unity_theme_image_try_load_icon_from_datadir (self)) {
#line 56 "theme.vala"
			if (!unity_theme_image_try_load_icon_from_theme (self)) {
#line 57 "theme.vala"
				unity_theme_image_load_missing_icon (self);
#line 346 "theme.c"
			}
		}
	}
	return obj;
}


static void unity_theme_image_class_init (UnityThemeImageClass * klass) {
	unity_theme_image_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityThemeImagePrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_theme_image_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_theme_image_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_theme_image_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_theme_image_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_THEME_IMAGE_ICON_NAME, g_param_spec_string ("icon-name", "icon-name", "icon-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void unity_theme_image_instance_init (UnityThemeImage * self) {
	self->priv = UNITY_THEME_IMAGE_GET_PRIVATE (self);
}


static void unity_theme_image_finalize (GObject* obj) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (obj);
	_g_free0 (self->priv->_icon_name);
	_g_object_unref0 (self->icon);
	G_OBJECT_CLASS (unity_theme_image_parent_class)->finalize (obj);
}


GType unity_theme_image_get_type (void) {
	static GType unity_theme_image_type_id = 0;
	if (unity_theme_image_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityThemeImageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_theme_image_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityThemeImage), 0, (GInstanceInitFunc) unity_theme_image_instance_init, NULL };
		unity_theme_image_type_id = g_type_register_static (CLUTTER_TYPE_TEXTURE, "UnityThemeImage", &g_define_type_info, 0);
	}
	return unity_theme_image_type_id;
}


static void unity_theme_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (object);
	switch (property_id) {
		case UNITY_THEME_IMAGE_ICON_NAME:
		g_value_set_string (value, unity_theme_image_get_icon_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_theme_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (object);
	switch (property_id) {
		case UNITY_THEME_IMAGE_ICON_NAME:
		unity_theme_image_set_icon_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




