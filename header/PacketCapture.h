#pragma once

#include <string>
#include <vector>
#include "Serializable.h"

namespace demo {
    class PacketCapture: public Serializable {
    public:
        std::string time;
        std::string sourceHost;
        std::string destinationHost;
        std::string sourcePort;
        std::string destinationPort;
        std::string rawSequence;
        std::string data;
        PacketCapture(const std::string& s);
        PacketCapture(const std::vector<std::string>& cells);
        u32 getSize() const override;
        void serialize(u8* buffer) const override;
    };
}
