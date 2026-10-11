#include <stdexcept>
#include "TextReader.h"

namespace demo {
    TextReader::TextReader(const std::string& path, bool skipTitle): stream(path) {
        if (!stream.is_open()) throw std::runtime_error(std::string("File not found: ") + path);
        if (skipTitle) std::getline(stream, line);
    }

    bool TextReader::left() const {
        return !stream.eof();
    }

    void TextReader::listen() {
        if (std::getline(stream, line)) emit(line);
    }
}
