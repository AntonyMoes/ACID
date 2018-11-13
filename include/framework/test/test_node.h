#ifndef ACID_INCLUDE_TEST_NODE_H_
#define ACID_INCLUDE_TEST_NODE_H_


#include <gtest/gtest.h>
#include <node.h>



class FakeNode: public Node<FakeNode> {
  public:
    FakeNode() : Node() {}
};


class FakeComponent: public IComponent {};


class SetupTestNode: public ::testing::Test {
  protected:
    void SetUp() final {
        node = new FakeNode;
    }

    void TearDown() final {
        delete node;
    }

    FakeNode* node;
};


#endif  // ACID_INCLUDE_TEST_NODE_H_
