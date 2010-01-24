/* indicator.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Indicator", lower_case_cprefix = "indicator_")]
namespace Indicator {
	[CCode (cheader_filename = "libindicate/indicate-object.h")]
	public class Object : GLib.Object {
		[CCode (has_construct_function = false)]
		public Object.from_file (string file);
		public virtual unowned GLib.List get_entries ();
		[NoWrapper]
		public virtual unowned Gtk.Image get_image ();
		[NoWrapper]
		public virtual unowned Gtk.Label get_label ();
		public virtual uint get_location (Indicator.ObjectEntry entry);
		[NoWrapper]
		public virtual unowned Gtk.Menu get_menu ();
		[NoWrapper]
		public virtual void indicator_object_reserved_1 ();
		[NoWrapper]
		public virtual void indicator_object_reserved_2 ();
		public virtual signal void entry_added (Indicator.ObjectEntry entry);
		public virtual signal void entry_moved (Indicator.ObjectEntry entry, uint old_pos, uint new_pos);
		public virtual signal void entry_removed (Indicator.ObjectEntry entry);
	}
	[Compact]
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public class ObjectEntry {
		public weak Gtk.Image image;
		public weak Gtk.Label label;
		public weak Gtk.Menu menu;
	}
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public class Service : GLib.Object {
		[CCode (has_construct_function = false)]
		public Service (string name);
		[NoWrapper]
		public virtual void indicator_service_reserved1 ();
		[NoWrapper]
		public virtual void indicator_service_reserved2 ();
		[NoWrapper]
		public virtual void indicator_service_reserved3 ();
		[NoWrapper]
		public virtual void indicator_service_reserved4 ();
		[CCode (has_construct_function = false)]
		public Service.version (string name, uint version);
		[NoAccessorMethod]
		public string name { owned get; set; }
		public virtual signal void shutdown ();
	}
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public class ServiceManager : GLib.Object {
		[CCode (has_construct_function = false)]
		public ServiceManager (string dbus_name);
		public bool connected ();
		[NoWrapper]
		public virtual void indicator_service_manager_reserved1 ();
		[NoWrapper]
		public virtual void indicator_service_manager_reserved2 ();
		[NoWrapper]
		public virtual void indicator_service_manager_reserved3 ();
		[NoWrapper]
		public virtual void indicator_service_manager_reserved4 ();
		public void set_refresh (uint time_in_ms);
		[CCode (has_construct_function = false)]
		public ServiceManager.version (string dbus_name, uint version);
		[NoAccessorMethod]
		public string name { owned get; set; }
		public virtual signal void connection_change (bool connected);
	}
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h", has_target = false)]
	public delegate GLib.Type get_type_t ();
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h", has_target = false)]
	public delegate unowned string get_version_t ();
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string GET_TYPE_S;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string GET_VERSION_S;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string OBJECT_SIGNAL_ENTRY_ADDED;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string OBJECT_SIGNAL_ENTRY_MOVED;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string OBJECT_SIGNAL_ENTRY_REMOVED;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string SERVICE_MANAGER_SIGNAL_CONNECTION_CHANGE;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string SERVICE_SIGNAL_SHUTDOWN;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const int SET_VERSION;
	[CCode (cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public const string VERSION;
	[CCode (cname = "get_version", cheader_filename = "gtk/gtk.h,libindicator/indicator.h,libindicator/indicator-object.h,libindicator-service.h,libindicator-service-manager.h")]
	public static unowned string get_version ();
}
