#include "TestUtil.h"
#include "Types.h"

i32 main(i32 argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
