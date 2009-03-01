/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
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

/*- HEADER NAME: Resource -*/

#ifndef NANOGEAR_RESOURCE_H
#define NANOGEAR_RESOURCE_H

#include "context.h"

class Resource {
public:
    virtual void handleGet()  {}
    virtual void handlePut()  {}
    virtual void handlePost() {}
    virtual void handleOptions() {}
    virtual void handleDelete()  {}


    void setContext(const Context& context)
        { m_context = context; }
    const Context& context() const
        { return m_context; }

//     void setRequest(const Request& request);
//     const Request& request() const;
// 
//     void setResponse(const Response& response);
//     Response& response();
    
private:
    bool m_modifiable;
    Context m_context;
//     Request m_request;
//     Response m_response;
};

#endif // NANOGEAR_RESOURCE_H
