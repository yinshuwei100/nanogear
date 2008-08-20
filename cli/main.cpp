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

#include <cstdlib>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "utils.hpp"
#include "generate_project.hpp"

namespace p_o = boost::program_options;

int main(int argc, char **argv) {
    p_o::options_description general_opts("General options");
    p_o::options_description project_opts("Project options");
    p_o::options_description model_opts("Model options");

    general_opts.add_options()
    ("help", "Show help message")
    ("help-all", "Show complete help message")
    ("help-project", "Show project commands")
    ("help-model", "Show model commands")
    ("help-unit", "Show unit testing commands");

    project_opts.add_options()
    ("generate-project", p_o::value<std::string>(), "Create a new project")
    ("generate-app", p_o::value<std::string>(), "Create a new application inside a project");

    model_opts.add_options()
    ("build-db", "Build the database from the model")
    ("build-gateways", "Create table gateways from the model");


    p_o::options_description all_opts("Nanogear CLI tool options");
    all_opts.add(general_opts).add(project_opts).add(model_opts);

    p_o::variables_map vm;
    p_o::store(p_o::parse_command_line(argc, argv, all_opts), vm);

    if (vm.count("help")) {
        std::cout << general_opts << std::endl;
    } else if (vm.count("help-all")) {
        std::cout << all_opts << std::endl;
    } else if (vm.count("help-project")) {
        std::cout << project_opts << std::endl;
    } else if (vm.count("help-model")) {
        std::cout << model_opts << std::endl;
    } else if (vm.count("generate-project")) {
        nanogear::cli::generate_project(vm["generate-project"].as<std::string>());
    }
}
