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

#include <list>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "conditions.hpp"

namespace nanogear {
namespace rest {
namespace data {

const boost::gregorian::date& conditions::modified_since() const
{
    return m_modified_since;
}
void conditions::set_modified_since(const boost::gregorian::date& modified_since)
{
    m_modified_since = modified_since;
}

const boost::gregorian::date& conditions::unmodified_since() const
{
    return m_unmodified_since;
}
void conditions::set_unmodified_since(const boost::gregorian::date& unmodified_since)
{
    m_unmodified_since = unmodified_since;
}

const std::list<tag>& conditions::match() const
{
    return m_match;
}
void conditions::set_match(const std::list<tag>& match)
{
    m_match = match;
}

const std::list<tag>& conditions::none_match() const
{
    return m_none_match;
}
void conditions::set_none_match(const std::list<tag>& none_match)
{
    m_none_match = none_match;
}



}
}
}
