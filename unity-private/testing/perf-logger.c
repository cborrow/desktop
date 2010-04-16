/* perf-logger.c generated by valac, the Vala compiler
 * generated from perf-logger.vala, do not modify */

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
 * Authored by Gord Allott <gord.allott@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <gee.h>
#include <gio/gio.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TYPE_PROCESS_INFO (unity_process_info_get_type ())
#define UNITY_PROCESS_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_PROCESS_INFO, UnityProcessInfo))
#define UNITY_PROCESS_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_PROCESS_INFO, UnityProcessInfoClass))
#define UNITY_IS_PROCESS_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_PROCESS_INFO))
#define UNITY_IS_PROCESS_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_PROCESS_INFO))
#define UNITY_PROCESS_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_PROCESS_INFO, UnityProcessInfoClass))

typedef struct _UnityProcessInfo UnityProcessInfo;
typedef struct _UnityProcessInfoClass UnityProcessInfoClass;
typedef struct _UnityProcessInfoPrivate UnityProcessInfoPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityParamSpecProcessInfo UnityParamSpecProcessInfo;

#define UNITY_TYPE_TIMELINE_LOGGER (unity_timeline_logger_get_type ())
#define UNITY_TIMELINE_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLogger))
#define UNITY_TIMELINE_LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLoggerClass))
#define UNITY_IS_TIMELINE_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_TIMELINE_LOGGER))
#define UNITY_IS_TIMELINE_LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_TIMELINE_LOGGER))
#define UNITY_TIMELINE_LOGGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLoggerClass))

typedef struct _UnityTimelineLogger UnityTimelineLogger;
typedef struct _UnityTimelineLoggerClass UnityTimelineLoggerClass;
typedef struct _UnityTimelineLoggerPrivate UnityTimelineLoggerPrivate;
#define _g_timer_destroy0(var) ((var == NULL) ? NULL : (var = (g_timer_destroy (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _unity_process_info_unref0(var) ((var == NULL) ? NULL : (var = (unity_process_info_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityProcessInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityProcessInfoPrivate * priv;
	char* name;
	double start;
	double end;
};

struct _UnityProcessInfoClass {
	GTypeClass parent_class;
	void (*finalize) (UnityProcessInfo *self);
};

struct _UnityParamSpecProcessInfo {
	GParamSpec parent_instance;
};

struct _UnityTimelineLogger {
	GObject parent_instance;
	UnityTimelineLoggerPrivate * priv;
};

struct _UnityTimelineLoggerClass {
	GObjectClass parent_class;
};

struct _UnityTimelineLoggerPrivate {
	GTimer* global_timer;
	GeeHashMap* process_map;
};


static gpointer unity_process_info_parent_class = NULL;
extern UnityTimelineLogger* unity_timeline_singleton;
UnityTimelineLogger* unity_timeline_singleton = NULL;
extern gboolean unity_is_logging;
gboolean unity_is_logging = FALSE;
static gpointer unity_timeline_logger_parent_class = NULL;

gpointer unity_process_info_ref (gpointer instance);
void unity_process_info_unref (gpointer instance);
GParamSpec* unity_param_spec_process_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_value_set_process_info (GValue* value, gpointer v_object);
void unity_value_take_process_info (GValue* value, gpointer v_object);
gpointer unity_value_get_process_info (const GValue* value);
GType unity_process_info_get_type (void);
enum  {
	UNITY_PROCESS_INFO_DUMMY_PROPERTY
};
UnityProcessInfo* unity_process_info_new (const char* name);
UnityProcessInfo* unity_process_info_construct (GType object_type, const char* name);
static void unity_process_info_finalize (UnityProcessInfo* obj);
GType unity_timeline_logger_get_type (void);
#define UNITY_TIMELINE_LOGGER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLoggerPrivate))
enum  {
	UNITY_TIMELINE_LOGGER_DUMMY_PROPERTY
};
UnityTimelineLogger* unity_timeline_logger_new (void);
UnityTimelineLogger* unity_timeline_logger_construct (GType object_type);
UnityTimelineLogger* unity_timeline_logger_get_default (void);
void unity_timeline_logger_start_process (UnityTimelineLogger* self, const char* name);
void unity_timeline_logger_end_process (UnityTimelineLogger* self, const char* name);
void unity_timeline_logger_write_log (UnityTimelineLogger* self, const char* filename);
static GObject * unity_timeline_logger_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_timeline_logger_finalize (GObject* obj);



UnityProcessInfo* unity_process_info_construct (GType object_type, const char* name) {
	UnityProcessInfo* self;
	char* _tmp0_;
	g_return_val_if_fail (name != NULL, NULL);
	self = (UnityProcessInfo*) g_type_create_instance (object_type);
	self->name = (_tmp0_ = g_strdup (name), _g_free0 (self->name), _tmp0_);
	self->start = (double) 0;
	self->end = (double) 0;
	return self;
}


