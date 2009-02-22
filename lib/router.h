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

#ifndef ROUTER_H
#define ROUTER_H

#include <QHash>

#include "context.h"

class QString;
class Resource;

class Router {
public:
    Router(const Context& context) : m_context(context) {}
    virtual ~Router() {}

    void attach(const QString& uri, Resource* resource);
    
    const QList<Resource*> attachedResources() const
        { return m_resources; }

    void setContext(const Context& context)
        { m_context = context; }
    const Context& context() const
        { return m_context; }
private:
    Context m_context;
    QList<Resource*> m_resources;
};

#endif // ROUTER_H
