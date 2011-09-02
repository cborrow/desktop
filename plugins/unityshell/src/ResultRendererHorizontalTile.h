// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
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



#ifndef RESULTRENDERERHORIZONTALTILE_H
#define RESULTRENDERERHORIZONTALTILE_H

#include <Nux/Nux.h>
#include <NuxCore/Object.h>
#include <NuxCore/Property.h>
#include "Nux/TextureArea.h"
#include "NuxImage/CairoGraphics.h"

#include "ResultRendererTile.h"

namespace unity
{
namespace dash
{

// Initially unowned object
class ResultRendererHorizontalTile : public ResultRendererTile
{
public:
  NUX_DECLARE_OBJECT_TYPE(ResultRendererHorizontalTile, ResultRendererTile);

  ResultRendererHorizontalTile(NUX_FILE_LINE_PROTO);
  ~ResultRendererHorizontalTile();

  virtual void Render(nux::GraphicsEngine& GfxContext,
                      Result& row,
                      ResultRendererState state,
                      nux::Geometry& geometry,
                      int x_offset, int y_offset);

protected:
  void LoadText(Result& row);

private:
  nux::BaseTexture* DrawHighlight(std::string const& texid, int width, int height);
};

}
}
#endif // RESULTRENDERERHORIZONTALTILE_H
