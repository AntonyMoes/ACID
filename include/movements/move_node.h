#ifndef ACID_INCLUDE_MOVE_NODE_H_
#define ACID_INCLUDE_MOVE_NODE_H_


#include <node.h>
#include <position_component.h>
#include <input_move_component.h>
#include <collision_component.h>

class MoveNode: public Node<MoveNode> {
  public:
    MoveNode() {
        add_component<InputMoveComponent>();
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_MOVE_NODE_H_
