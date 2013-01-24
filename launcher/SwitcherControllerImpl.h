/*
 * Copyright (C) 2013 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License version 3, as published 
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranties of 
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SWITCHERCONTROLLERIMPL_H
#define SWITCHERCONTROLLERIMPL_H

#include <memory>

#include "AbstractLauncherIcon.h"
#include <UnityCore/Variant.h>
#include <UnityCore/GLibSource.h>

#include "unity-shared/Introspectable.h"
#include "unity-shared/UBusWrapper.h"

#include "SwitcherModel.h"
#include "SwitcherView.h"

#include <Nux/Nux.h>
#include <Nux/BaseWindow.h>
#include <Nux/WindowCompositor.h>

namespace unity
{
namespace switcher
{

class Controller::Impl : public debug::Introspectable
{
public:
  Impl(Controller* obj)
  : obj_(obj)
  {}

  virtual ~Impl() {}

  virtual void Show(ShowMode show,
                    SortMode sort,
                    std::vector<launcher::AbstractLauncherIcon::Ptr> results) = 0;
  virtual void Hide(bool accept_state) = 0;

  virtual bool CanShowSwitcher(const std::vector<launcher::AbstractLauncherIcon::Ptr>& resutls) const = 0;

  virtual bool Visible() = 0;

  virtual void Next() = 0;
  virtual void Prev() = 0;

  virtual void NextDetail() = 0;
  virtual void PrevDetail() = 0;

  virtual void Select(int index) = 0;

  virtual void SetDetail(bool detail,
                         unsigned int min_windows) = 0;

  virtual void SelectFirstItem() = 0;

  virtual void SetWorkspace(nux::Geometry geo,
                            int monitor) = 0;

  virtual SwitcherView* GetView() = 0;

  virtual ui::LayoutWindow::Vector ExternalRenderTargets() = 0;

  virtual guint GetSwitcherInputWindowId() const = 0;

  virtual bool IsShowDesktopDisabled() const = 0;
  virtual void SetShowDesktopDisabled(bool disabled) = 0;
  virtual int StartIndex() const = 0;
  virtual Selection GetCurrentSelection() const = 0;

  sigc::signal<void> view_built;
protected:
  Controller* obj_;
};

class ShellController : public Controller::Impl,
                        public sigc::trackable
{
public:
  nux::Property<int> timeout_length;

  ShellController(Controller* obj,
                  unsigned int load_timeout,
                  Controller::WindowCreator const& create_window);

  virtual void Show(ShowMode show, SortMode sort, std::vector<launcher::AbstractLauncherIcon::Ptr> results);
  virtual void Hide(bool accept_state);

  bool CanShowSwitcher(const std::vector<launcher::AbstractLauncherIcon::Ptr>& resutls) const;

  virtual bool Visible();

  virtual void Next();
  virtual void Prev();

  void NextDetail();
  void PrevDetail();

  virtual void Select(int index);

  void SetDetail(bool detail, unsigned int min_windows = 1);

  void SelectFirstItem();

  void SetWorkspace(nux::Geometry geo, int monitor);

  virtual SwitcherView* GetView();

  ui::LayoutWindow::Vector ExternalRenderTargets();

  guint GetSwitcherInputWindowId() const;

  bool IsShowDesktopDisabled() const;
  void SetShowDesktopDisabled(bool disabled);
  int StartIndex() const;
  Selection GetCurrentSelection() const;

protected:
  // Introspectable methods
  std::string GetName() const;
  void AddProperties(GVariantBuilder* builder);

  virtual void ConstructWindow();
  virtual void ConstructView();
  virtual void ShowView();

  virtual bool OnDetailTimer();
  void OnModelSelectionChanged(launcher::AbstractLauncherIcon::Ptr const& icon);

  unsigned int construct_timeout_;

private:
  void OnBackgroundUpdate(GVariant* data);
  static bool CompareSwitcherItemsPriority(launcher::AbstractLauncherIcon::Ptr const& first, launcher::AbstractLauncherIcon::Ptr const& second);

  SwitcherModel::Ptr model_;
  SwitcherView::Ptr view_;

  nux::Geometry workarea_;
  Controller::WindowCreator create_window_;
  nux::ObjectPtr<nux::BaseWindow> view_window_;
  nux::HLayout* main_layout_;

  nux::Color bg_color_;

  launcher::AbstractLauncherIcon::Ptr last_active_selection_;

  UBusManager ubus_manager_;
  glib::SourceManager sources_;
};

}
}

#endif // SWITCHERCONTROLLERIMPL_H
