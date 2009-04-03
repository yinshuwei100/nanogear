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

#ifndef NANOGEAR_MIMETYPE_H
#define NANOGEAR_MIMETYPE_H

#include <QMetaType>

class QString;

namespace Nanogear {

/*!
 * \class MimeType
 * \brief Encapsulates a MIME type
 *
 * This class represents a MIME type as described in RFC2046
 */
class MimeType {
public:
    /*!
     * A default constructor, it will build a MimeType representing all possible
     * type/subtype pairs.
     */
    MimeType();

    /*!
     * A constructor which builds the object from the string representation of
     * a MIME type
     * \param type A string representation of the MIME type
     */
    MimeType(const QString& type);

    /*!
     * An overloaded constructor provided for convenience
     * \param type A C-style string representing the MIME type
     */
    MimeType(const char* type);

    /*!
     * Build this MimeType object from its string representation
     * \param type A string representation of the MIME type
     */
    void fromString(const QString& type);

    /*!
     * \return The string representation of this MimeType object
     */
    const QString& toString() const;

    bool operator==(const MimeType& type) const;

    /*!
     * A concrete MIME type must not contain wildcards
     * \return true if this MIME type does not contain wildcards
     */
    bool isConcrete() const;

    /*!
     * This is the part before the backslash in a string representation
     * of a MIME type
     * \return the MIME type
     */
    const QString& type() const;

    /*!
     * This is the part after the backslash in a string representation of a MIME
     * type
     * \return the MIME subtype
     */
    const QString& subtype() const;

    /*!
     * Check if two MIME types are compatible
     * \return true if both MIME types are compatible each other
     */
    bool isCompatible(const MimeType&) const;
private:
    QString m_whole;
    QString m_type;
    QString m_subtype;
};

}

Q_DECLARE_METATYPE(Nanogear::MimeType)

#endif // NANOGEAR_MIMETYPE_H
