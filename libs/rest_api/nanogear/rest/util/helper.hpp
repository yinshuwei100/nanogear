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

#ifndef NANOGEAR_REST_UTIL_HELPER_HPP
#define NANOGEAR_REST_UTIL_HELPER_HPP

#include <boost/shared_ptr.hpp>
#include <map>

#include "../context.hpp"
#include "../data/request.hpp"
#include "../data/response.hpp"

namespace nanogear {
namespace rest {
namespace util {
template <class T>
class helper {
public:
    helper(boost::shared_ptr<T>& helped) : m_helped(helped) {}
    const std::map<std::string, std::string>& attributes() const
    {
        return m_attributes;
    }
    const boost::shared_ptr<T>& helped() const
    {
        return m_helped;
    }
    void set_helped(const boost::shared_ptr<T>& h)
    {
        m_helped = h;
    }
    const context& get_context() const
    {
        return helped()->context();
    }
    const std::list<data::parameter>& helped_parameters() const
    {
        return helped()->context()->parameters();
    }
    virtual void operator()(const data::request& req, const data::response& res) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void update() = 0;

    typedef boost::shared_ptr< helper<T> > ptr;

private:
    std::map<std::string, std::string> m_attributes;
    boost::shared_ptr<T> m_helped;
};
}
}
}


#endif /* NANOGEAR_REST_UTIL_HELPER_HPP */

