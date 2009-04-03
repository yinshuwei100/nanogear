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
#include "../MimeType.h"
#include "../PreferenceList.h"

namespace Nanogear {
namespace Resource {

/*!
 * \class Representation
 * \brief A resource's representation
 *
 * "A representation is a sequence of bytes, plus representation metadata to
 * describe those bytes."
 *
 * \see Roy Fielding's dissertation at:
 *     http://roy.gbiv.com/pubs/dissertation/rest_arch_style.htm#sec_5_2_1_2
 */
class Representation : public QMimeData {
public:
    Representation() {}

    template <typename Data, typename Type>
    Representation(const Data& data, const Type& mimeType = "text/plain")
        { setData(mimeType, data); }

    /*!
     * \return the data (in raw form) attached to this representation
     */
    QByteArray data(const PreferenceList<MimeType>& mimeTypes) const
        { return data(format(mimeTypes)); }

    /*!
     * \return the best matching MIME type out of the MIME types supported by
     *    the client
     */
    MimeType format(const PreferenceList<MimeType>& mimeTypes) const
        { return mimeTypes.outOf(mimeTypeFormats()); }

    /*!
     * \return the data (in raw form) attached to this representation
     */
    QByteArray data(const MimeType& mimeType) const
        { return QMimeData::data(mimeType.toString()); }

    /*!
     * \return true if the requested format is available
     */
    bool hasFormat(const MimeType& mimeType) const
        { return QMimeData::hasFormat(mimeType.toString()); }

    /*!
     * A facility to easily add Xhtml content to this representation
     * \param xhtml A string representing the XHTML document
     */
    void setXhtml(const QString& xhtml);

    /*!
     * \return true if this representation is holding an XHTML document
     */
    bool hasXhtml() const
        { return hasFormat("application/xhtml+xml"); }

    /*!
     * \return the XHTML document attached to this representation
     */
    QString xhtml() const
        { return data("application/xhtml+xml"); }

    /*!
     * \return true if this representation is holding an XHTML document
     */
    bool hasXhtml() const
        { return hasFormat("application/xhtml+xml"); }

    /*!
     * \return the list of formats this representation can give back to the
     *    clients as MIME types.
     */
    QList<MimeType> mimeTypeFormats() const;
};

}
}

#endif /* NANOGEAR_RESOURCE_REPRESENTATION_H */
