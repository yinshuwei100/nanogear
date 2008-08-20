/*
 * This file is part of the nanogear project
 *
 * (C) Copyright 2008 by Lorenzo Villani <lvillani@binaryhelix.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation;
 * version 3 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
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