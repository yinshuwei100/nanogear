/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NANOGEAR_RESOURCE_REPRESENTATION_H
#define NANOGEAR_RESOURCE_REPRESENTATION_H

#include <QMimeData>
#include "../MediaType.h"
#include "../Preference.h"

namespace Nanogear {
namespace Resource {

class Representation : public QMimeData {
public:
    Representation() {}
    template <typename Data, typename MimeType>
    Representation(const Data& data, const MimeType& mediaType = "text/plain")
        { setData(mediaType, data); }
    QByteArray data(const QList< Preference<MediaType> >& mediaTypes) const
        { return data(format(mediaTypes)); }
    MediaType format(const QList< Preference<MediaType> >& mediaTypes) const
        { return Preference<MediaType>::outOf(mediaTypes, mediaTypeFormats()); }
    QByteArray data(const MediaType& mediaType) const
        { return QMimeData::data(mediaType.toString()); }
    bool hasFormat(const MediaType& mediaType) const
        { return QMimeData::hasFormat(mediaType.toString()); }
    void setXhtml(const QString& xhtml);
    QString xhtml() const
        { return data("application/xhtml+xml"); }
    QList<MediaType> mediaTypeFormats() const;
};

}
}

#endif /* NANOGEAR_RESOURCE_REPRESENTATION_H */
