//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_SERVER_LVLUP_SYNC_NODE_H
#define A_C_I_D_SERVER_LVLUP_SYNC_NODE_H

#include <framework/node.h>
#include <mana/mana_component.h>
#include <health/hp_regen_component.h>
#include <exp/exp_component.h>
#include <entities/name_component.h>
#include "skill_component.h"

class ServerSkillLvlupNode : public Node<ServerSkillLvlupNode> {
public:
    ServerSkillLvlupNode() {
        add_component<SkillComponent>();
        add_component<ManaComponent>();
        add_component<HpRegenComponent>();
        add_component<ExpComponent>();
        add_component<NameComponent>();
    }
};

#endif //A_C_I_D_SERVER_LVLUP_SYNC_NODE_H
