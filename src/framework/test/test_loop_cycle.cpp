#include <test_loop_cycle.h>

TEST_F(SetupLoopCycle, BaseTest) {
    ASSERT_NO_THROW(gm->run());
}