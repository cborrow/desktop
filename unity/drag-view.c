/* drag-view.c generated by valac, the Vala compiler
 * generated from drag-view.vala, do not modify */

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
#include <float.h>
#include <math.h>


#define UNITY_DRAG_TYPE_VIEW (unity_drag_view_get_type ())
#define UNITY_DRAG_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragView))
#define UNITY_DRAG_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))
#define UNITY_DRAG_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))

typedef struct _UnityDragView UnityDragView;
typedef struct _UnityDragViewClass UnityDragViewClass;
typedef struct _UnityDragViewPrivate UnityDragViewPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityDragView {
	GObject parent_instance;
	UnityDragViewPrivate * priv;
};

struct _UnityDragViewClass {
	GObjectClass parent_class;
};

struct _UnityDragViewPrivate {
	ClutterStage* _stage;
	ClutterActor* hooked_actor;
	float offset_x;
	float offset_y;
};


static gpointer unity_drag_view_parent_class = NULL;

GType unity_drag_view_get_type (void);
#define UNITY_DRAG_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_DRAG_TYPE_VIEW, UnityDragViewPrivate))
enum  {
	UNITY_DRAG_VIEW_DUMMY_PROPERTY,
	UNITY_DRAG_VIEW_STAGE
};
UnityDragView* unity_drag_view_new (ClutterStage* stage);
UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage);
void unity_drag_view_unhook_actor (UnityDragView* self);
ClutterStage* unity_drag_view_get_stage (UnityDragView* self);
static gboolean unity_drag_view_captured_event (UnityDragView* self, ClutterEvent* event);
static gboolean _unity_drag_view_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y);
static gboolean unity_drag_view_on_motion_event (UnityDragView* self, ClutterEvent* event);
static gboolean unity_drag_view_on_release_event (UnityDragView* self, ClutterEvent* event);
static gboolean _unity_drag_view_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_drag_view_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void unity_drag_view_set_stage (UnityDragView* self, ClutterStage* value);
static GObject * unity_drag_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_drag_view_finalize (GObject* obj);
static void unity_drag_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_drag_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static void g_cclosure_user_marshal_VOID__FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage) {
	UnityDragView * self;
	g_return_val_if_fail (stage != NULL, NULL);
	self = (UnityDragView*) g_object_new (object_type, "stage", stage, NULL);
	return self;
}


UnityDragView* unity_drag_view_new (ClutterStage* stage) {
	return unity_drag_view_construct (UNITY_DRAG_TYPE_VIEW, stage);
}


static gboolean _unity_drag_view_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_drag_view_captured_event (self, event);
}


void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y) {
	float x = 0.0F;
	float y = 0.0F;
	ClutterActor* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (actor != NULL);
	if (CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
		g_warning ("drag-view.vala:45: attempted to hook a new actor to dnd without unhook" \
"ing previous actor");
		unity_drag_view_unhook_actor (self);
	}
	self->priv->offset_x = offset_x;
	self->priv->offset_y = offset_y;
	self->priv->hooked_actor = (_tmp0_ = (ClutterActor*) g_object_ref_sink ((ClutterClone*) clutter_clone_new (actor)), _g_object_unref0 (self->priv->hooked_actor), _tmp0_);
	clutter_actor_unparent (self->priv->hooked_actor);
	clutter_container_add_actor ((ClutterContainer*) self->priv->_stage, self->priv->hooked_actor);
	clutter_actor_get_transformed_position (actor, &x, &y);
	clutter_actor_set_position (self->priv->hooked_actor, x, y);
	clutter_actor_set_width (self->priv->hooked_actor, clutter_actor_get_width (actor));
	clutter_actor_set_height (self->priv->hooked_actor, clutter_actor_get_height (actor));
	clutter_actor_show (self->priv->hooked_actor);
	g_signal_connect_object ((ClutterActor*) self->priv->_stage, "captured-event", (GCallback) _unity_drag_view_captured_event_clutter_actor_captured_event, self, 0);
}


static gboolean unity_drag_view_captured_event (UnityDragView* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if ((*event).type == CLUTTER_MOTION) {
		unity_drag_view_on_motion_event (self, event);
		result = TRUE;
		return result;
	}
	if ((*event).type == CLUTTER_BUTTON_RELEASE) {
		unity_drag_view_on_release_event (self, event);
		result = TRUE;
		return result;
	}
	result = FALSE;
	return result;
}


static gboolean _unity_drag_view_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_drag_view_on_motion_event (self, event);
}


