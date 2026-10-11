#pragma once

#include <string>
#include <vector>
#include "Types.h"

namespace demo {
    std::vector<std::string> split(const std::string& s, const std::string& delimiter);
    std::vector<u8> hex_to_vector(const std::string& hex);
}
