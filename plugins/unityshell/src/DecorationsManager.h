// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2013 Canonical Ltd
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
* Authored by: Marco Trevisan <marco.trevisan@canonical.com>
*/

#ifndef UNITY_DECORATION_MANAGER
#define UNITY_DECORATION_MANAGER

#include <memory>
#include <X11/Xlib.h>

class CompRegion;

namespace unity
{
class UnityWindow;
class UnityScreen;

namespace decoration
{
class Manager;

class Window
{
public:
  typedef std::shared_ptr<Window> Ptr;

  Window(UnityWindow*);
  virtual ~Window();

  void Update();
  void UpdateFrameRegion(CompRegion*);

private:
  Window(Window const&) = delete;
  Window& operator=(Window const&) = delete;

  friend class Manager;

  struct Impl;
  std::unique_ptr<Impl> impl_;
};

class Manager
{
public:
  typedef std::shared_ptr<Manager> Ptr;

  Manager(UnityScreen*);
  virtual ~Manager();

  void AddSupportedAtoms(std::vector<Atom>& atoms) const;
  bool HandleEventBefore(XEvent*);
  bool HandleEventAfter(XEvent*);

  Window::Ptr HandleWindow(UnityWindow*);
  void UnHandleWindow(UnityWindow*);

  Window::Ptr GetWindowByXid(::Window);

private:
  Manager(Manager const&) = delete;
  Manager& operator=(Manager const&) = delete;

  friend class Window;

  struct Impl;
  std::unique_ptr<Impl> impl_;
};

} // decoration namespace
} // unity namespace

#endif
