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

#ifndef NANOGEAR_REST_DATA_CHALLENGE_REQUEST_HPP
#define NANOGEAR_REST_DATA_CHALLENGE_REQUEST_HPP

#include "challenge_scheme.hpp"

#include <string>
#include <list>

namespace nanogear {
namespace rest {
namespace data {

// forward-declare challenge_scheme
class challenge_scheme;

class challenge_request {
public:
    challenge_request(const challenge_scheme&, const std::string&);
    virtual ~challenge_request() {};

    bool operator==(const challenge_request&) const;
    bool operator!=(const challenge_request&) const;
                        
//    std::list<parameter>& parameters() const; // TODO
//    void set_parameters(const std::list<parameter>&);
    
    const std::string& realm() const;
    void set_realm(const std::string&);
    
    const challenge_scheme scheme() const;
    void set_scheme(const challenge_scheme&);
    
protected:
private:
    challenge_scheme m_scheme;
    std::string m_realm;
//    std::list<parameter> m_parameters;
};


}
}
}

#endif /* NANOGEAR_REST_DATA_CHALLENGE_REQUEST_HPP */
