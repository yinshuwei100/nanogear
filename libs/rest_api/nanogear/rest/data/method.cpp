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



#include <string>

#include "method.hpp"

namespace nanogear {
namespace rest {
namespace data {

method::method(const std::string& name, const std::string& description, const std::string& uri) : metadata(name, description), m_uri(uri) {}

const std::string& method::uri() const
{
    return m_uri;
}


const method method::CONNECT("CONNECT",
                       "Used with a proxy that can dynamically switch to being a tunnel",
                       "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.9");

const method method::COPY("COPY",
                    "Creates a duplicate of the source resource, identified by"
                    "the Request-URI, in the destination resource, identified"
                    "by the URI in the Destination header",
                    "http://www.webdav.org/specs/rfc2518.html#METHOD_COPY");

const method method::DELETE("DELETE",
                      "Requests that the origin server deletes the resource"
                      "identified by the request URI",
                      "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.7");

const method method::GET("GET",
                   "Retrieves whatever information (in the form of an entity)"
                   "that is identified by the request URI",
                   "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.3");

const method method::HEAD("HEAD",
                    "Identical to GET except that the server must not return"
                    "a message body in the response",
                    "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.4");

const method method::LOCK("LOCK",
                    "Used to take out a lock of any access type (WebDAV)",
                    "http://www.webdav.org/specs/rfc2518.html#METHOD_LOCK");

const method method::MKCOL("MKCOL",
                     "Used to create a new collection (WebDAV)",
                     "http://www.webdav.org/specs/rfc2518.html#METHOD_MKCOL");

const method method::MOVE("MOVE",
                    "Logical equivalent of a copy, followed by consistency maintenance"
                    "processing, followed by a delete of the source (WebDAV)",
                    "http://www.webdav.org/specs/rfc2518.html#METHOD_MOVE");


const method method::OPTIONS("OPTIONS",
               "Requests for information about the communication options available"
               "on the request/response chain identified by the URI",
               "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.2");

const method method::POST("POST",
                    "Requests that the origin server accepts the entity enclosed"
                    "in the request as a new subordinate of the resource identified by the request URI",
                    "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.5");


const method method::PROPFIND("PROPFIND",
                        "Retrieves properties defined on the resource identified by the"
                        "request URI",
                        "http://www.webdav.org/specs/rfc2518.html#METHOD_PROPFIND");

const method method::PROPPATCH("PROPPATCH",
                         "Processes instructions specified in the request body to set"
                         "and/or remove properties defined on the resource identified"
                         "by the request URI",
                         "http://www.webdav.org/specs/rfc2518.html#METHOD_PROPPATCH");

const method method::PUT("PUT",
                   "Requests that the enclosed entity be stored under the"
                   "supplied request URI",
                   "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.6");

const method method::TRACE("TRACE",
                     "Used to invoke a remote, application-layer loop-back of"
                     "the request message",
                     "http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.8");

const method method::UNLOCK("UNLOCK",
                      "Removes the lock identified by the lock token from the request URI,"
                      "and allother resources included in the lock",
                      "http://www.webdav.org/specs/rfc2518.html#METHOD_UNLOCK");

method method::value_of(const std::string& name)
{
    if (name == GET.name()) {
        return GET;
    } else if (name == POST.name()) {
        return POST;
    } else if (name == HEAD.name()) {
        return HEAD;
    } else if (name == OPTIONS.name()) {
        return OPTIONS;
    } else if (name == PUT.name()) {
        return PUT;
    } else if (name == DELETE.name()) {
        return DELETE;
    } else if (name == CONNECT.name()) {
        return CONNECT;
    } else if (name == COPY.name()) {
        return COPY;
    } else if (name == LOCK.name()) {
        return LOCK;
    } else if (name == MKCOL.name()) {
        return MKCOL;
    } else if (name == MOVE.name()) {
        return MOVE;
    } else if (name == PROPFIND.name()) {
        return PROPFIND;
    } else if (name == PROPPATCH.name()) {
        return PROPPATCH;
    } else if (name == TRACE.name()) {
        return TRACE;
    } else if (name == UNLOCK.name()) {
        return UNLOCK;
    } else {
        return method(name);
    }
}

}
}
}
