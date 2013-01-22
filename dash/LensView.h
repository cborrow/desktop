// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010, 2011 Canonical Ltd
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

#ifndef UNITY_LENS_VIEW_H_
#define UNITY_LENS_VIEW_H_

#include <string>

#include <NuxGraphics/GraphicsEngine.h>
#include <Nux/Nux.h>
#include <Nux/HLayout.h>
#include <Nux/View.h>
#include <Nux/VLayout.h>
#include <UnityCore/Scope.h>
#include <UnityCore/GLibSource.h>

#include "FilterBar.h"
#include "unity-shared/Introspectable.h"
#include "PlacesGroup.h"
#include "ResultViewGrid.h"
#include "unity-shared/UBusWrapper.h"
#include "unity-shared/PlacesVScrollBar.h"

namespace unity
{
namespace dash
{

class ScopeScrollView;

class ScopeView : public nux::View, public unity::debug::Introspectable
{
  NUX_DECLARE_OBJECT_TYPE(ScopeView, nux::View);
  typedef std::vector<PlacesGroup*> CategoryGroups;
  typedef std::map<PlacesGroup*, unsigned int> ResultCounts;

public:
  ScopeView(Scope::Ptr scope, nux::Area* show_filters);
  ~ScopeView();

  CategoryGroups& categories() { return categories_; }
  FilterBar* filter_bar() const { return filter_bar_; }
  Scope::Ptr scope() const;
  nux::Area* fscroll_view() const;

  int GetNumRows();
  void AboutToShow();
  void JumpToTop();

  virtual void ActivateFirst();

  nux::ROProperty<std::string> search_string;
  nux::Property<bool> filters_expanded;
  nux::Property<ScopeViewType> view_type;
  nux::Property<bool> can_refine_search;

  sigc::signal<void, ResultView::ActivateType, std::string const&, GVariant*, std::string const&> uri_activated;

  void PerformSearch(std::string const& search_query, Scope::SearchCallback const& cb);
  void CheckNoResults(glib::HintsMap const& hints);
  void CheckCategoryExpansion();
  void HideResultsMessage();

  void ForceCategoryExpansion(std::string const& view_id, bool expand);
  void PushFilterExpansion(bool expand);
  void PopFilterExpansion();
  bool GetPushedFilterExpansion() const;

  void SetResultsPreviewAnimationValue(float preview_animation);

  void EnableResultTextures(bool enable_result_textures);
  std::vector<ResultViewTexture::Ptr> GetResultTextureContainers();
  void RenderResultTexture(ResultViewTexture::Ptr const& result_texture);

private:
  void SetupViews(nux::Area* show_filters);
  void SetupCategories();
  void SetupResults();
  void SetupFilters();

  void OnCategoryAdded(Category const& category);
  void OnCategoryRemoved(Category const& category);

  void OnResultAdded(Result const& result);
  void OnResultRemoved(Result const& result);
  
  void UpdateCounts(PlacesGroup* group);
  void OnGroupExpanded(PlacesGroup* group);
  void CheckScrollBarState();
  void OnColumnsChanged();
  void OnFilterAdded(Filter::Ptr filter);
  void OnFilterRemoved(Filter::Ptr filter);
  void OnViewTypeChanged(ScopeViewType view_type);
  void OnScopeFilterExpanded(bool expanded);
  bool ReinitializeFilterModels();
  void ClearCategories();
  ResultViewGrid* GetGridForCategory(unsigned category_index);
  ResultView* GetResultViewForCategory(unsigned category_index);

  virtual PlacesGroup* CreatePlacesGroup();

  void BuildPreview(std::string const& uri, Preview::Ptr model);

  virtual void Draw(nux::GraphicsEngine& gfx_context, bool force_draw);
  virtual void DrawContent(nux::GraphicsEngine& gfx_context, bool force_draw);
  
  virtual bool AcceptKeyNavFocus();
  virtual std::string GetName() const;
  virtual void AddProperties(GVariantBuilder* builder);

  std::string get_search_string() const;

  Scope::Ptr scope_;
  glib::Object<GCancellable> cancellable_;
  CategoryGroups categories_;
  ResultCounts counts_;
  bool initial_activation_;
  bool no_results_active_;
  std::string search_string_;
  PlacesGroup* last_expanded_group_;

  nux::HLayout* layout_;
  ScopeScrollView* scroll_view_;
  nux::VLayout* scroll_layout_;
  ScopeScrollView* fscroll_view_;
  nux::VLayout* fscroll_layout_;
  FilterBar* filter_bar_;
  StaticCairoText* no_results_;

  UBusManager ubus_manager_;
  glib::Source::UniquePtr model_updated_timeout_;
  int last_good_filter_model_;
  glib::Source::UniquePtr fix_filter_models_idle_;

  bool filter_expansion_pushed_;
  sigc::connection result_added_connection;
  sigc::connection result_removed_connection;
  sigc::connection category_added_connection;
  sigc::connection category_removed_connection;
  sigc::connection filter_added_connection;
  sigc::connection filter_removed_connection;

  friend class TestScopeView;
};


}
}
#endif
