// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef UNITY_LENS_H
#define UNITY_LENS_H

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <NuxCore/Property.h>
#include <sigc++/trackable.h>

#include "Categories.h"
#include "Results.h"

namespace unity
{
namespace dash
{

class Lens : public sigc::trackable, boost::noncopyable
{
public:
  typedef boost::shared_ptr<Lens> Ptr;

  Lens(std::string const& id,
       std::string const& dbus_name,
       std::string const& dbus_path,
       std::string const& name,
       std::string const& icon,
       std::string const& description = "",
       std::string const& search_hint = "",
       bool visible = true,
       std::string const& shortcut = "");

  ~Lens();

  void GlobalSearch(std::string const& search_string);
  void Search(std::string const& search_string);

  nux::RWProperty<std::string> id;
  nux::RWProperty<std::string> dbus_name;
  nux::RWProperty<std::string> dbus_path;
  nux::RWProperty<std::string> name;
  nux::RWProperty<std::string> icon_hint;
  nux::RWProperty<std::string> description;
  nux::RWProperty<std::string> search_hint;
  nux::RWProperty<bool> visible;
  nux::RWProperty<bool> search_in_global;
  nux::RWProperty<std::string> shortcut;
  nux::RWProperty<Results::Ptr> results;
  nux::RWProperty<Results::Ptr> global_results;
  nux::RWProperty<Categories::Ptr> categories;
  nux::RWProperty<bool> connected;

  nux::Property<bool> active;

  sigc::signal<void, std::string const&> search_finished;
  sigc::signal<void, std::string const&> global_search_finished;

  class Impl;
private:
  Impl* pimpl;
};

}
}

#endif
