#include <test_node.h>

TEST_F(SetupTestNode, UnitTestClone) {
    auto cloned_node = node->clone();
    ASSERT_NE(dynamic_cast<INode*>(cloned_node), nullptr);
    delete cloned_node;
}

TEST_F(SetupTestNode, UnitTestSubscribe) {
    ASSERT_NO_THROW(node->subscribe());
}

TEST_F(SetupTestNode, UnitTestGetComponents) {
    ASSERT_EQ(node->get_component<FakeComponent>(), nullptr);
}