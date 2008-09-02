/*
 * This file is part of the nanogear project
 *
 * (C) Copyright 2008 by Lorenzo Villani <lvillani@binaryhelix.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation;
 * version 3 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

namespace std {
    template <class T> class list<T>;
}

namespace nanogear {
namespace rest {
 
class client : public connector {
public:
    client(context, std::list<data::protocol>);
    client(context, data::protocol);
    client(std::list<data::protocol>);
    client(data::protocol);
    ~client();
    
    void handle(data::request, data::response);
    
    void start();
    void stop();
};

}
}