UnityProcessInfo* unity_process_info_new (const char* name) {
	return unity_process_info_construct (UNITY_TYPE_PROCESS_INFO, name);
}


static void unity_value_process_info_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_value_process_info_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_process_info_unref (value->data[0].v_pointer);
	}
}


static void unity_value_process_info_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_process_info_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_value_process_info_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_value_process_info_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityProcessInfo* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_process_info_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_value_process_info_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityProcessInfo** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_process_info_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_param_spec_process_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityParamSpecProcessInfo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TYPE_PROCESS_INFO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_value_get_process_info (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TYPE_PROCESS_INFO), NULL);
	return value->data[0].v_pointer;
}


void unity_value_set_process_info (GValue* value, gpointer v_object) {
	UnityProcessInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TYPE_PROCESS_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TYPE_PROCESS_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_process_info_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_process_info_unref (old);
	}
}


void unity_value_take_process_info (GValue* value, gpointer v_object) {
	UnityProcessInfo* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TYPE_PROCESS_INFO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TYPE_PROCESS_INFO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_process_info_unref (old);
	}
}


static void unity_process_info_class_init (UnityProcessInfoClass * klass) {
	unity_process_info_parent_class = g_type_class_peek_parent (klass);
	UNITY_PROCESS_INFO_CLASS (klass)->finalize = unity_process_info_finalize;
}


static void unity_process_info_instance_init (UnityProcessInfo * self) {
	self->ref_count = 1;
}


static void unity_process_info_finalize (UnityProcessInfo* obj) {
	UnityProcessInfo * self;
	self = UNITY_PROCESS_INFO (obj);
	_g_free0 (self->name);
}


GType unity_process_info_get_type (void) {
	static volatile gsize unity_process_info_type_id__volatile = 0;
	if (g_once_init_enter (&unity_process_info_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_value_process_info_init, unity_value_process_info_free_value, unity_value_process_info_copy_value, unity_value_process_info_peek_pointer, "p", unity_value_process_info_collect_value, "p", unity_value_process_info_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityProcessInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_process_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityProcessInfo), 0, (GInstanceInitFunc) unity_process_info_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_process_info_type_id;
		unity_process_info_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityProcessInfo", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_process_info_type_id__volatile, unity_process_info_type_id);
	}
	return unity_process_info_type_id__volatile;
}


gpointer unity_process_info_ref (gpointer instance) {
	UnityProcessInfo* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_process_info_unref (gpointer instance) {
	UnityProcessInfo* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_PROCESS_INFO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


UnityTimelineLogger* unity_timeline_logger_get_default (void) {
	UnityTimelineLogger* result = NULL;
	if (unity_timeline_singleton == NULL) {
		UnityTimelineLogger* _tmp0_;
		unity_timeline_singleton = (_tmp0_ = unity_timeline_logger_new (), _g_object_unref0 (unity_timeline_singleton), _tmp0_);
	}
	result = unity_timeline_singleton;
	return result;
}


void unity_timeline_logger_start_process (UnityTimelineLogger* self, const char* name) {
	GeeSet* _tmp0_;
	gboolean _tmp1_;
	UnityProcessInfo* info;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	if ((_tmp1_ = gee_collection_contains ((GeeCollection*) (_tmp0_ = gee_map_get_keys ((GeeMap*) self->priv->process_map)), name), _g_object_unref0 (_tmp0_), _tmp1_)) {
		g_warning ("perf-logger.vala:65: already started process: %s", name);
		return;
	}
	info = unity_process_info_new (name);
	gee_abstract_map_set ((GeeAbstractMap*) self->priv->process_map, name, info);
	info->start = g_timer_elapsed (self->priv->global_timer, NULL);
	_unity_process_info_unref0 (info);
}


void unity_timeline_logger_end_process (UnityTimelineLogger* self, const char* name) {
	double end_time;
	GeeSet* _tmp0_;
	gboolean _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	end_time = g_timer_elapsed (self->priv->global_timer, NULL);
	if ((_tmp1_ = gee_collection_contains ((GeeCollection*) (_tmp0_ = gee_map_get_keys ((GeeMap*) self->priv->process_map)), name), _g_object_unref0 (_tmp0_), _tmp1_)) {
		UnityProcessInfo* _tmp2_;
		(_tmp2_ = (UnityProcessInfo*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->process_map, name))->end = end_time;
		_unity_process_info_unref0 (_tmp2_);
	} else {
		g_warning ("perf-logger.vala:84: process %s not started", name);
	}
}


void unity_timeline_logger_write_log (UnityTimelineLogger* self, const char* filename) {
	GError * _inner_error_;
	GFile* log_file;
	GFileOutputStream* file_stream;
	g_return_if_fail (self != NULL);
	g_return_if_fail (filename != NULL);
	_inner_error_ = NULL;
	g_debug ("perf-logger.vala:90: Writing performance log file: %s...", filename);
	log_file = g_file_new_for_path (filename);
	file_stream = NULL;
	{
		GDataOutputStream* output_stream;
		if (!g_file_query_exists (log_file, NULL)) {
			GFileOutputStream* _tmp0_;
			GFileOutputStream* _tmp1_;
			_tmp0_ = g_file_create (log_file, G_FILE_CREATE_NONE, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch35_g_error;
			}
			file_stream = (_tmp1_ = _tmp0_, _g_object_unref0 (file_stream), _tmp1_);
		} else {
			GFileOutputStream* _tmp2_;
			GFileOutputStream* _tmp3_;
			_tmp2_ = g_file_replace (log_file, NULL, FALSE, G_FILE_CREATE_NONE, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch35_g_error;
			}
			file_stream = (_tmp3_ = _tmp2_, _g_object_unref0 (file_stream), _tmp3_);
		}
		output_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
		{
			GeeCollection* _tmp4_;
			GeeIterator* _tmp5_;
			GeeIterator* _info_it;
			_info_it = (_tmp5_ = gee_iterable_iterator ((GeeIterable*) (_tmp4_ = gee_map_get_values ((GeeMap*) self->priv->process_map))), _g_object_unref0 (_tmp4_), _tmp5_);
			while (TRUE) {
				UnityProcessInfo* info;
				char* outline;
				if (!gee_iterator_next (_info_it)) {
					break;
				}
				info = (UnityProcessInfo*) gee_iterator_get (_info_it);
				outline = g_strdup_printf ("%s, %f, %f\n", info->name, info->start, info->end);
				g_data_output_stream_put_string (output_stream, outline, NULL, &_inner_error_);
				if (_inner_error_ != NULL) {
					_unity_process_info_unref0 (info);
					_g_free0 (outline);
					_g_object_unref0 (_info_it);
					_g_object_unref0 (output_stream);
					goto __catch35_g_error;
				}
				_unity_process_info_unref0 (info);
				_g_free0 (outline);
			}
			_g_object_unref0 (_info_it);
		}
		g_output_stream_close ((GOutputStream*) file_stream, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (output_stream);
			goto __catch35_g_error;
		}
		_g_object_unref0 (output_stream);
	}
	goto __finally35;
	__catch35_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("perf-logger.vala:114: %s", e->message);
			_g_error_free0 (e);
		}
	}
	__finally35:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (log_file);
		_g_object_unref0 (file_stream);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_debug ("perf-logger.vala:116: Done writing performance log file: %s", filename);
	_g_object_unref0 (log_file);
	_g_object_unref0 (file_stream);
}


