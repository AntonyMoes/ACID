#ifndef ACID_INCLUDE_INPUT_NODE_H_
#define ACID_INCLUDE_INPUT_NODE_H_


#include <framework/node.h>
#include <input_component.h>
#include <framework/active_system.h>
#include <framework/entity.h>
#include <framework/entity_life_queue.h>
#include <framework/entity_life_system.h>

class InputNode : public Node<InputNode> {
  public:
    InputNode() {
        add_component<InputComponent>();
    }
};

#endif  // ACID_INCLUDE_INPUT_NODE_H_
