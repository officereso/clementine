/* This file is part of Clementine.

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FILESYSTEMDEVICE_H
#define FILESYSTEMDEVICE_H

#include "connecteddevice.h"
#include "core/backgroundthread.h"
#include "core/filesystemmusicstorage.h"

class DeviceManager;
class LibraryWatcher;

class FilesystemDevice : public ConnectedDevice, public FilesystemMusicStorage {
  Q_OBJECT

public:
  Q_INVOKABLE FilesystemDevice(
      const QUrl& url, DeviceLister* lister,
      const QString& unique_id, DeviceManager* manager,
      int database_id, bool first_time);
  ~FilesystemDevice();

  static QStringList url_schemes() { return QStringList() << "file"; }

  MusicStorage* storage() { return this; }

private:
  BackgroundThread<LibraryWatcher>* watcher_;
};

#endif // FILESYSTEMDEVICE_H
