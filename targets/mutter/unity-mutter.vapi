/* unity-mutter.vapi generated by valac, do not modify. */

[CCode (cprefix = "Unity", lower_case_cprefix = "unity_")]
namespace Unity {
	[CCode (cheader_filename = "unity-mutter.h")]
	public class ActorBlur : Ctk.Bin {
		public ActorBlur (Clutter.Actor actor);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class DragDest : Gtk.Window {
		public DragDest ();
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class ExposeClone : Clutter.Group {
		public ExposeClone (Mutter.Window source);
		public uint8 darken { get; set; }
		public uint8 hovered_opacity { get; set; }
		public Mutter.Window source { get; set; }
		public uint8 unhovered_opacity { get; set; }
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class ExposeManager : GLib.Object {
		public ExposeManager (Unity.Plugin plugin, Unity.Launcher.Launcher launcher);
		public void end_expose ();
		public void start_expose (GLib.SList<Wnck.Window> windows);
		public int bottom_buffer { get; set; }
		public bool coverflow { get; set; }
		public uint8 darken { get; set; }
		public bool expose_showing { get; set; }
		public uint8 hovered_opacity { get; set; }
		public int left_buffer { get; set; }
		public int right_buffer { get; set; }
		public int top_buffer { get; set; }
		public uint8 unhovered_opacity { get; set; }
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class Maximus : GLib.Object {
		public static string user_unmaximize_hint;
		public Maximus ();
		public bool process_window (Mutter.Window window);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class Plugin : GLib.Object, Unity.Shell {
		public Plugin ();
		public void destroy (Mutter.Window window);
		public void dexpose_windows ();
		public void expose_windows (GLib.SList<Wnck.Window> windows, int left_buffer = 250);
		public int get_launcher_width ();
		public int get_panel_height ();
		public void kill_effect (Mutter.Window window, ulong events);
		public void map (Mutter.Window window);
		public void maximize (Mutter.Window window, int x, int y, int width, int height);
		public void minimize (Mutter.Window window);
		public void switch_workspace (GLib.List<Mutter.Window> windows, int from, int to, int direction);
		public void topmost_changed (Mutter.Window old_window, Mutter.Window new_window);
		public void topmost_size_changed (Clutter.Actor actor, Clutter.ActorBox box, Clutter.AllocationFlags flags);
		public void unmaximize (Mutter.Window window, int x, int y, int width, int height);
		public bool expose_showing { get; }
		public Mutter.Plugin? plugin { get; set; }
		public signal void restore_input_region (bool fullscreen);
		public signal void window_destroyed (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_kill_effect (Unity.Plugin plugin, Mutter.Window window, ulong events);
		public signal void window_mapped (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_maximized (Unity.Plugin plugin, Mutter.Window window, int x, int y, int width, int height);
		public signal void window_minimized (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_unmaximized (Unity.Plugin plugin, Mutter.Window window, int x, int y, int width, int height);
		public signal void workspace_switch_event (Unity.Plugin plugin, GLib.List<Mutter.Window> windows, int from, int to, int direction);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class WindowManagement : GLib.Object {
		public WindowManagement (Unity.Plugin p);
	}
	[CCode (cprefix = "UNITY_INPUT_STATE_", cheader_filename = "unity-mutter.h")]
	public enum InputState {
		NONE,
		FULLSCREEN,
		UNITY,
		ZERO
	}
}