void unity_drag_view_unhook_actor (UnityDragView* self) {
	guint _tmp0_;
	ClutterActor* _tmp1_;
	g_return_if_fail (self != NULL);
	if (self->priv->hooked_actor == NULL) {
		return;
	}
	clutter_container_remove_actor ((ClutterContainer*) self->priv->_stage, self->priv->hooked_actor);
	g_signal_parse_name ("motion-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE);
	g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _unity_drag_view_on_motion_event_clutter_actor_motion_event, self);
	self->priv->hooked_actor = (_tmp1_ = NULL, _g_object_unref0 (self->priv->hooked_actor), _tmp1_);
}


static gboolean unity_drag_view_on_motion_event (UnityDragView* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if (!CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
		guint _tmp0_;
		g_signal_parse_name ("captured-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _unity_drag_view_captured_event_clutter_actor_captured_event, self);
		result = FALSE;
		return result;
	}
	clutter_actor_set_position (self->priv->hooked_actor, (*event).motion.x - self->priv->offset_x, (*event).motion.y - self->priv->offset_y);
	g_signal_emit_by_name (self, "motion", (*event).motion.x, (*event).motion.y);
	result = FALSE;
	return result;
}


static gboolean _unity_drag_view_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_drag_view_on_release_event (self, event);
}


static gboolean unity_drag_view_on_release_event (UnityDragView* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if (!CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
		guint _tmp0_;
		g_signal_parse_name ("button-release-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _unity_drag_view_on_release_event_clutter_actor_button_release_event, self);
		result = FALSE;
		return result;
	}
	unity_drag_view_unhook_actor (self);
	g_signal_emit_by_name (self, "end", (*event).button.x, (*event).button.y);
	result = FALSE;
	return result;
}


ClutterStage* unity_drag_view_get_stage (UnityDragView* self) {
	ClutterStage* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_stage;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_drag_view_set_stage (UnityDragView* self, ClutterStage* value) {
	ClutterStage* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_stage = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_stage), _tmp0_);
	g_object_notify ((GObject *) self, "stage");
}


static GObject * unity_drag_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityDragView * self;
	parent_class = G_OBJECT_CLASS (unity_drag_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_DRAG_VIEW (obj);
	{
	}
	return obj;
}


static void unity_drag_view_class_init (UnityDragViewClass * klass) {
	unity_drag_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityDragViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_drag_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_drag_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_drag_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_drag_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_DRAG_VIEW_STAGE, g_param_spec_object ("stage", "stage", "stage", CLUTTER_TYPE_STAGE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("motion", UNITY_DRAG_TYPE_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__FLOAT_FLOAT, G_TYPE_NONE, 2, G_TYPE_FLOAT, G_TYPE_FLOAT);
	g_signal_new ("end", UNITY_DRAG_TYPE_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__FLOAT_FLOAT, G_TYPE_NONE, 2, G_TYPE_FLOAT, G_TYPE_FLOAT);
}


static void unity_drag_view_instance_init (UnityDragView * self) {
	self->priv = UNITY_DRAG_VIEW_GET_PRIVATE (self);
}


static void unity_drag_view_finalize (GObject* obj) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (obj);
	_g_object_unref0 (self->priv->_stage);
	_g_object_unref0 (self->priv->hooked_actor);
	G_OBJECT_CLASS (unity_drag_view_parent_class)->finalize (obj);
}


GType unity_drag_view_get_type (void) {
	static volatile gsize unity_drag_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_drag_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_drag_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityDragView), 0, (GInstanceInitFunc) unity_drag_view_instance_init, NULL };
		GType unity_drag_view_type_id;
		unity_drag_view_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityDragView", &g_define_type_info, 0);
		g_once_init_leave (&unity_drag_view_type_id__volatile, unity_drag_view_type_id);
	}
	return unity_drag_view_type_id__volatile;
}


static void unity_drag_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (object);
	switch (property_id) {
		case UNITY_DRAG_VIEW_STAGE:
		g_value_set_object (value, unity_drag_view_get_stage (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_drag_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (object);
	switch (property_id) {
		case UNITY_DRAG_VIEW_STAGE:
		unity_drag_view_set_stage (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



static void g_cclosure_user_marshal_VOID__FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__FLOAT_FLOAT) (gpointer data1, float arg_1, float arg_2, gpointer data2);
	register GMarshalFunc_VOID__FLOAT_FLOAT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__FLOAT_FLOAT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_float (param_values + 1), g_value_get_float (param_values + 2), data2);
}



