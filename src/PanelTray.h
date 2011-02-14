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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef PANEL_TRAY_H
#define PANEL_TRAY_H

#include <Nux/View.h>
#include <gtk/gtk.h>

#include <gdk/gdkx.h>

#include "IndicatorObjectProxy.h"
#include "Introspectable.h"
#include "PanelIndicatorObjectView.h"

#include <unity-misc/na-tray.h>
#include <unity-misc/na-tray-child.h>
#include <unity-misc/na-tray-manager.h>

class PanelTray : public PanelIndicatorObjectView
{
public:

  PanelTray ();
  ~PanelTray ();

  void Draw (nux::GraphicsEngine& gfx_content, bool force_draw);
  
  Window GetTrayWindow ();

  void Sync ();

  void OnEntryAdded (IndicatorObjectEntryProxy *proxy);
  void OnEntryMoved (IndicatorObjectEntryProxy *proxy);
  void OnEntryRemoved (IndicatorObjectEntryProxy *proxy);
  int        _n_children;
protected:
  const gchar * GetName ();
  const gchar * GetChildsName ();
  void          AddProperties (GVariantBuilder *builder);

private:
  static gboolean FilterTrayCallback (NaTray *tray, NaTrayChild *child, PanelTray *self);
  static void     OnTrayIconRemoved  (NaTrayManager *manager, NaTrayChild *child, PanelTray *self);
  static gboolean IdleSync (PanelTray *tray);
  static gboolean OnTrayExpose (GtkWidget *widget, GdkEventExpose *ev, PanelTray *tray);

private:
  GtkWidget *_window;
  NaTray    *_tray;
  int        _last_x;
  int        _last_y;
};
#endif
