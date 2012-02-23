// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 */

#include "ResultIterator.h"
#include <NuxCore/Logger.h>
namespace unity
{
namespace dash
{

namespace 
{
  nux::logging::Logger logger("unity.dash.resultiterator");
}

ResultIterator::ResultIterator(glib::Object<DeeModel> model)
  : model_(model, glib::AddRef())
  , iter_(dee_model_get_first_iter(model))
  , iter_result_(model_, iter_, NULL)
  , cache_invalidated_(false)
{
}

ResultIterator::ResultIterator(glib::Object<DeeModel> model, DeeModelIter* iter_)
  : model_(model, glib::AddRef())
  , iter_(iter_)
  , iter_result_(model_, iter_, NULL)
  , cache_invalidated_(false)
{
}

ResultIterator& ResultIterator::operator=(ResultIterator const& rhs)
{
  model_ = rhs.model_;
  iter_ = rhs.iter_;
  iter_result_ = Result(model_, iter_, NULL);
  cache_invalidated_ = false;

  return *this;
}

ResultIterator& ResultIterator::operator++()
{
  iter_ = dee_model_next(model_, iter_);
  cache_invalidated_ = true;
  return *this;
}

ResultIterator& ResultIterator::operator+=(int count)
{
  if (dee_model_is_last(model_, iter_))
    return *this;

  for (int index = 0; index < count; index++)
    iter_ = dee_model_next(model_, iter_);
  
  cache_invalidated_ = true;
  return *this;
}

ResultIterator ResultIterator::operator++(int)
{
  ResultIterator tmp(*this);
  operator++();
  return tmp;
}

ResultIterator ResultIterator::operator+(int count) const
{
  ResultIterator tmp(*this);
  tmp += count;
  return tmp;
}

ResultIterator& ResultIterator::operator--()
{
  iter_ = dee_model_prev(model_, iter_);
  cache_invalidated_ = true;
  return *this;
}

ResultIterator& ResultIterator::operator-=(int count)
{
  if (dee_model_is_first(model_, iter_))
    return *this;

  for (int index = 0; index < count; index++)
    iter_ = dee_model_prev(model_, iter_);

  cache_invalidated_ = true;
  return *this;
}

ResultIterator ResultIterator::operator--(int)
{
  ResultIterator tmp(*this);
  operator--();
  return tmp;
}

ResultIterator ResultIterator::operator-(int count) const
{
  ResultIterator tmp(*this);
  tmp -= count;
  return tmp;
}

Result const& ResultIterator::operator*()
{
  if (cache_invalidated_)
    iter_result_ = Result(model_, iter_, NULL);
  return iter_result_;
}

bool const ResultIterator::IsLast()
{
  return (dee_model_is_last(model_, iter_));
}

bool const ResultIterator::IsFirst()
{
  return (dee_model_is_first(model_, iter_));
}

}
}
