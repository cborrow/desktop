/* background.c generated by valac, the Vala compiler
 * generated from background.vala, do not modify */

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
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <gconf/gconf.h>
#include <gconf/gconf-client.h>
#include <unity-utils.h>


#define UNITY_TESTING_TYPE_BACKGROUND (unity_testing_background_get_type ())
#define UNITY_TESTING_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackground))
#define UNITY_TESTING_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundClass))
#define UNITY_TESTING_IS_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_BACKGROUND))
#define UNITY_TESTING_IS_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_BACKGROUND))
#define UNITY_TESTING_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundClass))

typedef struct _UnityTestingBackground UnityTestingBackground;
typedef struct _UnityTestingBackgroundClass UnityTestingBackgroundClass;
typedef struct _UnityTestingBackgroundPrivate UnityTestingBackgroundPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityTestingBackground {
	CtkBin parent_instance;
	UnityTestingBackgroundPrivate * priv;
};

struct _UnityTestingBackgroundClass {
	CtkBinClass parent_class;
};

struct _UnityTestingBackgroundPrivate {
	char* BG_DIR;
	char* BG_FILE;
	char* BG_OPTION;
	char* filename;
	char* option;
	ClutterTexture* bg;
};


static gpointer unity_testing_background_parent_class = NULL;

GType unity_testing_background_get_type (void);
#define UNITY_TESTING_BACKGROUND_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundPrivate))
enum  {
	UNITY_TESTING_BACKGROUND_DUMMY_PROPERTY
};
static void unity_testing_background_ensure_layout (UnityTestingBackground* self);
static void unity_testing_background_on_filename_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry);
static void unity_testing_background_on_option_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry);
UnityTestingBackground* unity_testing_background_new (void);
UnityTestingBackground* unity_testing_background_construct (GType object_type);
static void _unity_testing_background_on_filename_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self);
static void _unity_testing_background_on_option_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self);
static GObject * unity_testing_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_testing_background_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void unity_testing_background_on_filename_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry) {
	char* new_filename;
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (client != NULL);
	g_return_if_fail (entry != NULL);
	new_filename = g_strdup (gconf_value_get_string (gconf_entry_get_value (entry)));
	if (_vala_strcmp0 (new_filename, self->priv->filename) == 0) {
		_g_free0 (new_filename);
		return;
	}
	self->priv->filename = (_tmp0_ = g_strdup (new_filename), _g_free0 (self->priv->filename), _tmp0_);
	unity_testing_background_ensure_layout (self);
	_g_free0 (new_filename);
}


static void unity_testing_background_on_option_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry) {
	char* new_option;
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (client != NULL);
	g_return_if_fail (entry != NULL);
	new_option = g_strdup (gconf_value_get_string (gconf_entry_get_value (entry)));
	if (_vala_strcmp0 (new_option, self->priv->option) == 0) {
		_g_free0 (new_option);
		return;
	}
	self->priv->option = (_tmp0_ = g_strdup (new_option), _g_free0 (self->priv->option), _tmp0_);
	unity_testing_background_ensure_layout (self);
	_g_free0 (new_option);
}


static void unity_testing_background_ensure_layout (UnityTestingBackground* self) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	{
		clutter_texture_set_from_file (self->priv->bg, self->priv->filename, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch22_g_error;
		}
	}
	goto __finally22;
	__catch22_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("background.vala:130: Background: Unable to load background file %s: %s", self->priv->filename, e->message);
			_g_error_free0 (e);
		}
	}
	__finally22:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	clutter_actor_queue_relayout ((ClutterActor*) self);
}


UnityTestingBackground* unity_testing_background_construct (GType object_type) {
	UnityTestingBackground * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


UnityTestingBackground* unity_testing_background_new (void) {
	return unity_testing_background_construct (UNITY_TESTING_TYPE_BACKGROUND);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_testing_background_on_filename_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self) {
	unity_testing_background_on_filename_changed (self, client, cnxn_id, entry);
}


static void _unity_testing_background_on_option_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self) {
	unity_testing_background_on_option_changed (self, client, cnxn_id, entry);
}


