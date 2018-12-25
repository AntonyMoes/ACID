#ifndef ACID_INCLUDE_TEST_NODE_H_
#define ACID_INCLUDE_TEST_NODE_H_


#include <gtest/gtest.h>
#include <node.h>



class ReactFakeNode: public Node<ReactFakeNode> {
  public:
    ReactFakeNode() : Node() {}
};


class ReactFakeComponent: public IComponent {};


class SetupTestNode: public ::testing::Test {
  protected:
    void SetUp() final {
        node = new ReactFakeNode;
    }

    void TearDown() final {
        delete node;
    }

    ReactFakeNode* node;
};


#endif  // ACID_INCLUDE_TEST_NODE_H_
