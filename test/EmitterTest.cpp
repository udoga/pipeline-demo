#include <gtest/gtest.h>
#include "Collector.h"
#include "Emitter.h"

namespace demo {
    class EmitterTest: public ::testing::Test {
    public:
        Emitter<i32> emitter;
        Collector<i32> collector;

        void SetUp() override {
            emitter.enrol(collector);
        }
    };

    TEST_F(EmitterTest, collectorHasNoItems) {
        EXPECT_EQ(0, collector.items.size());
    }

    TEST_F(EmitterTest, whenEmits_collectorSavesIt) {
        emitter.emit(5);
        ASSERT_EQ(1, collector.items.size());
        EXPECT_EQ(5, collector.items[0]);
    }
}
