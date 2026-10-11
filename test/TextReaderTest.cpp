#include <gtest/gtest.h>
#include "Collector.h"
#include "TextReader.h"

namespace demo {
    class TextReaderTest: public ::testing::Test {
    protected:
        std::string path = "resource/test.csv";
        Collector<std::string> collector;
    };

    TEST_F(TextReaderTest, checksIfFileExists) {
        EXPECT_THROW(TextReader("resource/missing.csv", false), std::runtime_error);
    }

    TEST_F(TextReaderTest, readsAndEmitsLines) {
        TextReader reader(path, false);
        reader.enrol(collector);
        reader.listen();
        reader.listen();
        ASSERT_EQ(2, collector.items.size());
        EXPECT_EQ("Header1;Header2;Header3", collector.items[0]);
        EXPECT_EQ("Cell11;Cell12;Cell13", collector.items[1]);
    }

    TEST_F(TextReaderTest, canSkipTitle) {
        TextReader reader(path, true);
        reader.enrol(collector);
        reader.listen();
        ASSERT_EQ(1, collector.items.size());
        EXPECT_EQ("Cell11;Cell12;Cell13", collector.items[0]);
    }

    TEST_F(TextReaderTest, checksIfEndOfFile) {
        TextReader reader(path, false);
        reader.enrol(collector);
        while (reader.left())
            reader.listen();
        ASSERT_EQ(3, collector.items.size());
    }
}
