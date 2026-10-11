#include "PacketCapture.h"
#include "StringUtil.h"
#include "Slice.h"

namespace demo {
    PacketCapture::PacketCapture(const std::string& s): PacketCapture(split(s, ";")) {
    }

    PacketCapture::PacketCapture(const std::vector<std::string>& cells):
            time(cells.at(0)),
            sourceHost(cells.at(1)),
            destinationHost(cells.at(2)),
            sourcePort(cells.at(3)),
            destinationPort(cells.at(4)),
            rawSequence(cells.at(5)),
            data(cells.at(6)) {
    }

    u32 PacketCapture::getSize() const {
        return data.size() / 2;
    }

    void PacketCapture::serialize(u8* buffer) const {
        Slice(hex_to_vector(data)).serialize(buffer);
    }
}
