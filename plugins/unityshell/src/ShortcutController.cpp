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
 * Authored by: Andrea Azzarone <azzaronea@gmail.com>
 */

#include "ShortcutController.h"

#include "UBusMessages.h"
#include "ubus-server.h"
#include "WindowManager.h"

namespace unity
{
namespace shortcut
{
namespace
{
const unsigned int SUPER_TAP_DURATION = 650;
} // anonymouse namespace;


  
Controller::Controller(std::list<AbstractHint*>& hints)
  : view_window_(0)
  , visible_(false)
  , show_timer_(0)

{
  bg_color_ = nux::Color(0.0, 0.0, 0.0, 0.5);

  UBusServer *ubus = ubus_server_get_default();
  bg_update_handle_ = ubus_server_register_interest(ubus, UBUS_BACKGROUND_COLOR_CHANGED,
                                                    (UBusCallback)&Controller::OnBackgroundUpdate,
                                                    this);

  model_.reset(new Model(hints));
}

Controller::~Controller()
{
  ubus_server_unregister_interest(ubus_server_get_default(), bg_update_handle_);
  
  if (view_window_)
    view_window_->UnReference();
}

void Controller::OnBackgroundUpdate(GVariant* data, Controller* self)
{
  gdouble red, green, blue, alpha;
  g_variant_get(data, "(dddd)", &red, &green, &blue, &alpha);
  self->bg_color_ = nux::Color(red, green, blue, alpha);

  if (self->view_)
    self->view_->background_color = self->bg_color_;
}

void Controller::Show()
{
  if (show_timer_)
    g_source_remove (show_timer_);
  show_timer_ = g_timeout_add(SUPER_TAP_DURATION, &Controller::OnShowTimer, this);

  model_->Fill();
  visible_ = true;

  ubus_server_send_message(ubus_server_get_default(),
                           UBUS_PLACE_VIEW_CLOSE_REQUEST,
                           NULL);
}

gboolean Controller::OnShowTimer(gpointer data)
{
  Controller* self = static_cast<Controller*>(data);

  if (self->visible_)
    self->ConstructView();

  self->show_timer_ = 0;
  return FALSE;
}

void Controller::ConstructView()
{
  view_ = View::Ptr(new View());
  view_->SetModel(model_);
  view_->background_color = bg_color_;

  if (!view_window_)
  {
    main_layout_ = new nux::HLayout(NUX_TRACKER_LOCATION);
    main_layout_->SetVerticalExternalMargin(0);
    main_layout_->SetHorizontalExternalMargin(0);

    view_window_ = new nux::BaseWindow("ShortcutHint");
    view_window_->SinkReference();
    view_window_->SetLayout(main_layout_);
    view_window_->SetBackgroundColor(nux::Color(0x00000000));
  }

  main_layout_->AddView(view_.GetPointer(), 1);

  view_window_->SetGeometry(workarea_);
  view_->SetupBackground();
  view_window_->ShowWindow(true);
}

void Controller::SetWorkspace(nux::Geometry geo)
{
  workarea_ = geo;
}

void Controller::Hide()
{
  if (!visible_)
    return;
    
  visible_ = false;

  if (view_)
    main_layout_->RemoveChildObject(view_.GetPointer());

  if (view_window_)
    view_window_->ShowWindow(false);

  if (show_timer_)
    g_source_remove(show_timer_);
  show_timer_ = 0;

  view_.Release();
}

bool Controller::Visible()
{
  return visible_;
}

} // namespace shortcut
} // namespace unity

