/* test-utils.c generated by valac, the Vala compiler
 * generated from test-utils.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define G_TEST_TYPE_LOG (g_test_log_get_type ())
#define G_TEST_LOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), G_TEST_TYPE_LOG, GTestLog))
#define G_TEST_LOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), G_TEST_TYPE_LOG, GTestLogClass))
#define G_TEST_IS_LOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), G_TEST_TYPE_LOG))
#define G_TEST_IS_LOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), G_TEST_TYPE_LOG))
#define G_TEST_LOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), G_TEST_TYPE_LOG, GTestLogClass))

typedef struct _GTestLog GTestLog;
typedef struct _GTestLogClass GTestLogClass;
typedef struct _GTestLogPrivate GTestLogPrivate;
typedef struct _GTestParamSpecLog GTestParamSpecLog;

#define UNITY_TESTING_TYPE_LOGGING (unity_testing_logging_get_type ())
#define UNITY_TESTING_LOGGING(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_LOGGING, UnityTestingLogging))
#define UNITY_TESTING_LOGGING_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_LOGGING, UnityTestingLoggingClass))
#define UNITY_TESTING_IS_LOGGING(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_LOGGING))
#define UNITY_TESTING_IS_LOGGING_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_LOGGING))
#define UNITY_TESTING_LOGGING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_LOGGING, UnityTestingLoggingClass))

typedef struct _UnityTestingLogging UnityTestingLogging;
typedef struct _UnityTestingLoggingClass UnityTestingLoggingClass;
typedef struct _UnityTestingLoggingPrivate UnityTestingLoggingPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityTestingParamSpecLogging UnityTestingParamSpecLogging;

struct _GTestLog {
	GTypeInstance parent_instance;
	volatile int ref_count;
	GTestLogPrivate * priv;
};

struct _GTestLogClass {
	GTypeClass parent_class;
	void (*finalize) (GTestLog *self);
};

typedef gboolean (*GTestLogLogFatalFunc) (const char* log_domain, GLogLevelFlags flags, const char* message, void* user_data);
struct _GTestParamSpecLog {
	GParamSpec parent_instance;
};

struct _UnityTestingLogging {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestingLoggingPrivate * priv;
};

struct _UnityTestingLoggingClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestingLogging *self);
};

struct _UnityTestingParamSpecLogging {
	GParamSpec parent_instance;
};


static gpointer g_test_log_parent_class = NULL;
static gpointer unity_testing_logging_parent_class = NULL;

gpointer g_test_log_ref (gpointer instance);
void g_test_log_unref (gpointer instance);
GParamSpec* g_test_param_spec_log (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void g_test_value_set_log (GValue* value, gpointer v_object);
void g_test_value_take_log (GValue* value, gpointer v_object);
gpointer g_test_value_get_log (const GValue* value);
GType g_test_log_get_type (void);
enum  {
	G_TEST_LOG_DUMMY_PROPERTY
};
void g_test_log_set_fatal_handler (GTestLogLogFatalFunc func, void* func_target);
GTestLog* g_test_log_new (void);
GTestLog* g_test_log_construct (GType object_type);
static void g_test_log_finalize (GTestLog* obj);
gpointer unity_testing_logging_ref (gpointer instance);
void unity_testing_logging_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_logging (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_logging (GValue* value, gpointer v_object);
void unity_testing_value_take_logging (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_logging (const GValue* value);
GType unity_testing_logging_get_type (void);
enum  {
	UNITY_TESTING_LOGGING_DUMMY_PROPERTY
};
static void unity_testing_logging_log_handler (UnityTestingLogging* self, const char* log_domain, GLogLevelFlags flags, const char* message);
static void _unity_testing_logging_log_handler_glog_func (const char* log_domain, GLogLevelFlags log_levels, const char* message, gpointer self);
UnityTestingLogging* unity_testing_logging_new (void);
UnityTestingLogging* unity_testing_logging_construct (GType object_type);
gboolean unity_testing_logging_fatal_handler (const char* log_domain, GLogLevelFlags flags, const char* message);
static gboolean _unity_testing_logging_fatal_handler_gtest_log_log_fatal_func (const char* log_domain, GLogLevelFlags flags, const char* message, gpointer self);
void unity_testing_logging_init_fatal_handler (void);
static void unity_testing_logging_finalize (UnityTestingLogging* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



GTestLog* g_test_log_construct (GType object_type) {
	GTestLog* self;
	self = (GTestLog*) g_type_create_instance (object_type);
	return self;
}


GTestLog* g_test_log_new (void) {
	return g_test_log_construct (G_TEST_TYPE_LOG);
}


static void g_test_value_log_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void g_test_value_log_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		g_test_log_unref (value->data[0].v_pointer);
	}
}


static void g_test_value_log_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = g_test_log_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer g_test_value_log_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* g_test_value_log_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		GTestLog* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = g_test_log_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* g_test_value_log_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	GTestLog** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = g_test_log_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* g_test_param_spec_log (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	GTestParamSpecLog* spec;
	g_return_val_if_fail (g_type_is_a (object_type, G_TEST_TYPE_LOG), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer g_test_value_get_log (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, G_TEST_TYPE_LOG), NULL);
	return value->data[0].v_pointer;
}


void g_test_value_set_log (GValue* value, gpointer v_object) {
	GTestLog* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, G_TEST_TYPE_LOG));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, G_TEST_TYPE_LOG));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		g_test_log_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		g_test_log_unref (old);
	}
}


void g_test_value_take_log (GValue* value, gpointer v_object) {
	GTestLog* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, G_TEST_TYPE_LOG));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, G_TEST_TYPE_LOG));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		g_test_log_unref (old);
	}
}


static void g_test_log_class_init (GTestLogClass * klass) {
	g_test_log_parent_class = g_type_class_peek_parent (klass);
	G_TEST_LOG_CLASS (klass)->finalize = g_test_log_finalize;
}


static void g_test_log_instance_init (GTestLog * self) {
	self->ref_count = 1;
}


static void g_test_log_finalize (GTestLog* obj) {
	GTestLog * self;
	self = G_TEST_LOG (obj);
}


GType g_test_log_get_type (void) {
	static volatile gsize g_test_log_type_id__volatile = 0;
	if (g_once_init_enter (&g_test_log_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { g_test_value_log_init, g_test_value_log_free_value, g_test_value_log_copy_value, g_test_value_log_peek_pointer, "p", g_test_value_log_collect_value, "p", g_test_value_log_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (GTestLogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) g_test_log_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GTestLog), 0, (GInstanceInitFunc) g_test_log_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType g_test_log_type_id;
		g_test_log_type_id = g_type_register_fundamental (g_type_fundamental_next (), "GTestLog", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&g_test_log_type_id__volatile, g_test_log_type_id);
	}
	return g_test_log_type_id__volatile;
}


gpointer g_test_log_ref (gpointer instance) {
	GTestLog* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void g_test_log_unref (gpointer instance) {
	GTestLog* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		G_TEST_LOG_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _unity_testing_logging_log_handler_glog_func (const char* log_domain, GLogLevelFlags log_levels, const char* message, gpointer self) {
	unity_testing_logging_log_handler (self, log_domain, log_levels, message);
}


UnityTestingLogging* unity_testing_logging_construct (GType object_type) {
	UnityTestingLogging* self;
	self = (UnityTestingLogging*) g_type_create_instance (object_type);
	g_log_set_default_handler (_unity_testing_logging_log_handler_glog_func, self);
	return self;
}


UnityTestingLogging* unity_testing_logging_new (void) {
	return unity_testing_logging_construct (UNITY_TESTING_TYPE_LOGGING);
}


static gboolean string_contains (const char* self, const char* needle) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	result = strstr (self, needle) != NULL;
	return result;
}


gboolean unity_testing_logging_fatal_handler (const char* log_domain, GLogLevelFlags flags, const char* message) {
	gboolean result = FALSE;
	if (string_contains (log_domain, "ndicator")) {
		result = FALSE;
		return result;
	}
	if (string_contains (message, "widget class `GtkImage' has no property named `x-ayatana-indicator-dyn" \
"amic'")) {
		result = FALSE;
		return result;
	}
	if (string_contains (message, "is currently inside an allocation cycle")) {
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}


static gboolean _unity_testing_logging_fatal_handler_gtest_log_log_fatal_func (const char* log_domain, GLogLevelFlags flags, const char* message, gpointer self) {
	return unity_testing_logging_fatal_handler (log_domain, flags, message);
}


void unity_testing_logging_init_fatal_handler (void) {
	g_test_log_set_fatal_handler (_unity_testing_logging_fatal_handler_gtest_log_log_fatal_func, NULL);
}


static void unity_testing_logging_log_handler (UnityTestingLogging* self, const char* log_domain, GLogLevelFlags flags, const char* message) {
	char* level;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	const char* _tmp10_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (message != NULL);
	level = NULL;
	if (_vala_strcmp0 (log_domain, "Clutter") == 0) {
		_tmp0_ = (flags & G_LOG_LEVEL_WARNING) != 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		if (string_contains (message, "is currently inside an allocation cycle")) {
			_g_free0 (level);
			return;
		}
	}
	if (_vala_strcmp0 (log_domain, "Gtk") == 0) {
		_tmp1_ = (flags & G_LOG_LEVEL_WARNING) != 0;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		if (string_contains (message, "has no property named `x-ayatana-indicator-dynamic'")) {
			_g_free0 (level);
			return;
		}
	}
	if ((flags & G_LOG_LEVEL_ERROR) != 0) {
		char* _tmp2_;
		level = (_tmp2_ = g_strdup ("FATAL"), _g_free0 (level), _tmp2_);
	} else {
		if ((flags & G_LOG_LEVEL_CRITICAL) != 0) {
			char* _tmp3_;
			level = (_tmp3_ = g_strdup ("CRITICAL"), _g_free0 (level), _tmp3_);
		} else {
			if ((flags & G_LOG_LEVEL_WARNING) != 0) {
				char* _tmp4_;
				level = (_tmp4_ = g_strdup ("WARNING"), _g_free0 (level), _tmp4_);
			} else {
				if ((flags & G_LOG_LEVEL_MESSAGE) != 0) {
					char* _tmp5_;
					level = (_tmp5_ = g_strdup ("MESSAGE"), _g_free0 (level), _tmp5_);
				} else {
					if ((flags & G_LOG_LEVEL_INFO) != 0) {
						char* _tmp6_;
						level = (_tmp6_ = g_strdup ("INFO"), _g_free0 (level), _tmp6_);
					} else {
						if ((flags & G_LOG_LEVEL_DEBUG) != 0) {
							char* _tmp7_;
							level = (_tmp7_ = g_strdup ("DEBUG"), _g_free0 (level), _tmp7_);
						} else {
							char* _tmp9_;
							GEnumValue* _tmp8_;
							level = (_tmp9_ = g_strdup ((_tmp8_ = g_enum_get_value (g_type_class_ref (G_TYPE_INT), (int) flags), (_tmp8_ != NULL) ? _tmp8_->value_name : NULL)), _g_free0 (level), _tmp9_);
						}
					}
				}
			}
		}
	}
	_tmp10_ = NULL;
	if (log_domain == NULL) {
		_tmp10_ = "Unity";
	} else {
		_tmp10_ = log_domain;
	}
	g_print ("%s-%s: %s\n\n", _tmp10_, level, message);
	_g_free0 (level);
}


static void unity_testing_value_logging_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_testing_value_logging_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_testing_logging_unref (value->data[0].v_pointer);
	}
}


static void unity_testing_value_logging_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_testing_logging_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_testing_value_logging_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_testing_value_logging_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestingLogging* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_testing_logging_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_testing_value_logging_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestingLogging** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_testing_logging_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_testing_param_spec_logging (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestingParamSpecLogging* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTING_TYPE_LOGGING), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_testing_value_get_logging (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTING_TYPE_LOGGING), NULL);
	return value->data[0].v_pointer;
}


void unity_testing_value_set_logging (GValue* value, gpointer v_object) {
	UnityTestingLogging* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTING_TYPE_LOGGING));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTING_TYPE_LOGGING));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_testing_logging_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_testing_logging_unref (old);
	}
}


void unity_testing_value_take_logging (GValue* value, gpointer v_object) {
	UnityTestingLogging* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTING_TYPE_LOGGING));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTING_TYPE_LOGGING));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_testing_logging_unref (old);
	}
}


static void unity_testing_logging_class_init (UnityTestingLoggingClass * klass) {
	unity_testing_logging_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTING_LOGGING_CLASS (klass)->finalize = unity_testing_logging_finalize;
}


static void unity_testing_logging_instance_init (UnityTestingLogging * self) {
	self->ref_count = 1;
}


static void unity_testing_logging_finalize (UnityTestingLogging* obj) {
	UnityTestingLogging * self;
	self = UNITY_TESTING_LOGGING (obj);
}


GType unity_testing_logging_get_type (void) {
	static volatile gsize unity_testing_logging_type_id__volatile = 0;
	if (g_once_init_enter (&unity_testing_logging_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_testing_value_logging_init, unity_testing_value_logging_free_value, unity_testing_value_logging_copy_value, unity_testing_value_logging_peek_pointer, "p", unity_testing_value_logging_collect_value, "p", unity_testing_value_logging_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestingLoggingClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_testing_logging_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestingLogging), 0, (GInstanceInitFunc) unity_testing_logging_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_testing_logging_type_id;
		unity_testing_logging_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestingLogging", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_testing_logging_type_id__volatile, unity_testing_logging_type_id);
	}
	return unity_testing_logging_type_id__volatile;
}


gpointer unity_testing_logging_ref (gpointer instance) {
	UnityTestingLogging* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_testing_logging_unref (gpointer instance) {
	UnityTestingLogging* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTING_LOGGING_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
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




