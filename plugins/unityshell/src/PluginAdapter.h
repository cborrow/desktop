// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#ifndef PLUGINADAPTER_H
#define PLUGINADAPTER_H

/* Compiz */
#include <core/core.h>
#include <core/atoms.h>

#include <sigc++/sigc++.h>

#include "WindowManager.h"

typedef struct
{
  unsigned long flags;
  unsigned long functions;
  unsigned long decorations;
  long input_mode;
  unsigned long status;
} MotifWmHints, MwmHints;

class MultiActionList
{
public:

  MultiActionList(int n) :
    m_ActionList(n),
    _primary_action(NULL) {};

  void InitiateAll(CompOption::Vector& extraArgs, int state);
  void TerminateAll(CompOption::Vector& extraArgs);

  void AddNewAction(CompAction*, bool primary);
  void RemoveAction(CompAction*);
private:

  std::list <CompAction*> m_ActionList;
  CompAction*              _primary_action;
};


class PluginAdapter : public sigc::trackable, public WindowManager
{
public:
  static PluginAdapter* Default();

  static void Initialize(CompScreen* screen);

  ~PluginAdapter();

  void SetScaleAction(MultiActionList& scale);
  void SetExpoAction(MultiActionList& expo);

  void SetShowHandlesAction(CompAction* action)
  {
    _grab_show_action = action;
  }
  void SetHideHandlesAction(CompAction* action)
  {
    _grab_hide_action = action;
  }
  void SetToggleHandlesAction(CompAction* action)
  {
    _grab_toggle_action = action;
  }

  void OnWindowClosed (CompWindow *);
  void OnScreenGrabbed();
  void OnScreenUngrabbed();

  void OnShowDesktop ();
  void OnLeaveDesktop ();

  void TerminateScale();
  bool IsScaleActive();

  void InitiateExpo();
  bool IsExpoActive();

  void ShowGrabHandles(CompWindow* window, bool use_timer);
  void HideGrabHandles(CompWindow* window);
  void ToggleGrabHandles(CompWindow* window);

  void Notify(CompWindow* window, CompWindowNotify notify);
  void NotifyMoved(CompWindow* window, int x, int y);
  void NotifyResized(CompWindow* window, int x, int y, int w, int h);
  void NotifyStateChange(CompWindow* window, unsigned int state, unsigned int last_state);
  void NotifyCompizEvent(const char* plugin, const char* event, CompOption::Vector& option);

  void Decorate(guint32 xid);
  void Undecorate(guint32 xid);

  // WindowManager implementation
  bool IsWindowMaximized(guint xid);
  bool IsWindowDecorated(guint xid);
  bool IsWindowOnCurrentDesktop(guint xid);
  bool IsWindowObscured(guint xid);
  bool IsWindowMapped(guint xid);
  void Restore(guint32 xid);
  void Minimize(guint32 xid);
  void Close(guint32 xid);
  void Activate(guint32 xid);
  void Raise(guint32 xid);
  void Lower(guint32 xid);
  void ShowDesktop();

  void SetWindowIconGeometry(Window window, nux::Geometry const& geo);

  void FocusWindowGroup(std::vector<Window> windows);
  bool ScaleWindowGroup(std::vector<Window> windows, int state, bool force);

  bool IsScreenGrabbed();
  bool IsViewPortSwitchStarted();

  unsigned int GetWindowActiveNumber (guint32 xid);

  void MaximizeIfBigEnough(CompWindow* window);

  nux::Geometry GetWindowGeometry(guint32 xid);
  nux::Geometry GetScreenGeometry();
  
  void CheckWindowIntersections(nux::Geometry const& region, bool &active, bool &any);

  int WorkspaceCount();

  void SetCoverageAreaBeforeAutomaximize(float area);

  bool saveInputFocus ();
  bool restoreInputFocus ();

protected:
  PluginAdapter(CompScreen* screen);

private:
  std::string MatchStringForXids(std::vector<Window> *windows);
  void InitiateScale(std::string const& match, int state = 0);

  bool CheckWindowIntersection(nux::Geometry const& region, CompWindow* window);
  void SetMwmWindowHints(Window xid, MotifWmHints* new_hints);

  CompScreen* m_Screen;
  MultiActionList m_ExpoActionList;
  MultiActionList m_ScaleActionList;
  std::list <guint32> m_SpreadedWindows;

  bool _spread_state;
  bool _expo_state;
  bool _vp_switch_started;

  CompAction* _grab_show_action;
  CompAction* _grab_hide_action;
  CompAction* _grab_toggle_action;

  float _coverage_area_before_automaximize;

  bool _in_show_desktop;
  CompWindow* _last_focused_window;

  static PluginAdapter* _default;
};

#endif
