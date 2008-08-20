/*
 * This file is part of the nanogear project
 *
 * (C) Copyright 2008 by Lorenzo Villani <lvillani@binaryhelix.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation;
 * version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

#include "utils.hpp"
#include "generate_project.hpp"

namespace nanogear {
namespace cli {

static void generate_cmake(const std::string& project_name) {
    std::cout << "[cmake] Creating project level CMakeLists.txt" << std::endl;
    boost::filesystem::path project_path(project_name);

    // Top level CMakeLists.txt
    std::ofstream cfile((project_path / "CMakeLists.txt").string().c_str());
    cfile << "project(" << project_name << ")" << std::endl
        << "cmake_minimum_required(VERSION 2.6)" << std::endl
        << std::endl
        << "find_library(Boost 1.35 COMPONENTS" << std::endl
        << "\tprogram_options" << std::endl
        << "\tREQUIRED)" << std::endl
        << std::endl
        << "add_subdirectory(app)" << std::endl
        << "add_subdirectory(tests)" << std::endl;
    cfile.close();

    // Application cmake file
    cfile = std::ofstream((project_path / "app" / "CMakeLists.txt").string()
            .c_str());
    cfile << "add_subdirectory(controllers)" << std::endl
        << "add_subdirectory(models)" << std::endl
        << "add_subdirectory(views)" << std::endl;
    cfile.close();
}

void generate_project(const std::string& project_name) {
    if (!boost::filesystem::exists(project_name)) {
        if (getenv("NANOGEAR_RESOURCES_DIR")) {
            std::string templates_dir(getenv("NANOGEAR_RESOURCES_DIR"));
            templates_dir.append("/templates");

            std::cout << "Creating project: " << project_name << std::endl;

            // Create directories without subdirectories
            create_dir(project_name);
            create_dir(std::string(project_name).append("/html"));
            create_dir(std::string(project_name).append("/config"));
            create_dir(std::string(project_name).append("/tests"));

            // Create the 'app' directory with MVC subdirs
            create_dir(std::string(project_name).append("/app"));
            create_dir(std::string(project_name).append("/app/controllers"));
            create_dir(std::string(project_name).append("/app/models"));
            create_dir(std::string(project_name).append("/app/views"));

            // Copy the router and dispatcher to app

            // Copy cpp and hpp templates in config directory
            copy_file(std::string(templates_dir).append("/cpp"),
                      std::string(project_name).append("/config/cpp.template"));
            copy_file(std::string(templates_dir).append("/hpp"),
                      std::string(project_name).append("/config/hpp.template"));

            generate_cmake(project_name);
        } else {
            std::cerr << "[error] Environment variable " <<
            "NANOGEAR_RESOURCES_DIR was not defined" << std::endl;
        }
    } else {
        std::cerr << "[error] Project already exists" << std::endl;
    }
}

}
}
