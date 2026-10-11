#include <gtest/gtest.h>
#include "PacketCapture.h"

namespace demo {
    TEST(PacketCaptureTest, parsesRow) {
        PacketCapture capture("time;source;destination;1000;2000;;0A1BFF");
        EXPECT_EQ("time", capture.time);
        EXPECT_EQ("source", capture.sourceHost);
        EXPECT_EQ("destination", capture.destinationHost);
        EXPECT_EQ("1000", capture.sourcePort);
        EXPECT_EQ("2000", capture.destinationPort);
        EXPECT_EQ("", capture.rawSequence);
        EXPECT_EQ("0A1BFF", capture.data);
    }

    TEST(PacketCaptureTest, serializesPayload) {
        PacketCapture capture(";;;;;;0A1BFF");
        u8 buffer[3]{};
        capture.serialize(buffer);
        EXPECT_EQ(3, capture.getSize());
        EXPECT_EQ(0x0A, buffer[0]);
        EXPECT_EQ(0x1B, buffer[1]);
        EXPECT_EQ(0xFF, buffer[2]);
    }
}
