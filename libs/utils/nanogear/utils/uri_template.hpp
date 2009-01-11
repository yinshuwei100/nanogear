/*
 * Nanogear - C++ web development framework
 * Class to parse URI templates as specified at
 *   http://bitworking.org/projects/URI-Templates/
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

#ifndef NANOGEAR_REST_UTIL_URI_TEMPLATE_HPP
#define NANOGEAR_REST_UTIL_URI_TEMPLATE_HPP

#include <map>
#include <string>

#include <boost/regex.hpp>

namespace nanogear {
namespace rest {
namespace util {

/*!
 * \see http://bitworking.org/projects/URI-Templates/
 */
class uri_template {
public:
    uri_template(const std::string& template_string) :
        m_template_string(template_string) {};
    virtual ~uri_template() {}

    std::string& operator[](const std::string&);

    const std::string& template_string() const;
    void set_template_string(const std::string&);
    
    std::string expanded();
private:
    std::string m_template_string;
    std::map<std::string, std::string> m_vars;
};

}
}
}

#endif