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




#ifndef NANOGEAR_REST_FILTER_HPP
#define NANOGEAR_REST_FILTER_HPP

#include <boost/shared_ptr.hpp>

#include "controller.hpp"
#include "data/request.hpp"
#include "data/response.hpp"
#include "context.hpp"

namespace nanogear {
namespace rest {

template <class T>    
class filter : public controller {
public:
    filter(const context& c = context(), boost::shared_ptr<T> n = boost::shared_ptr<T>());
    inline ~filter() {};
    boost::shared_ptr<T>& next();
    bool has_next();
    void set_next(boost::shared_ptr<T>&);
    void operator()(const data::request&, const data::response&);

protected:
    virtual void after_handle(const data::request&, const data::response&) {}
    virtual void before_handle(const data::request&, const data::response&) {}
    virtual void do_handle(const data::request&, const data::response&);

private:
    boost::shared_ptr<T> m_next;
};

// Specialization for pointers (i.e. function pointers).
template <typename T>
class filter<T*> : public controller {
public:
    filter(const context& c = context(), T* n = 0);
    inline ~filter() {};
    T* next();
    bool has_next();
    void set_next(T*);
    void operator()(const data::request&, const data::response&);

protected:
    virtual void after_handle(const data::request&, const data::response&) {}
    virtual void before_handle(const data::request&, const data::response&) {}
    virtual void do_handle(const data::request&, const data::response&);

private:
    T* m_next;
};

template <class T>
inline filter<T>::filter(const context& c, boost::shared_ptr<T> n) : controller(c), m_next(n) {}

template <typename T>
inline filter<T*>::filter(const context& c, T* n) : controller(c), m_next(n) {}

template <class T>
inline boost::shared_ptr<T>& filter<T>::next()
{
    return m_next;
}

template <typename T>
inline T* filter<T*>::next()
{
    return m_next;
}

template <typename T>
inline bool filter<T>::has_next()
{
    return m_next != 0;
}

template <class T>
inline void filter<T>::set_next(boost::shared_ptr<T>& next)
{
    m_next = next;
}

template <typename T>
inline void filter<T*>::set_next(T* next)
{
    m_next = next;
}

template <typename T>
void filter<T>::operator()(const data::request& req, const data::response& res)
{
    init(req, res);
    before_handle(req, res);
    do_handle(req, res);
    after_handle(req, res);
}

template <typename T>
void filter<T>::do_handle(const data::request& req, const data::response& res)
{
    if (has_next()) (*next())(req, res); else
    throw std::runtime_error("do_handle() without a next controller.");
}

}
}

#endif /* NANOGEAR_REST_FILTER_HPP */
