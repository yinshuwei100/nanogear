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

#ifndef NANOGEAR_REST_DATAMETADATA_HPP
#define NANOGEAR_REST_DATAMETADATA_HPP

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

private:
    std::string m_name;
    std::string m_description;
};

}
}
}

#endif /* NANOGEAR_REST_DATAMETADATA_HPP */
