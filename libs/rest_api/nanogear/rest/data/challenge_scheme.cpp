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

#include "challenge_scheme.hpp"

namespace nanogear {
namespace rest {
namespace data {

bool challenge_scheme::operator==(const challenge_scheme& other) const
{
    return (other.name() == name());
}

bool challenge_scheme::operator!=(const challenge_scheme& other) const
{
    return !(*this == other);
}


const std::string& challenge_scheme::name() const
{
    return m_name;
}
void challenge_scheme::set_name(const std::string& name)
{
    m_name = name;
}

const std::string& challenge_scheme::technical_name() const
{
    return m_technical_name;
}
void challenge_scheme::set_technical_name(const std::string& technical_name)
{
    m_technical_name = technical_name;
}

const std::string& challenge_scheme::description() const
{
    return m_description;
}
void challenge_scheme::set_description(const std::string& description)
{
    m_description = description;
}

challenge_scheme challenge_scheme::value_of(const std::string& name)
{
    if (name == CUSTOM.name()) {
        return CUSTOM;
    } else if (name == HTTP::AWS_S3.name()) {
        return HTTP::AWS_S3;
    } else if (name == HTTP::BASIC.name()) {
        return HTTP::BASIC;
    } else if (name == HTTP::DIGEST.name()) {
        return HTTP::DIGEST;
    } else if (name == HTTP::NTLM.name()) {
        return HTTP::NTLM;
    } else if (name == HTTP::OAUTH.name()) {
        return HTTP::OAUTH;
    } else if (name == POP::BASIC.name()) {
        return POP::BASIC;
    } else if (name == POP::DIGEST.name()) {
        return POP::DIGEST;
    } else if (name == SMTP::PLAIN.name()) {
        return SMTP::PLAIN;
    } else {
        return challenge_scheme(name);
    }
}

// default challenge_schemes
// FIXME: these are not immutable objects
const challenge_scheme challenge_scheme::CUSTOM("CUSTOM", "Custom");
const challenge_scheme challenge_scheme::HTTP::AWS_S3("HTTP_AWS_S3", "AWS", "Amazon S3 HTTP authentication");
const challenge_scheme challenge_scheme::HTTP::BASIC("HTTP_BASIC", "Basic", "Basic HTTP authentication");
const challenge_scheme challenge_scheme::HTTP::DIGEST("HTTP_DIGEST", "Digest", "Digest HTTP authentication");
const challenge_scheme challenge_scheme::HTTP::NTLM("HTTP_NTLM", "NTLM", "Microsoft NTLM HTTP authentication");
const challenge_scheme challenge_scheme::HTTP::OAUTH("HTTP_OAUTH", "OAuth", "Open protocol for API authentication");
const challenge_scheme challenge_scheme::POP::BASIC("POP_BASIC", "Basic", "Basic POP authentication (USER/PASS commands)");
const challenge_scheme challenge_scheme::POP::DIGEST("POP_DIGEST", "Digest", "Digest POP authentication (APOP command)");
const challenge_scheme challenge_scheme::SMTP::PLAIN("SMTP_PLAIN", "PLAIN", "Plain SMTP authentication");

}
}
}
