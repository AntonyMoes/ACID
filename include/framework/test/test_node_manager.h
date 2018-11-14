#ifndef ACID_INCLUDE_TEST_NODE_MANAGER_H_
#define ACID_INCLUDE_TEST_NODE_MANAGER_H_


#include <gtest/gtest.h>

#include <node_manager.h>
#include <node.h>


class ReactFakeComponent: public IComponent {};

class ReactFakeNode: public Node<ReactFakeNode> {
  public:
    ReactFakeNode() : Node() {}
};

class FakeEntity: public Entity {
  public:
    FakeEntity(): Entity() {}
};

class SetupNodeManager: public ::testing::Test {
  protected:
    void SetUp() final {
        nm = new NodeManager;
        node = new ReactFakeNode;
        entity = new FakeEntity;
        comp = new ReactFakeComponent;
        entity->add_component(comp);
    }

    void TearDown() final {
        delete nm;
    }

    ReactFakeComponent* comp;
    ReactFakeNode* node;
    FakeEntity* entity;
    NodeManager* nm;
};


#endif  // ACID_INCLUDE_TEST_NODE_MANAGER_H_
