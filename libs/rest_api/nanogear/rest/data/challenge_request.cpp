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


#include <list>
#include <string>

#include "parameter.hpp"

#include "challenge_request.hpp"

namespace nanogear {
namespace rest {
namespace data {

challenge_request::challenge_request(const challenge_scheme& scheme,
                                     const std::string& realm)
{
    m_scheme = scheme;
    m_realm = realm;
}

bool challenge_request::operator==(const challenge_request& other) const
{
    bool ret = false;
    ret = (parameters() == other.parameters());
    ret = (realm() == other.realm());
    ret = (scheme() == other.scheme());
    return ret;
}

bool challenge_request::operator!=(const challenge_request& other) const
{
    return !(*this == other);
}

const std::list<parameter>& challenge_request::parameters() const
{
    return m_parameters;
}
void challenge_request::set_parameters(const std::list<parameter>& parameters)
{
    m_parameters = parameters;
}

const std::string& challenge_request::realm() const
{
    return m_realm;
}
void challenge_request::set_realm(const std::string& realm)
{
    m_realm = realm;
}

const challenge_scheme& challenge_request::scheme() const
{
    return m_scheme;
}
void challenge_request::set_scheme(const challenge_scheme& scheme)
{
    m_scheme = scheme;
}


}
}
}
