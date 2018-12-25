#ifndef ACID_INCLUDE_MANA_SYNC_NODE_H_
#define ACID_INCLUDE_MANA_SYNC_NODE_H_


#include <framework/node.h>
#include <entities/name_component.h>
#include "mana_component.h"

class ManaSyncNode : public Node<ManaSyncNode> {
  public:
    ManaSyncNode() {
        add_component<NameComponent>();
        add_component<ManaComponent>();
    }
};

#endif  // ACID_INCLUDE_MANA_SYNC_NODE_H_
