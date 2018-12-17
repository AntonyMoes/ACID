#ifndef ACID_INCLUDE_INPUT_MOUSE_NODE_H_
#define ACID_INCLUDE_INPUT_MOUSE_NODE_H_

#include <framework/node.h>
#include <input_mouse_component.h>
#include <camera_component.h>

class InputMouseNode : public Node<InputMouseNode> {
  public:
    InputMouseNode() {
        add_component<InputMouseComponent>();
        add_component<CameraComponent>();
    }
};

#endif  // ACID_INCLUDE_INPUT_MOUSE_NODE_H_
