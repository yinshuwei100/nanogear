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




#ifndef NANOGEAR_REST_FILTER_HPP
#define NANOGEAR_REST_FILTER_HPP

#include <boost/shared_ptr.hpp>

#include "controller.hpp"
#include "data/request.hpp"
#include "data/response.hpp"
#include "context.hpp"

namespace nanogear {
namespace rest {

    
class filter : public controller {
public:
    filter(const context& c = context(), boost::shared_ptr<controller> n = boost::shared_ptr<controller>());
    boost::shared_ptr<controller>& next();
    bool has_next();
    void set_next(boost::shared_ptr<controller>&);
    void handle(data::request&, data::response&);

protected:
    virtual void after_handle(data::request&, data::response&) = 0;
    virtual void before_handle(data::request&, data::response&) = 0;
    virtual void do_handle(data::request&, data::response&);

private:
    boost::shared_ptr<controller> m_next;
};


}
}

#endif /* NANOGEAR_REST_FILTER_HPP */
