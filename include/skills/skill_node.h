#ifndef ACID_INCLUDE_SKILLS_SKILL_NODE_H_
#define ACID_INCLUDE_SKILLS_SKILL_NODE_H_


#include <framework/node.h>
#include <components/body_component.h>
#include "input_skill_component.h"

class SkillNode : public Node<SkillNode> {
  public:
    SkillNode() {
        add_component<InputSkillComponent>();
        add_component<BodyComponent>();
    }
};

#endif  // ACID_INCLUDE_SKILLS_SKILL_NODE_H_
