// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011-2012 Canonical Ltd
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
 * Authored by: Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *              Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 */

#include <NuxCore/Logger.h>

#include "LauncherEntryRemoteModel.h"

namespace unity
{

namespace
{
nux::logging::Logger logger("launcher.entry.remote.model");
}

/**
 * Helper class implementing the remote API to control the icons in the
 * launcher. Also known as the com.canonical.Unity.LauncherEntry DBus API.
 * It enables clients to dynamically control their launcher icons by
 * adding a counter, progress indicator, or emblem to it. It also supports
 * adding a quicklist menu by means of the dbusmenu library.
 *
 * We take care to print out any client side errors or oddities in detail,
 * in order to help third party developers as much as possible when integrating
 * with Unity.
 */
LauncherEntryRemoteModel::LauncherEntryRemoteModel()
  : _launcher_entry_dbus_signal_id(0)
{
  glib::Error error;

  _conn = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &error);
  if (error)
  {
    LOG_ERROR(logger) << "Unable to connect to session bus: " << error.Message();
    return;
  }

  /* Listen for *all* signals on the "com.canonical.Unity.LauncherEntry"
   * interface, no matter who the sender is */
  _launcher_entry_dbus_signal_id =
    g_dbus_connection_signal_subscribe(_conn,
                                       NULL,                       // sender
                                       "com.canonical.Unity.LauncherEntry",
                                       NULL,                       // member
                                       NULL,                       // path
                                       NULL,                       // arg0
                                       G_DBUS_SIGNAL_FLAGS_NONE,
                                       &on_launcher_entry_signal_received,
                                       this,
                                       NULL);

  _dbus_name_owner_changed_signal_id =
    g_dbus_connection_signal_subscribe(_conn,
                                       "org.freedesktop.DBus",     // sender
                                       "org.freedesktop.DBus",     // interface
                                       "NameOwnerChanged",         // member
                                       "/org/freedesktop/DBus",    // path
                                       NULL,                       // arg0
                                       G_DBUS_SIGNAL_FLAGS_NONE,
                                       &on_dbus_name_owner_changed_signal_received,
                                       this,
                                       NULL);
}

LauncherEntryRemoteModel::~LauncherEntryRemoteModel()
{
  if (_launcher_entry_dbus_signal_id && _conn)
  {
    g_dbus_connection_signal_unsubscribe(_conn,
                                         _launcher_entry_dbus_signal_id);
  }
  if (_dbus_name_owner_changed_signal_id && _conn)
  {
    g_dbus_connection_signal_unsubscribe(_conn,
                                         _dbus_name_owner_changed_signal_id);
  }
}

/**
 * Return the number of unique LauncherEntryRemote objects managed by the model.
 * The entries are identified by their LauncherEntryRemote::AppUri property.
 */
unsigned int LauncherEntryRemoteModel::Size() const
{
  return _entries_by_uri.size();
}

/**
 * Return a smart pointer to a LauncherEntryRemote if there is one for app_uri,
 * otherwise NULL.
 *
 * App Uris look like application://$desktop_file_id, where desktop_file_id
 * is the base name of the .desktop file for the application including the
 * .desktop extension. Eg. application://firefox.desktop.
 */
LauncherEntryRemote::Ptr LauncherEntryRemoteModel::LookupByUri(std::string const& app_uri)
{
  auto target_en = _entries_by_uri.find(app_uri);

  return (target_en != _entries_by_uri.end()) ? target_en->second : nullptr;
}

/**
 * Return a smart pointer to a LauncherEntryRemote if there is one for desktop_id,
 * otherwise NULL.
 *
 * The desktop id is the base name of the .desktop file for the application
 * including the .desktop extension. Eg. firefox.desktop.
 */
LauncherEntryRemote::Ptr LauncherEntryRemoteModel::LookupByDesktopId(std::string const& desktop_id)
{
  std::string prefix = "application://";
  return LookupByUri(prefix + desktop_id);
}

/**
 * Return a smart pointer to a LauncherEntryRemote if there is one for
 * desktop_file_path, otherwise NULL.
 */
LauncherEntryRemote::Ptr LauncherEntryRemoteModel::LookupByDesktopFile(std::string const& desktop_file_path)
{
  std::string desktop_id;

  if (!desktop_file_path.empty())
  {
    size_t id_pos = desktop_file_path.rfind('/');

    if (id_pos != std::string::npos)
    {
      size_t id_start = id_pos + 1;

      desktop_id = (id_start < desktop_file_path.length()) ? desktop_file_path.substr(id_start) : "";
    }
  }

  if (desktop_id.empty())
    return nullptr;

  return LookupByDesktopId(desktop_id);
}

