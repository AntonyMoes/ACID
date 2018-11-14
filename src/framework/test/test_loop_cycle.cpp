#include <test_loop_cycle.h>



TEST_F(SetupLoopCycle, BaseTest) {
    EXPECT_CALL(*g_system, execute()).Times(1);
    EXPECT_CALL(*e_system, execute()).Times(1);
    EXPECT_CALL(*c_system, execute()).Times(1);
    ASSERT_NO_THROW(gm->run());
}
