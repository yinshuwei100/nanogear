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



#ifndef NANOGEAR_REST_DATA_REFERENCE_LIST_HPP
#define NANOGEAR_REST_DATA_REFERENCE_LIST_HPP

#include <list>

#include "reference.hpp"
#include "../resource/representation.hpp"

namespace nanogear {
namespace rest {
namespace data {

template <typename T = reference, typename L = std::list<T> >
class reference_list : public L {
public:
    explicit reference_list(const L::allocator_type& allocator = L::allocator_type()) : L(allocator) {}
    explicit reference_list(size_type size, const T& value = T(),
                  const L::allocator_type& allocator = L::allocator_type()) : L(size, value, allocator) {}
    template <typename I> reference_list(I first, I last, const L::allocator_type()& allocator
                               = L::allocator_type()) : L(first, last, allocator) {}
    reference_list(resource::representation::ptr& uri_list)
    {
        //TODO
    }

    // Thank goodness for C++ implicit conversion!
    //void push_back(const std::string& uri);
    const T& identifier() const
    {
        return m_identifier;
    }
    void set_identifier(const T& identifier)
    {
        m_identifier = identifier;
    }
    const resource::representation::ptr& text_representation() const
    {
    }
private:
    T m_identifier;

};

}
}
}

#endif /* NANOGEAR_REST_DATA_REFERENCE_LIST_HPP */
