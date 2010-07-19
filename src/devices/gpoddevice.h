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

#ifndef GPODDEVICE_H
#define GPODDEVICE_H

#include "connecteddevice.h"
#include "core/musicstorage.h"

class GPodLoader;

class GPodDevice : public ConnectedDevice, public MusicStorage {
  Q_OBJECT

public:
  Q_INVOKABLE GPodDevice(
      const QUrl& url, DeviceLister* lister,
      const QString& unique_id, DeviceManager* manager,
      int database_id, bool first_time);
  ~GPodDevice();

  static QStringList url_schemes() { return QStringList() << "ipod"; }

  MusicStorage* storage() { return this; }

  bool CopyToStorage(const QString &source, const QString &destination,
                     const Song &metadata, bool overwrite, bool remove_original);

private:
  QThread* loader_thread_;
  GPodLoader* loader_;
};

#endif // GPODDEVICE_H
