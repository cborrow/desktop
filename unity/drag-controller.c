/* drag-controller.c generated by valac, the Vala compiler
 * generated from drag-controller.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by Gordon Allott <gord.allott@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_DRAG_TYPE_MODEL (unity_drag_model_get_type ())
#define UNITY_DRAG_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModel))
#define UNITY_DRAG_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_MODEL))
#define UNITY_DRAG_MODEL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModelIface))

typedef struct _UnityDragModel UnityDragModel;
typedef struct _UnityDragModelIface UnityDragModelIface;

#define UNITY_DRAG_TYPE_CONTROLLER (unity_drag_controller_get_type ())
#define UNITY_DRAG_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragController))
#define UNITY_DRAG_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))
#define UNITY_DRAG_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))

typedef struct _UnityDragController UnityDragController;
typedef struct _UnityDragControllerClass UnityDragControllerClass;
typedef struct _UnityDragControllerPrivate UnityDragControllerPrivate;

#define UNITY_DRAG_TYPE_VIEW (unity_drag_view_get_type ())
#define UNITY_DRAG_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragView))
#define UNITY_DRAG_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))
#define UNITY_DRAG_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))

typedef struct _UnityDragView UnityDragView;
typedef struct _UnityDragViewClass UnityDragViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

#define UNITY_TYPE_WINDOW_ACTION (unity_window_action_get_type ())

struct _UnityDragModelIface {
	GTypeInterface parent_iface;
	ClutterActor* (*get_icon) (UnityDragModel* self);
	char* (*get_drag_data) (UnityDragModel* self);
};

struct _UnityDragController {
	GObject parent_instance;
	UnityDragControllerPrivate * priv;
};

struct _UnityDragControllerClass {
	GObjectClass parent_class;
};

struct _UnityDragControllerPrivate {
	UnityDragModel* model;
	UnityDragView* view;
	gboolean _is_dragging;
};

typedef enum  {
	UNITY_SHELL_MODE_MINIMIZED,
	UNITY_SHELL_MODE_DASH,
	UNITY_SHELL_MODE_EXPOSE
} UnityShellMode;

typedef enum  {
	UNITY_WINDOW_ACTION_CLOSE,
	UNITY_WINDOW_ACTION_MINIMIZE,
	UNITY_WINDOW_ACTION_MAXIMIZE,
	UNITY_WINDOW_ACTION_UNMAXIMIZE
} UnityWindowAction;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	guint32 (*get_current_time) (UnityShell* self);
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	void (*hide_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	gint (*get_launcher_width_foobar) (UnityShell* self);
	gint (*get_panel_height_foobar) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*about_to_show_places) (UnityShell* self);
	void (*close_xids) (UnityShell* self, GArray* xids);
	void (*show_window) (UnityShell* self, guint32 xid);
	void (*expose_xids) (UnityShell* self, GArray* xids);
	void (*stop_expose) (UnityShell* self);
	void (*get_window_details) (UnityShell* self, guint32 xid, gboolean* allows_resize, gboolean* is_maximised);
	void (*do_window_action) (UnityShell* self, guint32 xid, UnityWindowAction action);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
};


extern UnityDragController* unity_drag_controller_singleton;
UnityDragController* unity_drag_controller_singleton = NULL;
extern UnityShell* unity_global_shell;
static gpointer unity_drag_controller_parent_class = NULL;

GType unity_drag_model_get_type (void) G_GNUC_CONST;
ClutterActor* unity_drag_model_get_icon (UnityDragModel* self);
char* unity_drag_model_get_drag_data (UnityDragModel* self);
GType unity_drag_controller_get_type (void) G_GNUC_CONST;
GType unity_drag_view_get_type (void) G_GNUC_CONST;
#define UNITY_DRAG_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerPrivate))
enum  {
	UNITY_DRAG_CONTROLLER_DUMMY_PROPERTY,
	UNITY_DRAG_CONTROLLER_IS_DRAGGING
};
UnityDragController* unity_drag_controller_new (void);
UnityDragController* unity_drag_controller_construct (GType object_type);
UnityDragController* unity_drag_controller_get_default (void);
UnityDragView* unity_drag_view_new (ClutterStage* stage);
UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage);
void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y);
static void unity_drag_controller_rehouse_orphaned_child (UnityDragController* self, ClutterActor* old_parent);
static void _unity_drag_controller_rehouse_orphaned_child_clutter_actor_parent_set (ClutterActor* _sender, ClutterActor* old_parent, gpointer self);
static void unity_drag_controller_on_view_motion (UnityDragController* self, float x, float y);
static void _unity_drag_controller_on_view_motion_unity_drag_view_motion (UnityDragView* _sender, float x, float y, gpointer self);
static void unity_drag_controller_on_view_end (UnityDragController* self, float x, float y);
static void _unity_drag_controller_on_view_end_unity_drag_view_end (UnityDragView* _sender, float x, float y, gpointer self);
GType unity_shell_mode_get_type (void) G_GNUC_CONST;
GType unity_window_action_get_type (void) G_GNUC_CONST;
GType unity_shell_get_type (void) G_GNUC_CONST;
void unity_shell_add_fullscreen_request (UnityShell* self, GObject* o);
void unity_drag_controller_start_drag (UnityDragController* self, UnityDragModel* model, float offset_x, float offset_y);
UnityDragModel* unity_drag_controller_get_drag_model (UnityDragController* self);
void unity_drag_view_unhook_actor (UnityDragView* self);
gboolean unity_shell_remove_fullscreen_request (UnityShell* self, GObject* o);
gboolean unity_drag_controller_get_is_dragging (UnityDragController* self);
static GObject * unity_drag_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_drag_controller_finalize (GObject* obj);
static void unity_drag_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


static void g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

ClutterActor* unity_drag_model_get_icon (UnityDragModel* self) {
	return UNITY_DRAG_MODEL_GET_INTERFACE (self)->get_icon (self);
}


char* unity_drag_model_get_drag_data (UnityDragModel* self) {
	return UNITY_DRAG_MODEL_GET_INTERFACE (self)->get_drag_data (self);
}


static void unity_drag_model_base_init (UnityDragModelIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType unity_drag_model_get_type (void) {
	static volatile gsize unity_drag_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_drag_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragModelIface), (GBaseInitFunc) unity_drag_model_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_drag_model_type_id;
		unity_drag_model_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityDragModel", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_drag_model_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&unity_drag_model_type_id__volatile, unity_drag_model_type_id);
	}
	return unity_drag_model_type_id__volatile;
}


UnityDragController* unity_drag_controller_get_default (void) {
	UnityDragController* result = NULL;
	if (unity_drag_controller_singleton == NULL) {
		UnityDragController* _tmp0_;
		unity_drag_controller_singleton = (_tmp0_ = unity_drag_controller_new (), _g_object_unref0 (unity_drag_controller_singleton), _tmp0_);
	}
	result = unity_drag_controller_singleton;
	return result;
}


static void _unity_drag_controller_rehouse_orphaned_child_clutter_actor_parent_set (ClutterActor* _sender, ClutterActor* old_parent, gpointer self) {
	unity_drag_controller_rehouse_orphaned_child (self, old_parent);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_drag_controller_on_view_motion_unity_drag_view_motion (UnityDragView* _sender, float x, float y, gpointer self) {
	unity_drag_controller_on_view_motion (self, x, y);
}


static void _unity_drag_controller_on_view_end_unity_drag_view_end (UnityDragView* _sender, float x, float y, gpointer self) {
	unity_drag_controller_on_view_end (self, x, y);
}


void unity_drag_controller_start_drag (UnityDragController* self, UnityDragModel* model, float offset_x, float offset_y) {
	ClutterActor* _tmp3_;
	ClutterActor* _tmp4_;
	UnityDragModel* _tmp5_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (model != NULL);
	if (!UNITY_DRAG_IS_VIEW (self->priv->view)) {
		UnityDragView* _tmp2_;
		ClutterActor* _tmp0_;
		ClutterActor* _tmp1_;
		self->priv->view = (_tmp2_ = unity_drag_view_new ((_tmp1_ = clutter_actor_get_stage (_tmp0_ = unity_drag_model_get_icon (model)), CLUTTER_IS_STAGE (_tmp1_) ? ((ClutterStage*) _tmp1_) : NULL)), _g_object_unref0 (self->priv->view), _tmp2_);
		_g_object_unref0 (_tmp0_);
	}
	unity_drag_view_hook_actor_to_cursor (self->priv->view, _tmp3_ = unity_drag_model_get_icon (model), offset_x, offset_y);
	_g_object_unref0 (_tmp3_);
	g_signal_connect_object (_tmp4_ = unity_drag_model_get_icon (model), "parent-set", (GCallback) _unity_drag_controller_rehouse_orphaned_child_clutter_actor_parent_set, self, 0);
	_g_object_unref0 (_tmp4_);
	self->priv->model = (_tmp5_ = _g_object_ref0 (model), _g_object_unref0 (self->priv->model), _tmp5_);
	g_signal_emit_by_name (self, "drag-start", model);
	g_signal_connect_object (self->priv->view, "motion", (GCallback) _unity_drag_controller_on_view_motion_unity_drag_view_motion, self, 0);
	g_signal_connect_object (self->priv->view, "end", (GCallback) _unity_drag_controller_on_view_end_unity_drag_view_end, self, 0);
	self->priv->_is_dragging = TRUE;
	unity_shell_add_fullscreen_request (unity_global_shell, (GObject*) self);
}


static void unity_drag_controller_rehouse_orphaned_child (UnityDragController* self, ClutterActor* old_parent) {
	ClutterActor* actor;
	g_return_if_fail (self != NULL);
	if (old_parent == NULL) {
		return;
	}
	actor = unity_drag_model_get_icon (self->priv->model);
	if (!CLUTTER_IS_ACTOR (clutter_actor_get_parent (actor))) {
		ClutterActor* _tmp0_;
		ClutterStage* stage;
		stage = _g_object_ref0 ((_tmp0_ = clutter_actor_get_stage (old_parent), CLUTTER_IS_STAGE (_tmp0_) ? ((ClutterStage*) _tmp0_) : NULL));
		clutter_actor_set_parent (actor, (ClutterActor*) stage);
		clutter_actor_set_position (actor, (float) 20000, (float) 20000);
		_g_object_unref0 (stage);
	}
	_g_object_unref0 (actor);
}


UnityDragModel* unity_drag_controller_get_drag_model (UnityDragController* self) {
	UnityDragModel* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 (self->priv->model);
	return result;
}


static void unity_drag_controller_on_view_motion (UnityDragController* self, float x, float y) {
	g_return_if_fail (self != NULL);
	g_signal_emit_by_name (self, "drag-motion", self->priv->model, x, y);
}


static void unity_drag_controller_on_view_end (UnityDragController* self, float x, float y) {
	guint _tmp1_;
	ClutterActor* _tmp0_;
	guint _tmp2_;
	guint _tmp3_;
	UnityDragModel* _tmp4_;
	g_return_if_fail (self != NULL);
	g_signal_parse_name ("parent-set", CLUTTER_TYPE_ACTOR, &_tmp1_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (_tmp0_ = unity_drag_model_get_icon (self->priv->model), G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp1_, 0, NULL, (GCallback) _unity_drag_controller_rehouse_orphaned_child_clutter_actor_parent_set, self);
	_g_object_unref0 (_tmp0_);
	unity_drag_view_unhook_actor (self->priv->view);
	g_signal_emit_by_name (self, "drag-drop", self->priv->model, x, y);
	g_signal_parse_name ("motion", UNITY_DRAG_TYPE_VIEW, &_tmp2_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (self->priv->view, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp2_, 0, NULL, (GCallback) _unity_drag_controller_on_view_motion_unity_drag_view_motion, self);
	g_signal_parse_name ("end", UNITY_DRAG_TYPE_VIEW, &_tmp3_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (self->priv->view, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp3_, 0, NULL, (GCallback) _unity_drag_controller_on_view_end_unity_drag_view_end, self);
	self->priv->model = (_tmp4_ = NULL, _g_object_unref0 (self->priv->model), _tmp4_);
	self->priv->_is_dragging = FALSE;
	unity_shell_remove_fullscreen_request (unity_global_shell, (GObject*) self);
}


UnityDragController* unity_drag_controller_construct (GType object_type) {
	UnityDragController * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


UnityDragController* unity_drag_controller_new (void) {
	return unity_drag_controller_construct (UNITY_DRAG_TYPE_CONTROLLER);
}


gboolean unity_drag_controller_get_is_dragging (UnityDragController* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_dragging;
	return result;
}


static GObject * unity_drag_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityDragController * self;
	parent_class = G_OBJECT_CLASS (unity_drag_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_DRAG_CONTROLLER (obj);
	{
		self->priv->_is_dragging = FALSE;
	}
	return obj;
}


static void unity_drag_controller_class_init (UnityDragControllerClass * klass) {
	unity_drag_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityDragControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_drag_controller_get_property;
	G_OBJECT_CLASS (klass)->constructor = unity_drag_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_drag_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_DRAG_CONTROLLER_IS_DRAGGING, g_param_spec_boolean ("is-dragging", "is-dragging", "is-dragging", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_signal_new ("drag_start", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_DRAG_TYPE_MODEL);
	g_signal_new ("drag_motion", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT, G_TYPE_NONE, 3, UNITY_DRAG_TYPE_MODEL, G_TYPE_FLOAT, G_TYPE_FLOAT);
	g_signal_new ("drag_drop", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT, G_TYPE_NONE, 3, UNITY_DRAG_TYPE_MODEL, G_TYPE_FLOAT, G_TYPE_FLOAT);
}


static void unity_drag_controller_instance_init (UnityDragController * self) {
	self->priv = UNITY_DRAG_CONTROLLER_GET_PRIVATE (self);
}


static void unity_drag_controller_finalize (GObject* obj) {
	UnityDragController * self;
	self = UNITY_DRAG_CONTROLLER (obj);
	_g_object_unref0 (self->priv->model);
	_g_object_unref0 (self->priv->view);
	G_OBJECT_CLASS (unity_drag_controller_parent_class)->finalize (obj);
}


GType unity_drag_controller_get_type (void) {
	static volatile gsize unity_drag_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_drag_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_drag_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityDragController), 0, (GInstanceInitFunc) unity_drag_controller_instance_init, NULL };
		GType unity_drag_controller_type_id;
		unity_drag_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityDragController", &g_define_type_info, 0);
		g_once_init_leave (&unity_drag_controller_type_id__volatile, unity_drag_controller_type_id);
	}
	return unity_drag_controller_type_id__volatile;
}


static void unity_drag_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityDragController * self;
	self = UNITY_DRAG_CONTROLLER (object);
	switch (property_id) {
		case UNITY_DRAG_CONTROLLER_IS_DRAGGING:
		g_value_set_boolean (value, unity_drag_controller_get_is_dragging (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



static void g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT) (gpointer data1, gpointer arg_1, float arg_2, float arg_3, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_float (param_values + 2), g_value_get_float (param_values + 3), data2);
}



