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

#ifndef UNIFORM_H
#define UNIFORM_H

class QHttpRequestHeader;
class QTcpSocket;

//! @note Support only GET until I come up with a better design
//! @todo Find better names for methods
class Uniform {
public:
    virtual void put() {}
    //! @todo WRONG! Create and use abstract Request and Response objects
    virtual void get(const QHttpRequestHeader& header, QTcpSocket* out) {}
    virtual void post() {}
    virtual void _delete() {}
    virtual void head() {}
    virtual void options() {}
};

#endif // UNIFORM_H
