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
#include <QMap>
#include <QDebug>
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
    MediaType format(const QList< Preference<MediaType> >& mediaTypes) const {
        // Step 1: map quality to MediaType.
        QMap<float, MediaType> map;
        foreach (const Preference<MediaType>& mediaType, mediaTypes) {
            map.insertMulti(mediaType.quality(), mediaType.data());
            qDebug() << Q_FUNC_INFO << ": got media type:" << mediaType.data().toString() << mediaType.quality();
        }
        qDebug() << Q_FUNC_INFO << map.size() << ": media types.";
        // Step 2: walk down until we find a usable type. QMap goes in descending order.
        for (QMap<float, MediaType>::iterator i = map.begin(); i != map.end(); ++i) {
            qDebug() << Q_FUNC_INFO << ": checking if" << i->toString() << "is supported.";
            if (hasFormat(i->toString())) {
                qDebug() << Q_FUNC_INFO << ": it is.";
                return *i;
            }
            qDebug() << Q_FUNC_INFO << ": it isn't.";
        }
        return "*/*";
    }
    QByteArray data(const MediaType& mediaType) const
        { return QMimeData::data(mediaType.toString()); }
    bool hasFormat(const MediaType& mediaType) const
        { return QMimeData::hasFormat(mediaType.toString()); }
};

}
}

#endif /* NANOGEAR_RESOURCE_REPRESENTATION_H */
