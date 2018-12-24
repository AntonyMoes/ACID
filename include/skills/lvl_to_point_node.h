#ifndef A_C_I_D_LVL_TO_POINT_NODE_H
#define A_C_I_D_LVL_TO_POINT_NODE_H


#include <framework/node.h>
#include <exp/exp_component.h>
#include "skill_component.h"

class LvlToPointNode : public Node<LvlToPointNode> {
  public:
    LvlToPointNode() {
        add_component<ExpComponent>();
        add_component<SkillComponent>();
    }
};

#endif //A_C_I_D_LVL_TO_POINT_NODE_H
