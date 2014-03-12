// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2014 Canonical Ltd
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
* Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
*/

#ifndef UNITY_UPSTART_WRAPPER
#define UNITY_UPSTART_WRAPPER

#include <memory>

namespace unity
{

class UpstartWrapper
{
public:
  typedef std::shared_ptr<UpstartWrapper> Ptr;

  UpstartWrapper();
  ~UpstartWrapper();

  void Emit(std::string const& name);

protected:
  struct TestMode {};
  UpstartWrapper(TestMode const&);

private:
  // Noncopyable
  UpstartWrapper(UpstartWrapper const&) = delete;
  UpstartWrapper& operator=(UpstartWrapper const&) = delete;

  class Impl;
  std::unique_ptr<Impl> pimpl_;
};

}

#endif
