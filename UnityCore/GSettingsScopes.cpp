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
 */


#include "GSettingsScopes.h"

#include "Scope.h"

namespace unity
{
namespace dash
{

namespace
{
const std::string SETTINGS_NAME = "com.canonical.Unity.Dash";
const std::string SCOPE_SETTINGS_KEY = "scopes";
const std::string ALWAYS_SEARCH_SETTINGS_KEY = "always-search";
}

class GSettingsScopesReader::Impl
{
public:
  Impl(GSettingsScopesReader* owner);
  ~Impl() {}

  void LoadScopes();

  GSettingsScopesReader* owner_;
  bool loaded_;

  glib::Object<GSettings> settings_;
  glib::Signal<void, GSettings*, gchar*> scopes_changed;
  glib::Signal<void, GSettings*, gchar*> always_search_changed;

  std::vector<std::string> get_string_vector(std::string const& setting)
  {
    std::vector<std::string> vector;

    std::unique_ptr<gchar*[], void(*)(gchar**)> strings(g_settings_get_strv(settings_, setting.c_str()), g_strfreev);

    for (int i = 0; strings[i]; ++i)
    { 
      std::string value = strings[i];

      if (!value.empty())
        vector.push_back(value);
    }
    return vector;
  }

  ScopeDataList scopes_order_;
};


GSettingsScopesReader::Impl::Impl(GSettingsScopesReader* owner)
: owner_(owner)
, loaded_(false)
, settings_(g_settings_new(SETTINGS_NAME.c_str()))
{
  auto change_func = [&] (GSettings*, gchar*)
  {
    if (loaded_)
    {
      LoadScopes();
      owner_->scopes_changed.emit(scopes_order_);
    }    
  };

  scopes_changed.Connect(settings_, "changed::"+SCOPE_SETTINGS_KEY, change_func);
  always_search_changed.Connect(settings_, "changed::"+ALWAYS_SEARCH_SETTINGS_KEY, change_func);
}


void GSettingsScopesReader::Impl::LoadScopes()
{
  std::vector<std::string> tmp_scope_ids = get_string_vector(SCOPE_SETTINGS_KEY);
  std::vector<std::string> always_search = get_string_vector(ALWAYS_SEARCH_SETTINGS_KEY);

  ScopeDataList old_scopes_order = scopes_order_;
  scopes_order_.clear();

  // insert new
  for (std::string const& scope_id : tmp_scope_ids)
  {
    auto match_scope_data_to_id = [scope_id](ScopeData::C_Ptr const& scope_data) { return scope_data->id() == scope_id; };

    ScopeData::C_Ptr scope;
    auto scope_position = std::find_if(old_scopes_order.begin(), old_scopes_order.end(), match_scope_data_to_id);
    if (scope_position == old_scopes_order.end())
    {
      scope = ScopeData::ReadProtocolDataForId(scope_id);
    }
    else
    {
      scope = *scope_position;
    }

    if (scope)
    {
      scope->always_search = std::find(always_search.begin(), always_search.end(), scope_id) != always_search.end();
      scopes_order_.push_back(scope);
    }
  }
  loaded_ = true;
}


GSettingsScopesReader::GSettingsScopesReader()
: pimpl(new Impl(this))
{
}

void GSettingsScopesReader::LoadScopes()
{
  pimpl->LoadScopes();  
}

ScopeDataList const& GSettingsScopesReader::GetScopesData() const
{
  if (!pimpl->loaded_)
    pimpl->LoadScopes();
  return pimpl->scopes_order_;  
}

GSettingsScopesReader::Ptr GSettingsScopesReader::GetDefault()
{
  static GSettingsScopesReader::Ptr main_reader(new GSettingsScopesReader());

  return main_reader;
}

GSettingsScopes::GSettingsScopes()
: Scopes(GSettingsScopesReader::GetDefault())
{

}

} // namespace dash
} // namespace unity