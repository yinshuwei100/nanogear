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

#ifndef NANOGEAR_REST_DATA_CONDITIONS_HPP
#define NANOGEAR_REST_DATA_CONDITIONS_HPP

#include <list>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "tag.hpp"
#include "status.hpp"
#include "method.hpp"
#include "../resource/variant.hpp"

namespace nanogear {
namespace rest {
namespace data {

class conditions
{
public:
    conditions() {};
    virtual ~conditions() {};

    const boost::gregorian::date& modified_since() const;
    void set_modified_since(const boost::gregorian::date&);

    const boost::gregorian::date& unmodified_since() const;
    void set_unmodified_since(const boost::gregorian::date&);

    const std::list<tag>& match() const;
    void set_match(const std::list<tag>&);

    const std::list<tag>& none_match() const;
    void set_none_match(const std::list<tag>&);
    
private:
    boost::gregorian::date m_modified_since;
    boost::gregorian::date m_unmodified_since;
    std::list<tag> m_match;
    std::list<tag> m_none_match;

    status get_status(method&, variant&) {};
};

#endif /* NANOGEAR_REST_DATA_CONDITIONS_HPP */
