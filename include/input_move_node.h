#ifndef ACID_INCLUDE_INPUT_MOVE_NODE_H_
#define ACID_INCLUDE_INPUT_MOVE_NODE_H_

#include <node.h>
#include <position_component.h>
#include <input_move_component.h>


class InputMoveNode: public Node<InputMoveNode> {
  public:
    InputMoveNode() {
        add_component<InputMoveComponent>();
    }
};

#endif  // ACID_INCLUDE_INPUT_MOVE_NODE_H_
