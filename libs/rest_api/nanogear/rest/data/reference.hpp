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



#ifndef NANOGEAR_REST_DATA_REFERENCE_HPP
#define NANOGEAR_REST_DATA_REFERENCE_HPP

#include <list>
#include <boost/shared_ptr.hpp>

#include "character_set.hpp"
#include "protocol.hpp"

namespace nanogear {
namespace rest {
namespace data {

class reference {
public:
    //reference(const reference&); // use default copy constructor
    reference(const reference&, const std::string&);
    reference(const std::string& = std::string());
    reference(const std::string&, const std::string&);
    reference(const std::string&, const std::string&, int, const std::string&,
            const std::string&, const std::string&);
    ~reference();

    static std::string decode(const std::string&);
    static std::string decode(const std::string&, const character_set&);

    static std::string encode(const std::string&);
    static std::string encode(const std::string&, const character_set&);

    std::string authorithy();
    reference base_ref();
    std::string get_fragment();
    std::string hierarchical_part();
    std::string host_domain();
    std::string host_identifier();
    int host_port();
    std::string identifier();
    std::string last_segment();
    reference parent_reference();
    std::string path();
    std::string query();

    //data::form query_as_form();
    //data::form query_as_form(const data::character_set&);

    std::string relative_part();

    reference relative_ref();
    reference relative_ref(const reference&);

    std::string remaining_part();
    std::string scheme();
    protocol scheme_protocol();
    std::string scheme_specific_part();

    std::list<std::string> segments();

private:
    boost::shared_ptr<reference> m_base_ref;
    std::string m_internal_ref;
    int m_fragment_index;
    int m_query_index;
    int m_scheme_index;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_REFERENCE_HPP */
