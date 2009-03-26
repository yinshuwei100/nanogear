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

#include "ClientInfo.h"
#include <QLocale>
#include <QMetaType>
#include "Preference.h"
#include "MimeType.h"

namespace Nanogear {

struct ClientInfo::Private {
    Private(const QString& ua) : userAgent(ua) {};
    QString userAgent;
    PreferenceList<MimeType> mimeTypes;
    PreferenceList<QLocale> locales;
    PreferenceList<QTextCodec*> codecs;
};

ClientInfo::ClientInfo(const QString& ua) : d(new Private(ua)) {
    qRegisterMetaType<ClientInfo>();
}
ClientInfo::~ClientInfo() {
    delete d;
}

void ClientInfo::setUserAgent(const QString& a) {
    d->userAgent = a;
}
const QString& ClientInfo::userAgent() const {
    return d->userAgent;
}

void ClientInfo::setAcceptedMimeTypes(const PreferenceList<MimeType>& mimeTypes) {
    d->mimeTypes = mimeTypes;
}
const PreferenceList<MimeType>& ClientInfo::acceptedMimeTypes() const {
    return d->mimeTypes;
}

void ClientInfo::setAcceptedLocales(const PreferenceList<QLocale>& locales) {
    d->locales = locales;
}
const PreferenceList<QLocale>& ClientInfo::acceptedLocales() const {
    return d->locales;
}

void ClientInfo::setAcceptedTextCodecs(const PreferenceList<QTextCodec*>& codecs) {
    d->codecs = codecs;
}
const PreferenceList<QTextCodec*>& ClientInfo::acceptedTextCodecs() const {
    return d->codecs;
}

}

