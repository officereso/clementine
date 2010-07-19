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

#ifndef FILESYSTEMMUSICSTORAGE_H
#define FILESYSTEMMUSICSTORAGE_H

#include "musicstorage.h"

class FilesystemMusicStorage : public MusicStorage {
public:
  FilesystemMusicStorage(const QString& root);

  QString LocalPath() const { return root_; }

  bool CopyToStorage(const QString &source, const QString &destination,
                     const Song &metadata, bool overwrite, bool remove_original);

private:
  QString root_;
};

#endif // FILESYSTEMMUSICSTORAGE_H
