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

#include <string>

#include "uri_template.hpp"

namespace nanogear {
namespace rest {
namespace util {


void uri_template::set_template_string(const std::string& template_string)
{
    m_template_string = template_string;
}
const std::string& uri_template::template_string() const
{
    return m_template_string;
}

std::string uri_template::expanded()
{
    
}

}
}
}