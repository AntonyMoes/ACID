//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_LVLUPSYNCNODE_H
#define A_C_I_D_LVLUPSYNCNODE_H

#include <framework/node.h>
#include <entities/name_component.h>
#include "skill_component.h"

class LvlupSyncNode : public Node<LvlupSyncNode> {
  public:
    LvlupSyncNode() {
        add_component<SkillComponent>();
        add_component<NameComponent>();
    }
};

#endif //A_C_I_D_LVLUPSYNCNODE_H
