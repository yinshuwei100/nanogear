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



#ifndef NANOGEAR_REST_DATA_FORM_HPP
#define NANOGEAR_REST_DATA_FORM_HPP

#include <list>
#include <string>
#include <map>

#include "parameter.hpp"

namespace nanogear {
namespace rest {
namespace data {

template <typename T = parameter, typename A = std::allocator<T>, typename L = std::list<T, A> >
class form : public L {
public:
    explicit form(const A& allocator = A()) : L(allocator) {}
    explicit form(size_type size, const T& value = T(),
                  const A& allocator = A()) : L(size, value, allocator) {}
    template <typename I> form(I first, I last, const A& allocator = A()) :
                               L(first, last, allocator) {}
    void push_front(const std::string& name, const std::string& value)
    {
        L::push_front(T(name, value));
    }
    void push_back(const std::string& name, const std::string& value)
    {
        L::push_back(T(name, value));
    }
    void copy_to(std::map<std::string, std::string>& params)
    {
        std::string current_value;
        for (L::iterator i = L::begin(); i != L::end(); ++i) {
            std::map<std::string, std::string>::iterator j = params.find(i->name());
            if (j) {
                params.erase(j);
            }
            params.insert(std::pair<std::string, std::string>(i->name(), i->value()));
        }
    }
private:
};

}
}
}

#endif /* NANOGEAR_REST_DATA_REFERENCE_HPP */
