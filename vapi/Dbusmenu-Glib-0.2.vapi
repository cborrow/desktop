/* Dbusmenu-Glib-0.2.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Dbusmenu", lower_case_cprefix = "dbusmenu_")]
namespace Dbusmenu {
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public class Client : GLib.Object {
		public weak GLib.Object parent;
		[CCode (has_construct_function = false)]
		public Client (string name, string object);
		public bool add_type_handler (string type, Dbusmenu.ClientTypeHandler newfunc);
		public Dbusmenu.Menuitem get_root ();
		public void send_about_to_show (int id, void* cb, void* cb_data);
		public void send_event (int id, string name, GLib.Value value, uint timestamp);
		public string dbus_name { get; construct; }
		public string dbus_object { get; construct; }
		public signal void layout_updated ();
		public signal void new_menuitem (GLib.Object object);
		public signal void root_changed (GLib.Object object);
	}
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public class Menuitem : GLib.Object {
		public weak GLib.Object parent;
		[CCode (has_construct_function = false)]
		public Menuitem ();
		public bool child_add_position (Dbusmenu.Menuitem child, uint position);
		public bool child_append (Dbusmenu.Menuitem child);
		public bool child_delete (Dbusmenu.Menuitem child);
		public Dbusmenu.Menuitem child_find (int id);
		public bool child_prepend (Dbusmenu.Menuitem child);
		public bool child_reorder (Dbusmenu.Menuitem child, uint position);
		public Dbusmenu.Menuitem find_id (int id);
		public void @foreach (void* func, void* data);
		public unowned GLib.List get_children ();
		public int get_id ();
		public uint get_position (Dbusmenu.Menuitem parent);
		public uint get_position_realized (Dbusmenu.Menuitem parent);
		public bool get_root ();
		public virtual void handle_event (string name, GLib.Value value, uint timestamp);
		public GLib.HashTable properties_copy ();
		public GLib.List properties_list ();
		public bool property_exist (string property);
		public unowned string property_get (string property);
		public bool property_get_bool (string property);
		public int property_get_int (string property);
		public GLib.Value property_get_value (string property);
		public void property_remove (string property);
		public bool property_set (string property, string value);
		public bool property_set_bool (string property, bool value);
		public bool property_set_int (string property, int value);
		public bool property_set_value (string property, GLib.Value value);
		public virtual void send_about_to_show (Dbusmenu.menuitem_about_to_show_cb cb, void* cb_data);
		public void set_root (bool root);
		public GLib.List take_children ();
		[CCode (has_construct_function = false)]
		public Menuitem.with_id (int id);
		public int id { get; construct; }
		public signal void child_added (GLib.Object object, uint p0);
		public signal void child_moved (GLib.Object object, uint p0, uint p1);
		public signal void child_removed (GLib.Object object);
		public signal void item_activated (uint object);
		public signal void property_changed (string object, void* p0);
		public signal void realized ();
	}
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public class MenuitemProxy : Dbusmenu.Menuitem {
		public weak Dbusmenu.Menuitem parent;
		[CCode (has_construct_function = false)]
		public MenuitemProxy (Dbusmenu.Menuitem mi);
		public Dbusmenu.Menuitem get_wrapped ();
		public Dbusmenu.Menuitem menu_item { get; construct; }
	}
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public class Server : GLib.Object {
		public weak GLib.Object parent;
		[CCode (has_construct_function = false)]
		public Server (string object);
		public void set_root (Dbusmenu.Menuitem root);
		public string dbus_object { get; construct; }
		public Dbusmenu.Menuitem root_node { get; set; }
		public uint version { get; }
		public signal void item_property_updated (int object, string p0, GLib.Value p1);
		public signal void item_updated (int object);
		public signal void layout_updated (uint object, int p0);
	}
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h", has_target = false)]
	public delegate bool ClientTypeHandler (Dbusmenu.Menuitem newitem, Dbusmenu.Menuitem parent, Dbusmenu.Client client);
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h", has_target = false)]
	public delegate void menuitem_about_to_show_cb (Dbusmenu.Menuitem mi, void* user_data);
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h", has_target = false)]
	public delegate void menuitem_buildxml_slot_t (Dbusmenu.Menuitem mi, ref unowned string[] stringarray);
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_PROP_DBUS_NAME;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_PROP_DBUS_OBJECT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_SIGNAL_LAYOUT_UPDATED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_SIGNAL_NEW_MENUITEM;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_SIGNAL_ROOT_CHANGED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_TYPES_DEFAULT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_TYPES_IMAGE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string CLIENT_TYPES_SEPARATOR;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_CHILD_DISPLAY_SUBMENU;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_ICON_NAME_BLANK;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_CHILD_DISPLAY;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_ENABLED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_ICON_DATA;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_ICON_NAME;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_LABEL;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_SHORTCUT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_TOGGLE_STATE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_TOGGLE_TYPE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_TYPE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_PROP_VISIBLE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SHORTCUT_ALT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SHORTCUT_CONTROL;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SHORTCUT_SHIFT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SHORTCUT_SUPER;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_CHILD_ADDED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_CHILD_MOVED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_CHILD_REMOVED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_ITEM_ACTIVATED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_PROPERTY_CHANGED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_SIGNAL_REALIZED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_TOGGLE_CHECK;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string MENUITEM_TOGGLE_RADIO;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const int MENUITEM_TOGGLE_STATE_CHECKED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const int MENUITEM_TOGGLE_STATE_UNCHECKED;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const int MENUITEM_TOGGLE_STATE_UNKNOWN;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_PROP_DBUS_OBJECT;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_PROP_ROOT_NODE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_PROP_VERSION;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_SIGNAL_ID_PROP_UPDATE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_SIGNAL_ID_UPDATE;
	[CCode (cheader_filename = "libdbusmenu-glib/client.h,libdbusmenu-glib/menuitem-proxy.h,libdbusmenu-glib/menuitem.h,libdbusmenu-glib/server.h")]
	public const string SERVER_SIGNAL_LAYOUT_UPDATED;
}
