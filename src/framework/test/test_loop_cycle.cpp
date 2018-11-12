#include <test_loop_cycle.h>

TEST_F(SetupLoopCycle, BaseTest) {
    gm->add_prototype(node);
    gm->add_system(system);
    gm->run();
}