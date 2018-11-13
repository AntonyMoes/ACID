#ifndef ACID_INCLUDE_TEST_NODE_MANAGER_H_
#define ACID_INCLUDE_TEST_NODE_MANAGER_H_


#include <gtest/gtest.h>

#include <node_manager.h>
#include <node.h>


class FakeComponent: public IComponent {};

class FakeNode: public Node<FakeNode> {
  public:
    FakeNode() : Node() {}
};

class FakeEntity: public Entity {
  public:
    FakeEntity(): Entity() {}
};

class SetupNodeManager: public ::testing::Test {
  protected:
    void SetUp() final {
        nm = new NodeManager;
        node = new FakeNode;
        entity = new FakeEntity;
        comp = new FakeComponent;
        entity->add_component(comp);
    }

    void TearDown() final {
        delete nm;
        delete node;
        delete entity;
    }

    FakeComponent* comp;
    FakeNode* node;
    FakeEntity* entity;
    NodeManager* nm;
};


#endif  // ACID_INCLUDE_TEST_NODE_MANAGER_H_
