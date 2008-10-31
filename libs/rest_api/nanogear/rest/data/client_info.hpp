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

#ifndef NANOGEAR_REST_DATA_CLIENT_INFO_HPP
#define NANOGEAR_REST_DATA_CLIENT_INFO_HPP

#include <list>
#include <string>

#include "preference.hpp"
#include "encoding.hpp"
#include "language.hpp"
#include "media_type.hpp"

namespace nanogear {
namespace rest {
namespace data {

class client_info
{
public:
    client_info();
    virtual ~client_info() {};

    const std::list< preference<character_set> >& accepted_character_sets() const;
    const std::list< preference<encoding> >& accepted_encodings() const;
    const std::list< preference<language> >& accepted_languages() const;
    const std::list< preference<media_type> >& accepted_media_types() const;
//    const variant& preferred_variant(const std::list<variant>&, const language) const;

    const std::string& address() const;
    void set_address(const std::string&);

    const std::string& agent() const;
    void set_agent(const std::string&);

    const int port() const;
    void set_port(int);
    
private:
    std::list<std::string> m_addresses;
    std::string m_agent;
    int m_port;
    std::list< preference<encoding> > m_encoding_prefs;
    std::list< preference<language> > m_language_prefs;
    std::list< preference<media_type> > m_mediatype_prefs;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_CLIENT_INFO_HPP */
