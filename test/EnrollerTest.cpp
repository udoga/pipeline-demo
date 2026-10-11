#include <gtest/gtest.h>
#include "Enroller.h"

namespace demo {
    class DummySubscriber {
    };

    class EnrollerTest: public ::testing::Test {
    public:
        DummySubscriber subscriber;
        Enroller<DummySubscriber> enroller;
    };

    TEST_F(EnrollerTest, hasNoSubscribers) {
        ASSERT_EQ(0, enroller.getSubscribers().size());
    }

    TEST_F(EnrollerTest, whenEnrols_addsSubscriber) {
        enroller.enrol(subscriber);
        ASSERT_EQ(1, enroller.getSubscribers().size());
    }
}