/**
 * Get a list of all application URIs which have registered with the launcher
 * API.
 */
std::list<std::string> LauncherEntryRemoteModel::GetUris() const
{
  std::list<std::string> uris;

  for (auto entry : _entries_by_uri)
    uris.push_back(entry.first);

  return uris;
}

/**
 * Add or update a remote launcher entry.
 */
void LauncherEntryRemoteModel::AddEntry(LauncherEntryRemote::Ptr const& entry)
{
  auto existing_entry = LookupByUri(entry->AppUri());
  if (existing_entry)
  {
    existing_entry->Update(entry);
  }
  else
  {
    _entries_by_uri[entry->AppUri()] = entry;
    entry_added.emit(entry);
  }
}

/**
 * Add or update a remote launcher entry.
 */
void LauncherEntryRemoteModel::RemoveEntry(LauncherEntryRemote::Ptr const& entry)
{
  _entries_by_uri.erase(entry->AppUri());
  entry_removed.emit(entry);
}

/**
 * Handle an incoming Update() signal from DBus
 */
void LauncherEntryRemoteModel::HandleUpdateRequest(const gchar* sender_name,
                                              GVariant*    parameters)
{
  GVariantIter* prop_iter;

  if (!sender_name || !parameters)
    return;

  if (!g_variant_is_of_type(parameters, G_VARIANT_TYPE("(sa{sv})")))
  {
    LOG_ERROR(logger) << "Received 'com.canonical.Unity.LauncherEntry.Update' with"
                         " illegal payload signature '"
                      << g_variant_get_type_string(parameters)
                      << "'. Expected '(sa{sv})'.";
    return;
  }

  if (sender_name == NULL)
  {
    LOG_ERROR(logger) << "Received 'com.canonical.Unity.LauncherEntry.Update' from"
                         " an undefined sender. This may happen if you are trying "
                         "to run Unity on a p2p DBus connection.";
    return;
  }

  glib::String app_uri;
  g_variant_get(parameters, "(sa{sv})", &app_uri, &prop_iter);
  auto entry = LookupByUri(app_uri.Str());

  if (entry)
  {
    /* It's important that we update the DBus name first since it might
     * unset the quicklist if it changes */
    entry->SetDBusName(sender_name);
    entry->Update(prop_iter);
  }
  else
  {
    LauncherEntryRemote::Ptr entry_ptr(new LauncherEntryRemote(sender_name, parameters));
    AddEntry(entry_ptr);
  }

  g_variant_iter_free(prop_iter);
}

void LauncherEntryRemoteModel::on_launcher_entry_signal_received(GDBusConnection* connection,
                                                            const gchar*     sender_name,
                                                            const gchar*     object_path,
                                                            const gchar*     interface_name,
                                                            const gchar*     signal_name,
                                                            GVariant*        parameters,
                                                            gpointer         user_data)
{
  LauncherEntryRemoteModel* self;

  self = static_cast<LauncherEntryRemoteModel*>(user_data);

  if (parameters == NULL)
  {
    LOG_ERROR(logger) << "Received DBus signal '" << interface_name << "."
                      << signal_name << "' with empty payload from " << sender_name;
    return;
  }

  if (g_strcmp0(signal_name, "Update") == 0)
  {
    self->HandleUpdateRequest(sender_name, parameters);
  }
  else
  {
    LOG_ERROR(logger) << "Unknown signal '" << interface_name << "."
                      << signal_name << "' from " << sender_name;
  }
}

void
LauncherEntryRemoteModel::on_dbus_name_owner_changed_signal_received(GDBusConnection* connection,
                                                                     const gchar* sender_name,
                                                                     const gchar* object_path,
                                                                     const gchar* interface_name,
                                                                     const gchar* signal_name,
                                                                     GVariant* parameters,
                                                                     gpointer user_data)
{
  auto self = static_cast<LauncherEntryRemoteModel*>(user_data);

  if (parameters == NULL || self->_entries_by_uri.empty())
    return;

  gchar *name, *before, *after;
  g_variant_get(parameters, "(&s&s&s)", &name, &before, &after);

  if (!after[0])
  {
    // Name gone, find and destroy LauncherEntryRemote
    std::vector<LauncherEntryRemote::Ptr> to_rm;

    for (auto it = self->_entries_by_uri.begin(); it != self->_entries_by_uri.end(); ++it)
    {
      auto entry = it->second;

      if (name && entry->DBusName() == std::string(name))
      {
        to_rm.push_back(entry);
      }
    }

    for (auto entry : to_rm)
    {
      self->RemoveEntry(entry);
    }
  }
}

}
