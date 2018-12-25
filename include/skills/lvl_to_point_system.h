//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_LVL_TO_POINT_SYSTEM_H
#define A_C_I_D_LVL_TO_POINT_SYSTEM_H


#include <framework/active_system.h>
#include "lvl_to_point_node.h"

class LvlToPointSystem : public ActiveSystem<LvlToPointNode> {
  public:
    void execute() override {
        static uint16_t tick = 20;

        if(--tick) {
            return;
        }

        tick = 20;


        auto node = *active_nodes.begin();
        if (!node) {
            return;
        }

        auto skill_comp = node->get_component<SkillComponent>();
        auto exp_comp = node->get_component<ExpComponent>();

        if (exp_comp->get_level() > skill_comp->get_max_skill_points()) {
            for (int i = skill_comp->get_max_skill_points(); i <exp_comp->get_level(); i++) {
                skill_comp->add_skill_point();
            }
        }
    }
};

#endif //A_C_I_D_LVL_TO_POINT_SYSTEM_H
