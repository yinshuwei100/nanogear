#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

#include "utils.hpp"

namespace nanogear {
namespace cli {

void create_dir(const std::string& directory) {
    std::cout << "[mkdir] " << directory << std::endl;
    boost::filesystem::create_directory(directory);
}

void copy_file(const std::string& source, const std::string& dest) {
    std::cout << "[copy] " << source << " to " << dest << std::endl;
    boost::filesystem::copy_file(source, dest);
}

}
}
