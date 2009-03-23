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

#ifndef NANOGEAR_CLIENTINFO_H
#define NANOGEAR_CLIENTINFO_H

#include <QLocale>
#include <QMetaType>
#include "Preference.h"
#include "MimeType.h"

class QTextCodec;

namespace Nanogear {

class ClientInfo {
public:
    ClientInfo(const QString& ua = QString())
        : m_userAgent(ua) { qRegisterMetaType<ClientInfo>(); }

    void setUserAgent(const QString& a)
        { m_userAgent = a; }
    const QString& userAgent() const
        { return m_userAgent; }

    void setAcceptedMimeTypes(const Preference<MimeType>::List& mimeTypes)
        { m_mimeTypes = mimeTypes; }
    const Preference<MimeType>::List& acceptedMimeTypes() const
        { return m_mimeTypes; }

    void setAcceptedLocales(const Preference<QLocale>::List& locales)
        { m_locales = locales; }
    const Preference<QLocale>::List& acceptedLocales() const
        { return m_locales; }

    void setAcceptedTextCodecs(const Preference<QTextCodec*>::List& codecs)
        { m_codecs = codecs; }
    const Preference<QTextCodec*>::List& acceptedTextCodecs() const
        { return m_codecs; }
private:
    QString m_userAgent;
    Preference<MimeType>::List m_mimeTypes;
    Preference<QLocale>::List m_locales;
    Preference<QTextCodec*>::List m_codecs;
};

}

Q_DECLARE_METATYPE(Nanogear::ClientInfo);

#endif // NANOGEAR_CLIENTINFO_H
