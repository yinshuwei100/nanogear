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



#ifndef NANOGEAR_REST_DATA_METADATA_HPP
#define NANOGEAR_REST_DATA_METADATA_HPP

#include <string>

namespace nanogear {
namespace rest {
namespace data {

/**
 * Description of data contained in a resource representation. "A representation
 * consists of data, metadata describing the data, and, on occasion, metadata to
 * describe the metadata (usually for the purpose of verifying message
 * integrity). Metadata is in the form of name-value pairs, where the name
 * corresponds to a standard that defines the value's structure and semantics.
 * Response messages may include both representation metadata and resource
 * metadata: information about the resource that is not specific to the supplied
 * representation." Roy T. Fielding
 *
 * @see <a
 *      href="http://roy.gbiv.com/pubs/dissertation/rest_arch_style.htm#sec_5_2_1_2">Source
 *      dissertation</a>
 * @author Lorenzo Villani <lvillani@binaryhelix.net>
 */
class metadata {
public:
    metadata(const std::string&);
    metadata(const std::string&, const std::string&);

    virtual ~metadata() {}

    // Getters and setters
    const std::string& name();
    const std::string& description();

protected:
    std::string m_name;
    std::string m_description;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_METADATA_HPP */
