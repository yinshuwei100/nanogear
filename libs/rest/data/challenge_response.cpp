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

#include <string>

#include "challenge_scheme.hpp"
#include "challenge_response.hpp"

namespace nanogear {
namespace rest {
namespace data {

challenge_response::challenge_response(const challenge_scheme& scheme,
                                       const std::string& credentials)
{
    m_scheme = scheme;
    m_credentials = credentials;
}

challenge_response::challenge_response(const challenge_scheme& scheme,
                                       const std::string& identifier,
                                       const std::string& secret)
{
    challenge_response(scheme, identifier);
    m_secret = secret;
}

bool challenge_response::operator==(const challenge_response& other) const
{
    bool result = false;
    result = (scheme() == other.scheme());
    result = (identifier() == other.identifier());
    result = (secret() == other.secret());
    result = (credentials() == other.credentials());
}

bool challenge_response::operator!=(const challenge_response& other) const
{
    return !(*this == other);
}




const challenge_scheme& challenge_response::scheme() const
{
    return m_scheme;
}
void challenge_response::set_scheme(const challenge_scheme& scheme)
{
    m_scheme = scheme;
}

const std::string& challenge_response::identifier() const
{
    return m_identifier;
}
void challenge_response::set_identifier(const std::string& identifier)
{
    m_identifier = identifier;
}

const std::string& challenge_response::secret() const
{
    return m_secret;
}
void challenge_response::set_secret(const std::string& secret)
{
    m_secret = secret;
}

const std::string& challenge_response::credentials() const
{
    return m_credentials;
}
void challenge_response::set_credentials(const std::string& credentials)
{
    m_credentials = credentials;
}

}
}
}
