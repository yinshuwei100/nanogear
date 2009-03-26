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

#ifndef NANOGEAR_PREFERENCE_H
#define NANOGEAR_PREFERENCE_H

#include <QMap>

namespace Nanogear {

/*!
 * \class Preference
 * \brief Encapsulates client preferences
 *
 * Encapsulates a generic preference
 */
template <typename T> class Preference {
public:
    Preference(const T& data = T(), float quality = 1)
        : m_data(data), m_quality(quality) {}

    const T& data() const
        { return m_data; }
    void setData(const T& data)
        { m_data = data; }

    float quality() const
        { return m_quality; }
    void setQuality(float quality)
        { m_quality = quality; }

    class List : public QList<Preference> {
    public:
        List() {};
        List(const QList<Preference>& other)
            : QList<Preference>(other) {}
        T top() const
            { return *(toMap().end()); }
        T outOf(const QList<T>& server) const {
            QMap<float, T> map = toMap();
            for (typename QMap<float, T>::iterator i = map.end(); i != map.begin();) {
                --i;
                if (server.contains(*i))
                    return *i;
            }
            return T();
        }
        QMap<float, T> toMap() const {
            QMap<float, T> ret;
            foreach (const Preference& type, *this) {
                ret.insertMulti(type.quality(), type.data());
            }
            return ret;
        }
    };
private:
    T m_data;
    float m_quality;
};

template <typename T>
class PreferenceList : public Preference<T>::List {
public:
    PreferenceList() {};
    PreferenceList(const QList< Preference<T> >& list)
        : Preference<T>::List(list) {};
};

template <typename T, typename U>
bool operator==(const Preference<T>& a, const Preference<U>& b) {
    return a.data() == b.data();
}

template <typename T, typename U>
bool operator==(const Preference<T>& a, const U& b) {
    return a.data() == b;
}

}

#endif // NANOGEAR_PREFERENCE_H
