/* clutk-0.3.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Ctk", lower_case_cprefix = "ctk_")]
namespace Ctk {
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Actor : Clutter.Actor, Clutter.Scriptable, Ctk.Focusable {
		public void add_effect (Ctk.Effect effect);
		public unowned Clutter.Actor get_background ();
		public unowned Clutter.Actor get_background_for_state (Ctk.ActorState state);
		public static Gtk.TextDirection get_default_direction ();
		public unowned GLib.SList get_effects ();
		public bool get_effects_painting ();
		public void get_padding (Ctk.Padding padding);
		public Ctk.ActorState get_state ();
		public void get_stored_allocation (Clutter.ActorBox box);
		public unowned string get_tooltip_text ();
		public void remove_all_effects ();
		public void remove_effect (Ctk.Effect effect);
		public void set_background (Clutter.Actor bg);
		public void set_background_for_state (Ctk.ActorState state, Clutter.Actor bg);
		public static void set_default_direction (Gtk.TextDirection dir);
		public void set_effects_painting (bool painting);
		public void set_padding (Ctk.Padding padding);
		public void set_state (Ctk.ActorState state);
		public void set_tooltip_text (string self);
		public void* background { get; set; }
		public bool effects_painting { get; set; }
		[NoAccessorMethod]
		public bool focused { get; set; }
		public Ctk.Padding padding { get; set; }
		public Ctk.ActorState state { get; set; }
		public string tooltip_text { get; set; }
		public virtual signal void child_focus_changed (Clutter.ActorBox box);
		public virtual signal void drag_begin (Gdk.DragContext context);
		public virtual signal void drag_data_delete (Gdk.DragContext context);
		public virtual signal void drag_data_get (Gdk.DragContext context, Gtk.SelectionData data, uint info, uint time);
		public virtual signal void drag_data_received (Gdk.DragContext context, int x, int y, Gtk.SelectionData data, uint info, uint time);
		public virtual signal bool drag_drop (Gdk.DragContext context, int x, int y, uint time);
		public virtual signal void drag_end (Gdk.DragContext context);
		public virtual signal bool drag_failed (Gdk.DragContext context, Gtk.DragResult result);
		public virtual signal void drag_leave (Gdk.DragContext context, uint time);
		public virtual signal bool drag_motion (Gdk.DragContext context, int x, int y, uint time);
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Bin : Ctk.Actor, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		public unowned Clutter.Actor get_child ();
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Box : Ctk.Actor, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		public bool get_homogeneous ();
		public Ctk.Orientation get_orientation ();
		public int get_spacing ();
		public void pack (Clutter.Actor child, bool expand, bool fill);
		public void set_homogeneous (bool homogeneous);
		public void set_orientation (Ctk.Orientation orient);
		public void set_spacing (int spacing);
		public void sort_children (GLib.CompareFunc func);
		public bool homogeneous { get; set; }
		public int orientation { get; set; }
		public int spacing { get; set; }
	}
	[Compact]
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class BoxChild {
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Button : Ctk.Bin, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Button (Ctk.Orientation orientation);
		public unowned Ctk.Image get_image ();
		public unowned string get_label ();
		public Ctk.Orientation get_orientation ();
		public unowned Ctk.Text get_text ();
		public void set_image (Ctk.Image image);
		public void set_label (string label);
		public void set_orientation (Ctk.Orientation orient);
		public void set_text (Ctk.Text text);
		public Ctk.Image image { get; set; }
		public string label { get; set; }
		public int orientation { get; set; }
		public virtual signal void clicked ();
		public virtual signal void show_context_menu (uint event_time);
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Effect : GLib.InitiallyUnowned {
		public unowned Clutter.Animation animate (ulong mode, uint duration, ...);
		public unowned Clutter.Actor get_actor ();
		public unowned Clutter.Animation get_animation ();
		public virtual void paint (Ctk.EffectPaintFunc func);
		public void set_actor (Clutter.Actor actor);
		public void* actor { get; set; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class EffectBlur : Ctk.Effect {
		[CCode (type = "CtkEffect*", has_construct_function = false)]
		public EffectBlur ();
		public float get_factor ();
		public void set_factor (float factor);
		public float factor { get; set; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class EffectContext : GLib.Object {
		public static unowned Ctk.EffectContext get_default_for_actor (Clutter.Actor actor);
		public static unowned Ctk.EffectContext get_default_for_stage (Clutter.Stage stage);
		public unowned Ctk.RenderTarget grab_render_target ();
		public unowned Ctk.RenderTarget grab_render_target_for_actor (Clutter.Actor actor);
		public unowned Ctk.RenderTarget grab_render_target_for_size (uint width, uint height);
		public unowned Ctk.RenderTarget peek_render_target ();
		public unowned Ctk.RenderTarget pop_render_target ();
		public void push_render_target (Ctk.RenderTarget target);
		public void release_render_target (Ctk.RenderTarget target);
		[NoAccessorMethod]
		public void* stage { get; construct; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class EffectDropShadow : Ctk.Effect {
		[CCode (has_construct_function = false)]
		public EffectDropShadow (uint size, int offset_x, int offset_y);
		public int get_offset_x ();
		public int get_offset_y ();
		public uint get_size ();
		public void set_offset_x (int offset_x);
		public void set_offset_y (int offset_y);
		public void set_size (uint size);
		public int offset_x { get; set; }
		public int offset_y { get; set; }
		public uint size { get; set; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class EffectGlow : Ctk.Effect {
		[CCode (type = "CtkEffect*", has_construct_function = false)]
		public EffectGlow ();
		public void get_color (out Clutter.Color color);
		public float get_factor ();
		public void set_background_texture (Gdk.Pixbuf pixbuf);
		public void set_color (Clutter.Color c);
		public void set_factor (float factor);
		public Clutter.Color color { get; set; }
		public float factor { get; set; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class HBox : Ctk.Box, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public HBox (uint spacing);
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class IconView : Ctk.Actor, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public IconView ();
		public int get_spacing ();
		public void set_spacing (int spacing);
		public int spacing { get; set construct; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Image : Ctk.Actor, Clutter.Scriptable, Ctk.Focusable {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image (uint size);
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image.from_filename (uint size, string filename);
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image.from_gicon (uint size, GLib.Icon icon);
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image.from_icon_name (uint size, string icon_name);
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image.from_pixbuf (uint size, Gdk.Pixbuf pixbuf);
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Image.from_stock (uint size, string stock_id);
		public unowned string get_filename ();
		public unowned GLib.Icon get_gicon ();
		public unowned string get_icon_name ();
		public Ctk.ImageType get_image_storage_type ();
		public unowned Gdk.Pixbuf get_pixbuf ();
		public uint get_size ();
		public unowned string get_stock ();
		public void set_from_filename (string filename);
		public void set_from_gicon (GLib.Icon icon);
		public void set_from_icon_name (string icon_name);
		public void set_from_pixbuf (Gdk.Pixbuf pixbuf);
		public void set_from_stock (string stock_id);
		public void set_size (uint size);
		[NoAccessorMethod]
		public string filename { owned get; set; }
		[NoAccessorMethod]
		public GLib.Icon gicon { owned get; set; }
		[NoAccessorMethod]
		public string icon_name { owned get; set; }
		[NoAccessorMethod]
		public Gdk.Pixbuf pixbuf { owned get; set; }
		public int size { get; set; }
		[NoAccessorMethod]
		public string stock_id { owned get; set; }
	}
	[Compact]
	[CCode (type_id = "CTK_TYPE_RENDER_TARGET", cheader_filename = "clutk/clutk.h")]
	public class RenderTarget {
		[CCode (has_construct_function = false)]
		public RenderTarget ();
		public void bind ();
		public uint get_color_buffer_ogl_id ();
		public uint get_depth_buffer_ogl_id ();
		public Ctk.RenderTargetFlags get_flags ();
		public uint get_frame_buffer_ogl_id ();
		public uint get_height ();
		public void get_size (uint width, uint height);
		public uint get_width ();
		public void resize (uint width, uint height);
		public void set_flags (Ctk.RenderTargetFlags flags);
		[CCode (has_construct_function = false)]
		public RenderTarget.sized (uint width, uint height);
		public static void unbind ();
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class ScrollView : Ctk.Bin, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public ScrollView ();
		public bool can_scroll ();
		public Ctk.ScrollbarType get_bar_type ();
		public void get_scroll_bar (out unowned Clutter.Actor trough, out unowned Clutter.Actor slider);
		public float get_value ();
		public bool scroll (Clutter.ScrollEvent event);
		public void set_bar_type (Ctk.ScrollbarType type);
		public void set_scroll_bar (Clutter.Actor trough, Clutter.Actor slider);
		public void set_value (float value);
		[NoAccessorMethod]
		public Ctk.ScrollbarType scrollbar_type { get; set; }
		public float value { get; set; }
	}
	[Compact]
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class ShaderProgram {
		public uint shfrag;
		public uint shprog;
		public uint shvert;
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Text : Clutter.Text, Clutter.Scriptable {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Text (string text);
		public Pango.Alignment get_alignment ();
		public void set_alignment (Pango.Alignment alignment);
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Tooltip : Ctk.Actor, Clutter.Scriptable, Ctk.Focusable {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public Tooltip (Clutter.Actor actor);
		public unowned Clutter.Actor get_actor ();
		public unowned string get_label ();
		public void hide ();
		public void set_actor (Clutter.Actor actor);
		public void set_label (string label);
		public void show (int x, int y);
		public void* actor { get; set; }
		public string label { get; set; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class Toplevel : Ctk.Bin, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		public static unowned Clutter.Actor get_default_for_stage (Clutter.Actor stage);
		public unowned Clutter.Actor get_stage ();
		public void set_focus (Ctk.Focusable focusable);
		[NoAccessorMethod]
		public Clutter.Stage stage { owned get; set construct; }
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public class VBox : Ctk.Box, Clutter.Scriptable, Ctk.Focusable, Clutter.Container {
		[CCode (type = "ClutterActor*", has_construct_function = false)]
		public VBox (uint spacing);
	}
	[CCode (cheader_filename = "clutk/clutk.h")]
	public interface Focusable {
		public abstract void activate ();
		public abstract bool can_focus ();
		public static Ctk.FocusEventType get_event_type (Clutter.KeyEvent event, Ctk.FocusDirection direction);
		public abstract bool get_focused ();
		public abstract void set_focused (bool is_focused);
	}
	[CCode (type_id = "CTK_TYPE_PADDING", cheader_filename = "clutk/clutk.h")]
	public struct Padding {
		public float top;
		public float right;
		public float bottom;
		public float left;
	}
	[CCode (cprefix = "CTK_", cheader_filename = "clutk/clutk.h")]
	public enum ActorState {
		STATE_NORMAL,
		STATE_ACTIVE,
		STATE_PRELIGHT,
		STATE_SELECTED,
		STATE_INSENSITIVE,
		N_STATES
	}
	[CCode (cprefix = "CTK_FOCUS_DIR_", cheader_filename = "clutk/clutk.h")]
	public enum FocusDirection {
		NONE,
		NEXT,
		PREV,
		UP,
		RIGHT,
		DOWN,
		LEFT
	}
	[CCode (cprefix = "CTK_FOCUS_EVENT_", cheader_filename = "clutk/clutk.h")]
	public enum FocusEventType {
		NONE,
		DIRECTION,
		ACTIVATE
	}
	[CCode (cprefix = "CTK_IMAGE_", cheader_filename = "clutk/clutk.h")]
	public enum ImageType {
		EMPTY,
		PIXBUF,
		STOCK,
		ICON_NAME,
		GICON,
		FILENAME
	}
	[CCode (cprefix = "CTK_ORIENTATION_", cheader_filename = "clutk/clutk.h")]
	public enum Orientation {
		HORIZONTAL,
		VERTICAL
	}
	[CCode (cprefix = "CTK_RENDER_TARGET_", cheader_filename = "clutk/clutk.h")]
	[Flags]
	public enum RenderTargetFlags {
		IN_USE,
		STACKED
	}
	[CCode (cprefix = "CTK_SCROLLBAR_", cheader_filename = "clutk/clutk.h")]
	public enum ScrollbarType {
		INSET,
		OVERLAY,
		HIDDEN
	}
	[CCode (cheader_filename = "clutk/clutk.h", has_target = false)]
	public delegate void EffectPaintFunc (Clutter.Actor actor);
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_DEFAULT_OFFSET_X;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_DEFAULT_OFFSET_Y;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_DEFAULT_SIZE;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MAX_OFFSET_X;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MAX_OFFSET_Y;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MAX_SIZE;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MIN_OFFSET_X;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MIN_OFFSET_Y;
	[CCode (cheader_filename = "clutk/clutk.h")]
	public const int EFFECT_DROP_SHADOW_MIN_SIZE;
	[CCode (cname = "CheckGLError", cheader_filename = "clutk/clutk.h")]
	public static int CheckGLError (string glCall, string file, int line);
	[CCode (cname = "CreateAlphaMaskShader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateAlphaMaskShader ();
	[CCode (cname = "CreateBlurH0Shader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateBlurH0Shader ();
	[CCode (cname = "CreateBlurH1Shader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateBlurH1Shader ();
	[CCode (cname = "CreateBlurV0Shader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateBlurV0Shader ();
	[CCode (cname = "CreateBlurV1Shader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateBlurV1Shader ();
	[CCode (cname = "CreateColorMaskShader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateColorMaskShader ();
	[CCode (cname = "CreateExponentShader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreateExponentShader ();
	[CCode (cname = "CreatePassThroughShader", cheader_filename = "clutk/clutk.h")]
	public static unowned Ctk.ShaderProgram CreatePassThroughShader ();
	[CCode (cname = "custom_render_quad_alpha_mask", cheader_filename = "clutk/clutk.h")]
	public static void custom_render_quad_alpha_mask (Ctk.RenderTarget rt, float red, float green, float blue, float alpha, int window_w, int window_h, int x, int y, int w, int h);
	[CCode (cname = "custom_render_quad_gaussian_blur_separable", cheader_filename = "clutk/clutk.h")]
	public static void custom_render_quad_gaussian_blur_separable (Ctk.RenderTarget rt, Ctk.ShaderProgram shader, float sigma, int window_w, int window_h, int x, int y, int w, int h);
	[CCode (cname = "custom_render_quad_texture_mask", cheader_filename = "clutk/clutk.h")]
	public static void custom_render_quad_texture_mask (Ctk.RenderTarget fbo, uint texid, uint texture_width, uint texture_height, Ctk.ShaderProgram shader, int window_w, int window_h, int x, int y, int w, int h);
	[CCode (cname = "delete_shader_program", cheader_filename = "clutk/clutk.h")]
	public static void delete_shader_program (Ctk.ShaderProgram sh);
	[CCode (cheader_filename = "clutk/clutk.h")]
	public static void dnd_init (Gtk.Widget widget, Gtk.TargetEntry[] targets);
	[CCode (cheader_filename = "clutk/clutk.h")]
	public static void drag_dest_start (Ctk.Actor widget);
	[CCode (cheader_filename = "clutk/clutk.h")]
	public static void drag_get_data (Ctk.Actor actor, Gdk.DragContext context, Gdk.Atom target, uint32 time_);
	[CCode (cheader_filename = "clutk/clutk.h")]
	public static void init ([CCode (array_length_pos = 0.9)] ref unowned string[] argv);
	[CCode (cname = "ogldraw_render_fullscreen_quad", cheader_filename = "clutk/clutk.h")]
	public static void ogldraw_render_fullscreen_quad (Ctk.RenderTarget fbo, Ctk.ShaderProgram shader, int window_w, int window_h, int x, int y, int w, int h);
}
