#ifndef ACID_INCLUDE_SKILL_INPUT_SKILL_NODE_H_
#define ACID_INCLUDE_SKILL_INPUT_SKILL_NODE_H_


#include <framework/node.h>
#include "input_skill_component.h"

class InputSkillNode : public Node<InputSkillNode> {
  public:
    InputSkillNode() {
        add_component<InputSkillComponent>();
    }
};

#endif  // ACID_INCLUDE_SKILL_INPUT_SKILL_NODE_H_
