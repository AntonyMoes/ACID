#include <test_node_manager.h>

TEST_F(SetupNodeManager, UnitTestAddComp) {
    ASSERT_NO_THROW(nm->add_prototype(node));
}

TEST_F(SetupNodeManager, UnitTestAddNodes) {
    ASSERT_NO_THROW(nm->add_nodes(entity));
}