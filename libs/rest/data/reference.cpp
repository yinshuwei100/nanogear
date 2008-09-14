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



#include "reference.hpp"

namespace nanogear {
namespace rest {
namespace data {

reference::reference(const reference& base_ref, const std::string& uri_ref)
{
    m_base_ref = base_ref;
    m_internal_ref = uri_ref;
}

reference::reference(const reference& base_ref, const std::string& relative_part,
        const std::string& query, const std::string fragment)
{
    // Create the required string and pass it to the other constructor
    reference(base_ref, std::string(relative_part).append('?').append(query)
            .append('#').append(fragment));
}

reference::reference(const std::string scheme, const std::string& host_name,
        int host_port, const std::string& path,
        const std::string& query, const std::string& fragment)
{

}

}
}
}
