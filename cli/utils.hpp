#ifndef NANOGEAR_CLI_UTILS_HPP
#define NANOGEAR_CLI_UTILS_HPP

#include <string>

namespace nanogear {
namespace cli {

void create_dir(const std::string& directory);
void copy_file(const std::string& source, const std::string& dest);

}
}

#endif
