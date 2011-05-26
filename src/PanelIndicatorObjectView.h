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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef PANEL_INDICATOR_OBJECT_VIEW_H
#define PANEL_INDICATOR_OBJECT_VIEW_H

#include <Nux/View.h>

#include "Indicator.h"
#include "IndicatorEntry.h"
#include "PanelIndicatorObjectEntryView.h"

#include "Introspectable.h"

#define MINIMUM_INDICATOR_WIDTH 12

namespace unity {

class PanelIndicatorObjectView : public nux::View, public Introspectable
{
public:
  PanelIndicatorObjectView();
  PanelIndicatorObjectView(indicator::Indicator::Ptr const& proxy);
  ~PanelIndicatorObjectView();

  virtual long ProcessEvent (nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo);
  virtual void Draw (nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw);

  virtual void OnEntryAdded(indicator::Entry::Ptr const& proxy);

protected:
  const gchar * GetName ();
  const gchar * GetChildsName ();
  void          AddProperties (GVariantBuilder *builder);

  nux::HLayout* layout_;
  indicator::Indicator::Ptr proxy_;
  std::vector<PanelIndicatorObjectEntryView *> entries_;

  sigc::connection on_entry_added_connection_;
};

}

#endif // PANEL_INDICATOR_OBJECT_VIEW_H
