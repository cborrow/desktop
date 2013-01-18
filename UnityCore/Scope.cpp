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
 * Authored by: Nick Dedekind <nick.dedekind@canonical.com>
 *
 */

#include "Scope.h"
#include "MiscUtils.h"
#include "ScopeProxy.h"
#include <unity-protocol.h>


namespace unity
{
namespace dash
{
DECLARE_LOGGER(logger, "unity.dash.scope");

class Scope::Impl
{
public:
  Impl(Scope* owner, std::string const& scope_id);
  ~Impl();

  void Init();

  void Activate(std::string const& uri, guint action_type, glib::HintsMap const& hints, ActivateCallback const& callback, GCancellable* cancellable);
  void OnActivateReply(std::string const& uri, ScopeHandledType handled_type, glib::HintsMap const& hints, glib::Error const& error);

  DeeFilter* GetFilterForCategory(unsigned category, DeeFilter* filter)  const;

  Scope* owner_;
  std::string scope_id_;
  ScopeProxyInterface::Ptr proxy_;

  typedef std::shared_ptr<sigc::connection> ConnectionPtr;
  std::vector<ConnectionPtr> property_connections;
};

Scope::Impl::Impl(Scope* owner, std::string const& scope_id)
: owner_(owner)
, scope_id_(scope_id)
{
}

Scope::Impl::~Impl()
{
  for_each(property_connections.begin(), property_connections.end(), [](ConnectionPtr const& con) { con->disconnect(); });
  property_connections.clear();
}

void Scope::Impl::Init()
{
  proxy_ = owner_->CreateProxyInterface();

  if (proxy_)
  {
    property_connections.push_back(utils::ConnectProperties(owner_->connected, proxy_->connected));
    property_connections.push_back(utils::ConnectProperties(owner_->visible, proxy_->visible));
    property_connections.push_back(utils::ConnectProperties(owner_->is_master, proxy_->is_master));
    property_connections.push_back(utils::ConnectProperties(owner_->search_in_global, proxy_->search_in_global));
    property_connections.push_back(utils::ConnectProperties(owner_->search_hint, proxy_->search_hint));
    property_connections.push_back(utils::ConnectProperties(owner_->view_type, proxy_->view_type));
    property_connections.push_back(utils::ConnectProperties(owner_->results, proxy_->results));
    property_connections.push_back(utils::ConnectProperties(owner_->filters, proxy_->filters));
    property_connections.push_back(utils::ConnectProperties(owner_->categories, proxy_->categories));

    property_connections.push_back(utils::ConnectProperties(owner_->name, proxy_->name));
    property_connections.push_back(utils::ConnectProperties(owner_->description, proxy_->description));
    property_connections.push_back(utils::ConnectProperties(owner_->icon_hint, proxy_->icon_hint));
    property_connections.push_back(utils::ConnectProperties(owner_->category_icon_hint, proxy_->category_icon_hint));
    property_connections.push_back(utils::ConnectProperties(owner_->keywords, proxy_->keywords));
    property_connections.push_back(utils::ConnectProperties(owner_->type, proxy_->type));
    property_connections.push_back(utils::ConnectProperties(owner_->query_pattern, proxy_->query_pattern));
    property_connections.push_back(utils::ConnectProperties(owner_->shortcut, proxy_->shortcut));

    owner_->id.SetGetterFunction([this]() { return scope_id_; });

    owner_->results.SetGetterFunction([this]() { return proxy_->results(); });
    proxy_->results.changed.connect([this](Results::Ptr const& value) { owner_->results.EmitChanged(value); });

    owner_->filters.SetGetterFunction([this]() { return proxy_->filters(); });
    proxy_->filters.changed.connect([this](Filters::Ptr const& value) { owner_->filters.EmitChanged(value); });

    owner_->categories.SetGetterFunction([this]() { return proxy_->categories(); });
    proxy_->categories.changed.connect([this](Categories::Ptr const& value) { owner_->categories.EmitChanged(value); });
  }
}

void Scope::Impl::Activate(std::string const& uri, guint action_type, glib::HintsMap const& hints, ActivateCallback const& callback, GCancellable* cancellable)
{
  proxy_->Activate(uri,
                   action_type,
                   hints,
                   [this, callback] (std::string const& uri, ScopeHandledType handled_type, glib::HintsMap const& hints, glib::Error const& error) {
      if (callback)
        callback(uri, handled_type, error);
      OnActivateReply(uri, handled_type, hints, error);
    },
    cancellable);
}


void Scope::Impl::OnActivateReply(std::string const& uri, ScopeHandledType handled, glib::HintsMap const& hints, glib::Error const& error)
{
  if (static_cast<UnityProtocolHandledType>(handled) == UNITY_PROTOCOL_HANDLED_TYPE_SHOW_PREVIEW)
  {
    auto iter = hints.find("preview");
    if (iter != hints.end())
    {
      glib::Variant v = iter->second;

      Preview::Ptr preview(Preview::PreviewForVariant(v));
      if (preview)
      {
        // would be nice to make parent_scope_ a shared_ptr,
        // but that's not really doable from here
        preview->parent_scope = owner_;
        preview->preview_uri = uri;
        owner_->preview_ready.emit(uri, preview);
        return;
      }
    }

    LOG_WARNING(logger) << "Unable to deserialize Preview";
  }
  else
  {
    owner_->activated.emit(uri, handled, hints);
  }
}

Scope::Scope(std::string const& scope_id)
: pimpl(new Impl(this, scope_id))
{
}

Scope::~Scope()
{
}

void Scope::Init()
{
  pimpl->Init();
}

void Scope::Connect()
{
  if (pimpl->proxy_->connected())
    return;
  
  pimpl->proxy_->CreateProxy();
}

void Scope::Search(std::string const& search_hint, SearchCallback const& callback, GCancellable* cancellable)
{
  return pimpl->proxy_->Search(search_hint, callback, cancellable);
}

void Scope::Activate(std::string const& uri, ActivateCallback const& callback, GCancellable* cancellable)
{
  pimpl->Activate(uri, UNITY_PROTOCOL_ACTION_TYPE_ACTIVATE_RESULT, glib::HintsMap(), callback, cancellable);
}

void Scope::Preview(std::string const& uri, ActivateCallback const& callback, GCancellable* cancellable)
{
  pimpl->Activate(uri, UNITY_PROTOCOL_ACTION_TYPE_PREVIEW_RESULT, glib::HintsMap(), callback, cancellable);
}

void Scope::ActivatePreviewAction(std::string const& action_id,
                                   std::string const& uri,
                                   glib::HintsMap const& hints,
                                   ActivateCallback const& callback,
                                   GCancellable* cancellable)
{
  std::string activation_uri(action_id);
  activation_uri += ":";
  activation_uri += uri;

  pimpl->Activate(activation_uri, UNITY_PROTOCOL_ACTION_TYPE_PREVIEW_ACTION, hints, callback, cancellable);
}

void Scope::UpdatePreviewProperty(std::string const& uri, glib::HintsMap const& hints, UpdatePreviewPropertyCallback const& callback, GCancellable* cancellable)
{
  pimpl->proxy_->UpdatePreviewProperty(uri, glib::HintsMap(), callback, cancellable);
}

Results::Ptr Scope::GetResultsForCategory(unsigned category) const
{
  return pimpl->proxy_->GetResultsForCategory(category);
}

ScopeProxyInterface::Ptr Scope::CreateProxyInterface() const
{
  return ScopeProxyInterface::Ptr(new ScopeProxy(pimpl->scope_id_));
}


} // namespace dash
} // namespace unity
