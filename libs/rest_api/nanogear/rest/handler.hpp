/*
 *
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NANOGEAR_REST_HANDLER_HPP
#define NANOGEAR_REST_HANDLER_HPP
#include "context.hpp"
#include "data/request.hpp"
#include "data/response.hpp"

namespace nanogear {
namespace rest {
class handler
{
public:
    handler(const context& = context(), const data::request& = data::request(), const data::response& = data::response());
    virtual bool allow_delete() const;
    virtual bool allow_get() const;
    virtual bool allow_head() const;
    virtual bool allow_options() const;
    virtual bool allow_post() const;
    virtual bool allow_put() const;
    const context& get_context() const;
    const data::request& get_request() const;
    const data::response& get_response() const;
    void handle_delete();
    void handle_get();
    void handle_head();
    void handle_options();
    void handle_post();
    void handle_put();
    void init(const context&, const data::request&, const data::response&);
    void set_context(const context&);
    void set_request(const data::request&);
    void set_response(const data::response&);
    void update_allowed_methods();
private:
    context m_context;
    data::request m_request;
    data::response m_response;
};
}
}

#endif // HANDLER_H
