#include <gtest/gtest.h>
#include "StringUtil.h"

namespace demo {
    TEST(StringUtilTest, splitsString) {
        EXPECT_EQ(std::vector<std::string>({""}), split("", ","));
        EXPECT_EQ(std::vector<std::string>({"ab"}), split("ab", ","));
        EXPECT_EQ(std::vector<std::string>({"a", "b", "cd"}), split("a,b,cd", ","));
        EXPECT_EQ(std::vector<std::string>({"a", "bc", "", "def", ""}), split("a,bc,,def,", ","));
        EXPECT_EQ(std::vector<std::string>({"a,bc", "def,"}), split("a,bc,,def,", ",,"));
    }

    TEST(StringUtilTest, convertsHexToVector) {
        std::vector<u8> bytes = hex_to_vector("01113F");
        EXPECT_EQ(0x01, bytes[0]);
        EXPECT_EQ(0x11, bytes[1]);
        EXPECT_EQ(0x3F, bytes[2]);
    }
}
