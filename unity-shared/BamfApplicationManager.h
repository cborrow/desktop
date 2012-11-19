// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Tim Penhey <tim.penhey@canonical.com>
 */

#ifndef UNITYSHARED_BAMF_APPLICATION_MANAGER_H
#define UNITYSHARED_BAMF_APPLICATION_MANAGER_H

#include <libbamf/libbamf.h>
#include <UnityCore/GLibWrapper.h>
#include <UnityCore/GLibSignal.h>

#include "unity-shared/ApplicationManager.h"


namespace unity
{
namespace bamf
{
class Manager;
class View
{
public:
  View(Manager const& manager,
       glib::Object<BamfView> const& view);

  std::string title() const;

protected:
  Manager const& manager_;
  glib::Object<BamfView> bamf_view_;
};

// NOTE: Can't use Window as a type as there is a #define for Window to some integer value.
class AppWindow: public ::unity::ApplicationWindow, public View
{
public:
  AppWindow(Manager const& manager,
            glib::Object<BamfView> const& window);

  virtual std::string title() const;
  virtual Window window_id() const;
  virtual int monitor() const;
  virtual ApplicationPtr application() const;

private:
  glib::Object<BamfWindow> bamf_window_;
};

class Tab: public ::unity::ApplicationWindow, public View
{
public:
  Tab(Manager const& manager,
      glib::Object<BamfView> const& tab);

  virtual std::string title() const;
  virtual Window window_id() const;
  virtual int monitor() const;
  virtual ApplicationPtr application() const;

private:
  glib::Object<BamfTab> bamf_tab_;
};


class Application : public ::unity::Application, public View
{
public:
  Application(Manager const& manager,
              glib::Object<BamfView> const& app);
  Application(Manager const& manager,
              glib::Object<BamfApplication> const& app);
  ~Application();

  virtual std::string title() const;
  virtual std::string icon() const;

  virtual WindowList get_windows() const;

private: // Property getters and setters
  void HookUpEvents();

  bool GetSeen() const;
  bool SetSeen(bool const& param);

  bool GetSticky() const;
  bool SetSticky(bool const& param);

  bool GetVisible() const;
  bool GetActive() const;
  bool GetRunning() const;
  bool GetUrgent() const;

private:
  glib::Object< ::BamfApplication> bamf_app_;
  glib::SignalManager signals_;
};

class Manager : public ::unity::ApplicationManager
{
public:
  Manager();
  ~Manager();

  virtual ApplicationWindowPtr GetActiveWindow() const;

  virtual ApplicationPtr active_application() const;
  virtual ApplicationPtr GetApplicationForDesktopFile(std::string const& desktop_file) const;

  virtual ApplicationList running_applications() const;


  virtual ApplicationPtr GetApplicationForWindow(BamfWindow* window) const;

private:
  void OnViewOpened(BamfMatcher* matcher, BamfView* view);

private:
  glib::Object<BamfMatcher> matcher_;
  glib::Signal<void, BamfMatcher*, BamfView*> view_opened_signal_;

};

} // namespace bamf
} // namespace unity

#endif // UNITYSHARED_APPLICATION_MANAGER_H
