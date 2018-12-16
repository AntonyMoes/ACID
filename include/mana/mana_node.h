#ifndef ACID_MANA_MANA_NODE_H_
#define ACID_MANA_MANA_NODE_H_


#include <framework/node.h>
#include "mana_component.h"

class ManaNode : public Node<ManaNode> {
  public:
    ManaNode() {
        add_component<ManaComponent>();
    }
};

#endif  // ACID_MANA_MANA_NODE_H_
