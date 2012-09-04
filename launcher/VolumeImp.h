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
 * Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
 */

#ifndef UNITYSHELL_VOLUME_IMP_H
#define UNITYSHELL_VOLUME_IMP_H

#include <memory>

#include <UnityCore/GLibWrapper.h>

#include "DeviceNotificationDisplay.h"
#include "FileManagerOpener.h"
#include "Volume.h"

namespace unity
{
namespace launcher
{

class VolumeImp : public Volume
{
public:
  typedef std::shared_ptr<VolumeImp> Ptr;

  VolumeImp(glib::Object<GVolume> const& volume,
            FileManagerOpener::Ptr const& file_manager_opener,
            DeviceNotificationDisplay::Ptr const& device_notification_display);
  virtual ~VolumeImp();

  virtual bool CanBeEjected() const;
  virtual bool CanBeRemoved() const;
  virtual bool CanBeStopped() const;
  virtual std::string GetName() const;
  virtual std::string GetIconName() const;
  virtual std::string GetIdentifier() const;
  virtual bool HasSiblings() const;
  virtual bool IsMounted() const;

  virtual void EjectAndShowNotification();
  virtual void MountAndOpenInFileManager();
  virtual void StopDrive();
  virtual void Unmount();

private:
  class Impl;
  std::unique_ptr<Impl> pimpl;
};

}
}

#endif