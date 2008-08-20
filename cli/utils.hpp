/*
 * This file is part of the nanogear project
 *
 * (C) Copyright 2008 by Lorenzo Villani <lvillani@binaryhelix.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation;
 * version 3 of the License
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef NANOGEAR_CLI_UTILS_HPP
#define NANOGEAR_CLI_UTILS_HPP

#include <string>

namespace nanogear {
namespace cli {

void create_dir(const std::string& directory);
void copy_file(const std::string& source, const std::string& dest);

}
}

#endif /* NANOGEAR_CLI_UTILS_HPP */

