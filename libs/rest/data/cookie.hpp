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

#ifndef NANOGEAR_REST_DATA_COOKIE_HPP
#define NANOGEAR_REST_DATA_COOKIE_HPP

#include <string>

#include "parameter.hpp"

namespace nanogear {
namespace rest {
namespace data {

class cookie
{
public:
    cookie();
    cookie(const std::string&, const std::string&);
    cookie(int, const std::string&, const std::string&);
    cookie(int, const std::string&, const std::string&, const std::string&
           const std::string&);
    virtual ~cookie() {}
    
    bool operator==(const cookie&) const;
    bool operator!=(const cookie&) const;

    const std::string& name() const;
    void set_name(const std::string&);

    const std::string& value() const;
    void set_value(const std::string&);

    const std::string& path() const;
    void set_path(const std::string&);

    const std::string& domain() const;
    void set_domain(const std::string&);

private:
    int m_version;
    std::string m_name;
    std::string m_value;
    std::string m_path;
    std::string m_domain;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_COOKIE_HPP */
