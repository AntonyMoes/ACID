#ifndef ACID_INCLUDE_SKILL_SYNC_NODE_H_
#define ACID_INCLUDE_SKILL_SYNC_NODE_H_


#include <framework/node.h>
#include <entities/name_component.h>
#include "input_skill_component.h"

class SkillSyncNode : public Node<SkillSyncNode> {
  public:
    SkillSyncNode() {
        add_component<NameComponent>();
        add_component<InputSkillComponent>();
    }
};

#endif  // ACID_INCLUDE_SKILL_SYNC_NODE_H_
