//
// Created by antonymo on 02.12.18.
//

#ifndef ACID_INCLUDE_FIREBALL_CREATION_NODE_H_
#define ACID_INCLUDE_FIREBALL_CREATION_NODE_H_


#include <framework/node.h>
#include "input_mouse_component.h"
#include "collision_component.h"

class FireballCreationNode : public Node<FireballCreationNode> {
  public:
    FireballCreationNode() {
        add_component<InputMouseComponent>();
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_FIREBALL_CREATION_NODE_H_
