#include <test_reactivesystems_cycle.h>

TEST_F(SetupReactiveCycle, BaseReactTest) {
    EXPECT_CALL(*g_system, execute()).Times(1);
    EXPECT_CALL(*e_system, execute()).Times(1);
    EXPECT_CALL(*c_system, execute()).Times(1);
    ASSERT_NO_THROW(gm->run());
}

TEST(NonFixtureReactiveTest, BaseReactTest) {
    auto *g_system = new MockFakeGenSystem;
    auto *e_system = new MockFakeEditSystem;
    auto *c_system = new MockReactiveFakeCheckerSystem;

    auto *gm = new TestGameLoop;

    auto *node = new ReactFakeNode;
    gm->add_prototype(node);
    EntityLifeQueue* tmp = gm->get_queue_ref();
    g_system->set_queue(tmp);
    e_system->set_queue(tmp);
    c_system->set_queue(tmp);
    gm->add_system(g_system);
    gm->add_system(e_system);
    gm->add_system(c_system);
    EXPECT_CALL(*g_system, execute()).Times(1);
    EXPECT_CALL(*e_system, execute()).Times(1);
    EXPECT_CALL(*c_system, execute()).Times(1);
    ASSERT_NO_THROW(gm->run());
}
