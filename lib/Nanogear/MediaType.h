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

#ifndef NANOGEAR_MEDIATYPE_H
#define NANOGEAR_MEDIATYPE_H

#include <QString>
#include "Preference.h"

namespace Nanogear {

class MediaType {
public:
    MediaType() : m_whole("*/*") {};
    MediaType(const QString& type) : m_whole(type) {};
    MediaType(const char* type) : m_whole(type) {};
    void fromString(const QString& type)
        { m_whole = type; m_category = m_specific = ""; }
    const QString& toString() const
        { return m_whole; }
    bool operator==(const MediaType& type)
        { return m_whole == type.m_whole; }
    bool isConcrete() const
        { return !m_whole.contains("*"); }
    const QString& category() const;
    const QString& specific() const;
    bool isCompatible(const MediaType&) const;
private:
    QString m_whole;
    QString m_category;
    QString m_specific;
};

}

#endif // NANOGEAR_MEDIATYPE_H
