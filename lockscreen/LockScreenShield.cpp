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
* Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
*/

#include "LockScreenShield.h"

#include <Nux/VLayout.h>
#include <Nux/HLayout.h>
#include <Nux/PaintLayer.h>
#include <UnityCore/DBusIndicators.h>

#include "BackgroundSettings.h"
#include "CofView.h"
#include "LockScreenSettings.h"
#include "UserPromptView.h"
#include "panel/PanelView.h"
#include "unity-shared/GnomeKeyGrabber.h"
#include "unity-shared/PanelStyle.h"

namespace unity
{
namespace lockscreen
{

Shield::Shield(session::Manager::Ptr const& session_manager, int monitor, bool is_primary)
  : MockableBaseWindow("Lockscreen")
  , primary(is_primary)
  , session_manager_(session_manager)
  , monitor_(monitor)
  , bg_settings_(new BackgroundSettings)
  , prompt_view_(nullptr)
{
  SetLayout(new nux::VLayout());

  is_primary ? ShowPrimaryView() : ShowSecondaryView();

  EnableInputWindow(true);

  geometry_changed.connect([this](nux::Area*, nux::Geometry&) {
    UpdateBackgroundTexture();
  });
}

void Shield::UpdateBackgroundTexture()
{
  auto background_texture = bg_settings_->GetBackgroundTexture(monitor_, true, true);
  background_layer_.reset(new nux::TextureLayer(background_texture->GetDeviceTexture(), nux::TexCoordXForm(), nux::color::White, true));
  SetBackgroundLayer(background_layer_.get());
}

void Shield::ShowPrimaryView()
{
  GrabPointer();
  GrabKeyboard();

  nux::Layout* main_layout = GetLayout();

  main_layout->AddView(CreatePanel());

  nux::HLayout* prompt_layout = new nux::HLayout();
  prompt_layout->SetLeftAndRightPadding(2 * Settings::GRID_SIZE);

  prompt_view_ = CreatePromptView();
  prompt_layout->AddView(prompt_view_);

  // 10 is just a random number to center the prompt view.
  main_layout->AddSpace(0, 10);
  main_layout->AddLayout(prompt_layout);
  main_layout->AddSpace(0, 10);
}

void Shield::ShowSecondaryView()
{
  nux::Layout* main_layout = GetLayout();

  // The circle of friends
  CofView* cof_view = new CofView();
  main_layout->AddView(cof_view);
}

nux::View* Shield::CreatePanel()
{
  auto indicators = std::make_shared<indicator::LockScreenDBusIndicators>();
  auto gnome_grabber = std::make_shared<key::GnomeGrabber>();
  auto menu_manager = std::make_shared<menu::Manager>(indicators, gnome_grabber);

  // Hackish but ok for the moment. Would be nice to have menus without grab.
  indicators->on_entry_show_menu.connect(sigc::mem_fun(this, &Shield::OnIndicatorEntryShowMenu));
  indicators->on_entry_activated.connect(sigc::mem_fun(this, &Shield::OnIndicatorEntryActivated));

  panel::PanelView* panel_view = new panel::PanelView(this, menu_manager, /*lockscreen_mode*/ true);
  panel_view->SetMaximumHeight(panel::Style::Instance().PanelHeight(monitor_));
  panel_view->SetOpacity(0.5);
  panel_view->SetMonitor(monitor_);

  return panel_view;
}

UserPromptView* Shield::CreatePromptView()
{
  auto* prompt_view = new UserPromptView(session_manager_);

  auto width = 8 * Settings::GRID_SIZE;
  auto height = 3 * Settings::GRID_SIZE;

  prompt_view->SetMinimumWidth(width);
  prompt_view->SetMaximumWidth(width);
  prompt_view->SetMinimumHeight(height);

  return prompt_view;
}

void Shield::OnIndicatorEntryShowMenu(std::string const&, unsigned, int, int, unsigned)
{
  UnGrabPointer();
  UnGrabKeyboard();
}

void Shield::OnIndicatorEntryActivated(std::string const& panel, std::string const& entry, nux::Geometry const& geo)
{
  if (entry.empty() and geo.IsNull()) /* on menu closed */
  {
    GrabPointer();
    GrabKeyboard();
  }
}

nux::Area* Shield::FindKeyFocusArea(unsigned int,
                                    unsigned long,
                                    unsigned long)
{
  if (prompt_view_ && prompt_view_->focus_view() && prompt_view_->focus_view()->GetInputEventSensitivity())
    return prompt_view_->focus_view();
  else
    return nullptr;
}


bool Shield::AcceptKeyNavFocus()
{
  return false;
}

}
}
