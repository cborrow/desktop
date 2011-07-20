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

#include "Nux/Nux.h"
#include "Nux/BaseWindow.h"

#include "SimpleLauncherIcon.h"
#include "Launcher.h"
#include "PluginAdapter.h"

SimpleLauncherIcon::SimpleLauncherIcon(Launcher* IconManager)
  : LauncherIcon(IconManager)
  , icon_(0)
  , theme_changed_id_(0)
{
  LauncherIcon::mouse_down.connect(sigc::mem_fun(this, &SimpleLauncherIcon::OnMouseDown));
  LauncherIcon::mouse_up.connect(sigc::mem_fun(this, &SimpleLauncherIcon::OnMouseUp));
  LauncherIcon::mouse_click.connect(sigc::mem_fun(this, &SimpleLauncherIcon::OnMouseClick));
  LauncherIcon::mouse_enter.connect(sigc::mem_fun (this, &SimpleLauncherIcon::OnMouseEnter));
  LauncherIcon::mouse_leave.connect(sigc::mem_fun (this, &SimpleLauncherIcon::OnMouseLeave));

  theme_changed_id_ = g_signal_connect (gtk_icon_theme_get_default (), "changed",
                                        G_CALLBACK (SimpleLauncherIcon::OnIconThemeChanged), this);
}

SimpleLauncherIcon::~SimpleLauncherIcon()
{
  if (icon_)
    icon_->UnReference ();

  if (theme_changed_id_)
    g_signal_handler_disconnect(gtk_icon_theme_get_default(), theme_changed_id_);
}

void SimpleLauncherIcon::OnMouseDown(int button)
{
}

void SimpleLauncherIcon::OnMouseUp(int button)
{
}

void SimpleLauncherIcon::OnMouseClick(int button)
{
}

void SimpleLauncherIcon::OnMouseEnter()
{
}

void SimpleLauncherIcon::OnMouseLeave()
{
}

void SimpleLauncherIcon::ActivateLauncherIcon(ActionArg arg)
{
  activate.emit();
}

nux::BaseTexture* SimpleLauncherIcon::GetTextureForSize(int size)
{
  if (icon_ && size == last_size_)
    return icon_;
  
  last_size_ = size;

  if (icon_)
    icon_->UnReference ();
  icon_ = 0;

  if (icon_name_.empty())
    return 0;

  if (icon_name_[0] == '/')
    icon_ = TextureFromPath(icon_name_.c_str(), size);
  else
    icon_ = TextureFromGtkTheme(icon_name_.c_str(), size);
  return icon_;
}

void SimpleLauncherIcon::SetIconName(const char *name)
{
  icon_name_ = name;
  ReloadIcon();
}

void SimpleLauncherIcon::ReloadIcon()
{
  if (icon_)
  {
    icon_->UnReference ();
    icon_ = 0;
  }
  needs_redraw.emit(this);
}

void SimpleLauncherIcon::OnIconThemeChanged(GtkIconTheme* icon_theme, gpointer data)
{
  SimpleLauncherIcon *self;

  if (!data)
    return;

  // invalidate the current cache
  _current_theme_is_mono = -1;

  self = (SimpleLauncherIcon*) data;
  self->ReloadIcon();
}
