#ifndef A_C_I_D_SKILL_LVLUP_NODE_H
#define A_C_I_D_SKILL_LVLUP_NODE_H


#include <framework/node.h>
#include <mana/mana_component.h>
#include <health/hp_regen_component.h>
#include <exp/exp_component.h>
#include "skill_component.h"
#include "input_skill_component.h"

class SkillLvlupNode : public Node<SkillLvlupNode> {
  public:
    SkillLvlupNode() {
        add_component<SkillComponent>();
        add_component<ManaComponent>();
        add_component<HpRegenComponent>();
        add_component<InputSkillComponent>();
        add_component<ExpComponent>();
    }
};

#endif //A_C_I_D_SKILL_LVLUP_NODE_H
