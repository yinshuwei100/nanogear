/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008 Lorenzo Villani.
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

#ifndef NANOGEAR_REST_DATA_PREFERENCE_HPP
#define NANOGEAR_REST_DATA_PREFERENCE_HPP

#include <string>
#include <list>

#include "metadata.hpp"
#include "parameter.hpp"

namespace nanogear {
namespace rest {
namespace data {

template <typename T>
class preference {
public:
    inline preference(const T& m = T(), const float q = 1,
               const std::list<parameter>& p = std::list<parameter>())
               : m_metadata(m), m_quality(q), m_parameters(p) {}
    inline const T& get_metadata() { return m_metadata; }
    inline const std::list<parameter>& get_parameters() { return m_parameters; }
    inline const float get_quality() { return m_quality; }

private:
    T m_metadata;
    std::list<parameter> m_parameters;
    float m_quality;
};


}
}
}

#endif /* NANOGEAR_REST_DATA_PARAMETER_HPP */

