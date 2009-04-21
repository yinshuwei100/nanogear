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

#ifndef NSTATUS_H
#define NSTATUS_H

#include <QObject>
#include <QString>

/*!
 * \class NStatus
 * \brief Response status code
 *
 * This class is used to send Response codes to the clients
 */

class NStatus
{
    Q_GADGET
    Q_ENUMS(Type)
public:

    /*!
     * A default constructor which sends an invalid response code by default (!)
     */
    NStatus() : m_status(Invalid) {}

    /*!
     * Construct the status from its name
     * \param name The status name
     */
    NStatus(const QString& name) : m_status(toType(name)) {}

    /*!
     * An overloaded constructor provided for convenience
     * \param name The status name as C-style string
     */
    NStatus(const char* name) : m_status(toType(name)) {}

    /*!
     * Construct this Status from its code
     * \param status the status code
     */
    NStatus(int status) : m_status(status) {}

    /*!
     * Construct the status from its name
     * \param name The status name
     */
    void fromString(const QString& name)
    { m_status = toType(name); }

    /*!
     * \return The string representation of this status code
     */
    QString toString() const
    { return toString(m_status); }

    /*!
     * Construct this Status from its code
     * \param status the status code
     */
    void fromType(int status)
    { m_status = status; }

    /*!
     * \return The status code
     */
    int toType() const
    { return m_status; }

    bool operator==(const NStatus& type) const
    { return m_status == type.m_status; }

    /*!
     * \return true if this Status is valid
     */
    bool isValid() const
    { return m_status != Invalid; }

    enum Type {
        Invalid = 0,
        Continue = 100,
        SwitchingProtocols = 101,
        Processing = 102,
        OK = 200,
        Created = 201,
        Accepted = 202,
        NonAuthorativeInformation = 203,
        NoContent = 204,
        ResetContent = 205,
        PartialContent = 206,
        MultiStatus = 207,
        MultipleChoices = 300,
        MovedPermanently = 301,
        Found = 302,
        SeeOther = 303,
        NotModified = 304,
        UseProxy = 305,
        SwitchProxy = 306,
        TemporaryRedirect = 307,
        BadRequest = 400,
        Unauthorized = 401,
        PaymentRequired = 402,
        Forbidden = 403,
        NotFound = 404,
        MethodNotAllowed = 405,
        NotAcceptable = 406,
        ProxyAuthenticationRequired = 407,
        RequestTimeout = 408,
        Conflict = 409,
        Gone = 410,
        LengthRequired = 411,
        PreconditionFailed = 412,
        RequestEntityTooLarge = 413,
        RequestURITooLong = 414,
        UnsupportedMediaType = 415,
        RequestedRangeNotSatisfiable = 416,
        ExpectationFailed = 417,
        ImATeapot = 418,
        UnprocessableEntity = 422,
        Locked = 423,
        FailedDependency = 424,
        UnorderedCollection = 425,
        UpgradeRequired = 426,
        RetryWith = 449,
        Blocked = 450,
        InternalServerError = 500,
        NotImplemented = 501,
        BadGateway = 502,
        GatewayTimeout = 504,
        VersionNotSupported = 505,
        VariantAlsoNegotiates = 506,
        InsufficientStorage = 507,
        BandwidthLimitExceeded = 509,
        NotExtended = 510
    };

private:
    QString toString(int value) const;
    int toType(const QString& key) const;

    int m_status;
};

#endif /* NSTATUS_H */
