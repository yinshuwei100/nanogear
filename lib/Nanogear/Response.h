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

#ifndef NANOGEAR_RESPONSE_H
#define NANOGEAR_RESPONSE_H

#include <QMetaType>

class QDateTime;

namespace Nanogear {

class Status;

namespace Resource {
class Representation;
}

/*!
 * \class Response
 * \brief Encapsulates a response to the client
 *
 * A Response object represents a server response. Resources usually have the
 * task to fill a Response object which will be sent back to the client by a
 * concrete implementation of Server
 */
class Response {
public:
    /*!
     * A default constructor which builds a Response with an empty
     * representation.
     */
    Response();

    /*!
     * A constructor used to initialize several values
     * \param status The response status code
     * \param rep A representation attached to this Response
     * \param expires A QDateTime representing the expiration date of this response
     */
    Response(const Status& s, const Resource::Representation* rep);
    Response(const Status& s, const Resource::Representation* rep, const QDateTime& expires);
    virtual ~Response();

    /*!
     * Set the response status code
     * \param status The response status code
     */
    void setStatus(const Status& s);

    /*!
     * \return The response' status code
     */
    const Status& status();

    /*!
     * Set the representation attached to this Response
     * \param representation A pointer to a Representation object
     */
    void setRepresentation(const Resource::Representation* representation);

    /*!
     * \return The representation attached to this Response
     */
    const Resource::Representation* representation() const;

    /*!
     * Set the expiration date for this Response
     * \param expirationDate A QDateTime representing the expiration date
     */
    void setExpirationDate(const QDateTime& expires);

    /*!
     * \return the expiration date of this Response
     */
    const QDateTime& expirationDate() const;
private:
    struct Private;
    Private* d;
};

}

Q_DECLARE_METATYPE(Nanogear::Response)

#endif /* NANOGEAR_RESPONSE_H */
