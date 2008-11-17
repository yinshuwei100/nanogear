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



#ifndef NANOGEAR_REST_DATA_METHOD_HPP
#define NANOGEAR_REST_DATA_METHOD_HPP

#include "metadata.hpp"

#include <string>

namespace nanogear {
namespace rest {
namespace data {

class method : public metadata {
public:
    method(const std::string& = std::string(), const std::string& = std::string(), const std::string& = std::string());
    const std::string& uri() const;

    static method CONNECT;
    static method COPY;
    static method DELETE;
    static method GET;
    static method HEAD;
    static method LOCK;
    static method MKCOL;
    static method MOVE;
    static method OPTIONS;
    static method POST;
    static method PROPFIND;
    static method PROPPATCH;
    static method PUT;
    static method TRACE;
    static method UNLOCK;

    static method value_of(const std::string&);
private:
    std::string m_uri;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_METADATA_HPP */
