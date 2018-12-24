//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_HP_REGEN_SYSTEM_H
#define A_C_I_D_HP_REGEN_SYSTEM_H


#include <framework/active_system.h>
#include "hp_regen_node.h"

class HpRegenSystem : public ActiveSystem<HpRegenNode> {
public:
    HpRegenSystem() = default;

    void execute() override {
        static uint16_t tick = 60;

        if(--tick) {
            return;
        }

        tick = 60;

        for (auto &node : active_nodes) {
            auto hp_component = node->get_component<HealthComponent>();
            auto hp_regen_component = node->get_component<HpRegenComponent>();
            auto hp = hp_component->get_hp();
            auto max_hp = hp_component->get_max_hp();

            if (hp != max_hp) {
                auto regen = hp_regen_component->get_hp_regen_rate();
                hp += regen;

                if (hp > max_hp) {
                    hp = max_hp;
                }

                hp_component->set_hp(hp);
            }
        }
    }
};

#endif //A_C_I_D_HP_REGEN_SYSTEM_H
