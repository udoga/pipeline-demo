#include "StringUtil.h"

namespace demo {
    std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
        std::vector<std::string> output;
        size_t start = 0;
        for (size_t pos; (pos = s.find(delimiter, start)) != std::string::npos; start = pos + delimiter.size())
            output.push_back(s.substr(start, pos - start));
        output.push_back(s.substr(start));
        return output;
    }

    std::vector<u8> hex_to_vector(const std::string& hex) {
        std::vector<u8> buffer(hex.size() / 2);
        for (u32 i = 0; i < hex.size() / 2; i++)
            buffer[i] = u8(stoi(hex.substr(i * 2, 2), nullptr, 16));
        return buffer;
    }
}
