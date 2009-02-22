/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef RESOURCE_H
#define RESOURCE_H

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

#endif // RESOURCE_H
