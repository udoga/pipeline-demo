#pragma once

#include <fstream>
#include <string>
#include "Emitter.h"
#include "Listener.h"

namespace demo {
    class TextReader: public Listener, public Emitter<std::string> {
    public:
        TextReader(const std::string& path, bool skipTitle);
        bool left() const;
        void listen() override;
    private:
        std::ifstream stream;
        std::string line;
    };
}
