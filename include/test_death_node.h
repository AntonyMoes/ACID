#ifndef ACID_INCLUDE_TEST_DEATH_NODE_H_
#define ACID_INCLUDE_TEST_DEATH_NODE_H_


#include <framework/node.h>
#include "death_component.h"
#include "texture_component.h"

class TestDeathNode : public Node<TestDeathNode> {
  public:
    TestDeathNode() {
        add_component<DeathComponent>();
        add_component<TextureComponent>();
    }
};

#endif  // ACID_INCLUDE_TEST_DEATH_NODE_H_