UnityTimelineLogger* unity_timeline_logger_construct (GType object_type) {
	UnityTimelineLogger * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


UnityTimelineLogger* unity_timeline_logger_new (void) {
	return unity_timeline_logger_construct (UNITY_TYPE_TIMELINE_LOGGER);
}


static GObject * unity_timeline_logger_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTimelineLogger * self;
	parent_class = G_OBJECT_CLASS (unity_timeline_logger_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TIMELINE_LOGGER (obj);
	{
		GeeHashMap* _tmp0_;
		GTimer* _tmp1_;
		self->priv->process_map = (_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, UNITY_TYPE_PROCESS_INFO, (GBoxedCopyFunc) unity_process_info_ref, unity_process_info_unref, NULL, NULL, NULL), _g_object_unref0 (self->priv->process_map), _tmp0_);
		self->priv->global_timer = (_tmp1_ = g_timer_new (), _g_timer_destroy0 (self->priv->global_timer), _tmp1_);
		g_timer_start (self->priv->global_timer);
	}
	return obj;
}


static void unity_timeline_logger_class_init (UnityTimelineLoggerClass * klass) {
	unity_timeline_logger_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTimelineLoggerPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_timeline_logger_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_timeline_logger_finalize;
}


static void unity_timeline_logger_instance_init (UnityTimelineLogger * self) {
	self->priv = UNITY_TIMELINE_LOGGER_GET_PRIVATE (self);
}


static void unity_timeline_logger_finalize (GObject* obj) {
	UnityTimelineLogger * self;
	self = UNITY_TIMELINE_LOGGER (obj);
	_g_timer_destroy0 (self->priv->global_timer);
	_g_object_unref0 (self->priv->process_map);
	G_OBJECT_CLASS (unity_timeline_logger_parent_class)->finalize (obj);
}


GType unity_timeline_logger_get_type (void) {
	static volatile gsize unity_timeline_logger_type_id__volatile = 0;
	if (g_once_init_enter (&unity_timeline_logger_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTimelineLoggerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_timeline_logger_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTimelineLogger), 0, (GInstanceInitFunc) unity_timeline_logger_instance_init, NULL };
		GType unity_timeline_logger_type_id;
		unity_timeline_logger_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTimelineLogger", &g_define_type_info, 0);
		g_once_init_leave (&unity_timeline_logger_type_id__volatile, unity_timeline_logger_type_id);
	}
	return unity_timeline_logger_type_id__volatile;
}




