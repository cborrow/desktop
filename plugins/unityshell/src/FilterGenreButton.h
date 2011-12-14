/*
 * Copyright 2011 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */

#ifndef UNITYSHELL_FILTERGENREBUTTON_H
#define UNITYSHELL_FILTERGENREBUTTON_H

#include <Nux/Nux.h>
#include <Nux/ToggleButton.h>

#include "FilterWidget.h"
#include "FilterBasicButton.h"

namespace unity
{
namespace dash
{

class FilterGenreButton : public FilterBasicButton
{
public:
  FilterGenreButton(std::string const& label, NUX_FILE_LINE_PROTO);
  FilterGenreButton(NUX_FILE_LINE_PROTO);

  void SetFilter(dash::FilterOption::Ptr filter);
  FilterOption::Ptr GetFilter();

protected:
  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw);

private:
  FilterOption::Ptr filter_;
};

} // namespace dash
} // namespace unity

#endif // FILTERGENREBUTTON_H
