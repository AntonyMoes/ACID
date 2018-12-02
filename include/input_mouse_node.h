#ifndef ACID_INCLUDE_INPUT_MOUSE_NODE_H_
#define ACID_INCLUDE_INPUT_MOUSE_NODE_H_


#include <framework/node.h>

class InputMouseNode : public Node<InputMouseNode> {
  public:
    InputMouseNode() {
        add_component<InputMouseComponent>();
    }
};

#endif  // ACID_INCLUDE_INPUT_MOUSE_NODE_H_