static GObject * unity_testing_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTestingBackground * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_testing_background_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TESTING_BACKGROUND (obj);
	_inner_error_ = NULL;
	{
		GConfClient* client;
		ClutterTexture* _tmp6_;
		START_FUNCTION ();
		client = _g_object_ref0 (gconf_client_get_default ());
		{
			gconf_client_add_dir (client, self->priv->BG_DIR, GCONF_CLIENT_PRELOAD_NONE, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch23_g_error;
			}
		}
		goto __finally23;
		__catch23_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("background.vala:46: Background: Unable to monitor background: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally23:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp0_;
			char* _tmp1_;
			_tmp0_ = gconf_client_get_string (client, self->priv->BG_FILE, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch24_g_error;
			}
			self->priv->filename = (_tmp1_ = _tmp0_, _g_free0 (self->priv->filename), _tmp1_);
		}
		goto __finally24;
		__catch24_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp2_;
				self->priv->filename = (_tmp2_ = g_strdup ("/usr/share/backgrounds/warty-final.png"), _g_free0 (self->priv->filename), _tmp2_);
				_g_error_free0 (e);
			}
		}
		__finally24:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			gconf_client_notify_add (client, self->priv->BG_FILE, _unity_testing_background_on_filename_changed_gconf_client_notify_func, g_object_ref (self), g_object_unref, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch25_g_error;
			}
		}
		goto __finally25;
		__catch25_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("background.vala:64: Background: Unable to monitor background filename:" \
" %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally25:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp3_;
			char* _tmp4_;
			_tmp3_ = gconf_client_get_string (client, self->priv->BG_OPTION, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch26_g_error;
			}
			self->priv->option = (_tmp4_ = _tmp3_, _g_free0 (self->priv->option), _tmp4_);
		}
		goto __finally26;
		__catch26_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp5_;
				self->priv->option = (_tmp5_ = g_strdup ("wallpaper"), _g_free0 (self->priv->option), _tmp5_);
				_g_error_free0 (e);
			}
		}
		__finally26:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			gconf_client_notify_add (client, self->priv->BG_OPTION, _unity_testing_background_on_option_changed_gconf_client_notify_func, g_object_ref (self), g_object_unref, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch27_g_error;
			}
		}
		goto __finally27;
		__catch27_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("background.vala:81: Background: Unable to monitor background options: " \
"%s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally27:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		self->priv->bg = (_tmp6_ = g_object_ref_sink ((ClutterTexture*) clutter_texture_new ()), _g_object_unref0 (self->priv->bg), _tmp6_);
		clutter_texture_set_load_async (self->priv->bg, TRUE);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bg);
		clutter_actor_show ((ClutterActor*) self->priv->bg);
		unity_testing_background_ensure_layout (self);
		END_FUNCTION ();
		_g_object_unref0 (client);
	}
	return obj;
}


static void unity_testing_background_class_init (UnityTestingBackgroundClass * klass) {
	unity_testing_background_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestingBackgroundPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_testing_background_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_testing_background_finalize;
}


static void unity_testing_background_instance_init (UnityTestingBackground * self) {
	self->priv = UNITY_TESTING_BACKGROUND_GET_PRIVATE (self);
	self->priv->BG_DIR = g_strdup ("/desktop/gnome/background");
	self->priv->BG_FILE = g_strdup ("/desktop/gnome/background/picture_filename");
	self->priv->BG_OPTION = g_strdup ("/desktop/gnome/background/picture_options");
}


static void unity_testing_background_finalize (GObject* obj) {
	UnityTestingBackground * self;
	self = UNITY_TESTING_BACKGROUND (obj);
	_g_free0 (self->priv->BG_DIR);
	_g_free0 (self->priv->BG_FILE);
	_g_free0 (self->priv->BG_OPTION);
	_g_free0 (self->priv->filename);
	_g_free0 (self->priv->option);
	_g_object_unref0 (self->priv->bg);
	G_OBJECT_CLASS (unity_testing_background_parent_class)->finalize (obj);
}


GType unity_testing_background_get_type (void) {
	static volatile gsize unity_testing_background_type_id__volatile = 0;
	if (g_once_init_enter (&unity_testing_background_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestingBackgroundClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_testing_background_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestingBackground), 0, (GInstanceInitFunc) unity_testing_background_instance_init, NULL };
		GType unity_testing_background_type_id;
		unity_testing_background_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityTestingBackground", &g_define_type_info, 0);
		g_once_init_leave (&unity_testing_background_type_id__volatile, unity_testing_background_type_id);
	}
	return unity_testing_background_type_id__volatile;
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




