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

#ifndef NANOGEAR_REST_DATA_CHALLENGE_RESPONSE_HPP
#define NANOGEAR_REST_DATA_CHALLENGE_RESPONSE_HPP

#include <list>
#include <string>
#include "parameter.hpp"
#include "challenge_scheme.hpp"

namespace nanogear {
namespace rest {
namespace data {

class challenge_response {
public:
    challenge_response(const challenge_scheme& scheme,
                       const std::string& credentials) : m_scheme(scheme),
                       m_credentials(credentials) {}
                       
    challenge_response(const challenge_scheme& scheme,
                       const std::string& identifier,
                       const std::string& secret) : m_scheme(scheme),
                       m_identifier(identifier), m_secret(secret) {}

    challenge_response(const challenge_scheme& scheme,
                       const std::string& identifier,
                       const std::list<parameter> parameters) : m_scheme(scheme),
                       m_identifier(identifier), m_parameters(parameters) {}

    virtual ~challenge_response() {};

    bool operator==(const challenge_response&) const;
    bool operator!=(const challenge_response&) const;

    const challenge_scheme& scheme() const;
    void set_scheme(const challenge_scheme&);

    const std::string& identifier() const;
    void set_identifier(const std::string&);

    const std::string& secret() const;
    void set_secret(const std::string&);

    const std::string& credentials() const;
    void set_credentials(const std::string&);

    std::list<parameter>& parameters();
    void set_credential_components(const std::list<parameter>&);

    bool authenticated();
    void set_authenticated(bool);
private:
    bool m_authenticated;
    std::list<parameter> m_parameters;
    challenge_scheme m_scheme;
    std::string m_credentials;
    std::string m_identifier;
    std::string m_secret;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_CHALLENGE_RESPONSE_HPP */
