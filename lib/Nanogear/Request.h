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

#ifndef NANOGEAR_REQUEST_H
#define NANOGEAR_REQUEST_H

#include <QString>
#include "Context.h"
#include "ClientInfo.h"
#include "Method.h"

namespace Nanogear {

class Request {
public:
    Request() {};
    Request(const Method& m, const Context& c,
        const ClientInfo& cI = ClientInfo())
        : m_method(m), m_context(c), m_clientInfo(cI) {}
    virtual ~Request() {};

    const Method& method() const
        { return m_method; }
    void setMethod(const Method& method)
        { m_method = method; }

    const Context& context() const
        { return m_context; }
    void setContext(const Context& context)
        { m_context = context; }

    void setClientInfo(const ClientInfo& clientInfo)
        { m_clientInfo = clientInfo; }
    const ClientInfo& clientInfo() const
        { return m_clientInfo; }

private:
    Method m_method;
    Context m_context;
    ClientInfo m_clientInfo;
};

}

#endif /* NANOGEAR_REQUEST_H */
