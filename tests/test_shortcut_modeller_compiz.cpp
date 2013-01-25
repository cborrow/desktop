/*
 * Copyright 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Marco Trevisan <marco.trevisan@canonical.com>
 */

#include "config.h"
#include <gmock/gmock.h>
#include <glib/gi18n-lib.h>
using namespace testing;

#include "CompizShortcutModeller.h"
#include "StandaloneWindowManager.h"
using namespace unity;
using namespace unity::shortcut;

namespace
{

struct TestShortcutCompizModeller : Test
{
  TestShortcutCompizModeller()
    : WM(dynamic_cast<StandaloneWindowManager*>(&WindowManager::Default()))
    , modeller(std::make_shared<CompizModeller>())
  {
    WM->SetViewportSize(2, 2);
  }

  void AssertHasWorkspaces()
  {
    auto const& cats = modeller->GetCurrentModel()->categories();
    auto it = cats.begin();
    ASSERT_EQ(it, std::find(cats.begin(), cats.end(), _("Launcher")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Dash")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("HUD & Menu Bar")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Switching")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Workspaces")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Windows")));
    ASSERT_EQ(std::next(it), cats.end());
  }

  void AssertHasNoWorkspaces()
  {
    auto const& cats = modeller->GetCurrentModel()->categories();
    auto it = cats.begin();
    ASSERT_EQ(it, std::find(cats.begin(), cats.end(), _("Launcher")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("HUD & Menu Bar")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Switching")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Dash")));
    ASSERT_EQ(it = std::next(it), std::find(cats.begin(), cats.end(), _("Windows")));
    ASSERT_EQ(std::next(it), cats.end());
    ASSERT_EQ(std::find(cats.begin(), cats.end(), "Workspaces"), cats.end());
  }

  StandaloneWindowManager* WM;
  AbstractModeller::Ptr modeller;
};

TEST_F(TestShortcutCompizModeller, Construction)
{
  EXPECT_NE(modeller->GetCurrentModel(), nullptr);
}

TEST_F(TestShortcutCompizModeller, ConstructionWithWSEnabled)
{
  AssertHasWorkspaces();
}

TEST_F(TestShortcutCompizModeller, ConstructionWithWSDisabled)
{
  WM->SetViewportSize(1, 1);
  modeller = std::make_shared<CompizModeller>();
  AssertHasNoWorkspaces();
}

TEST_F(TestShortcutCompizModeller, WorkspacesEnabled)
{
  AssertHasWorkspaces();
  bool changed = false;
  modeller->model_changed.connect([&changed](Model::Ptr const&) {changed = true;});

  WM->SetViewportSize(1, 1);
  AssertHasNoWorkspaces();
  EXPECT_TRUE(changed);
}

TEST_F(TestShortcutCompizModeller, WorkspacesDisabled)
{
  WM->SetViewportSize(1, 1);
  modeller = std::make_shared<CompizModeller>();
  AssertHasNoWorkspaces();

  bool changed = false;
  modeller->model_changed.connect([&changed](Model::Ptr const&) {changed = true;});

  WM->SetViewportSize(2, 2);
  AssertHasWorkspaces();
  EXPECT_TRUE(changed);
}

}
