#include <gtest/gtest.h>
#include "Slice.h"

namespace demo {
    TEST(SliceTest, initializesWithPtr) {
        u8 data[]{0x00, 0x01, 0x02, 0x03};
        Slice slice(data + 1, 2);
        EXPECT_EQ(0x01, slice[0]);
        EXPECT_EQ(0x01, slice.data[0]);
        EXPECT_EQ(2, slice.size);
    }

    TEST(SliceTest, initializesWithVector) {
        std::vector<u8> v({0, 1, 2});
        Slice slice(v, 1);
        EXPECT_EQ(2, slice.size);
        EXPECT_EQ(1, slice[0]);
        EXPECT_EQ(2, slice[1]);
    }

    TEST(SliceTest, serializes) {
        u8 buffer[]{0x00, 0x00, 0x00};
        std::vector<u8> v{0, 1, 2};
        Slice slice(v);
        slice.serialize(buffer);
        EXPECT_EQ(3, slice.getSize());
        EXPECT_EQ(0, buffer[0]);
        EXPECT_EQ(1, buffer[1]);
        EXPECT_EQ(2, buffer[2]);
    }
}
