#ifndef ACID_INCLUDE_MANA_MANA_REGEN_SYSTEM_H_
#define ACID_INCLUDE_MANA_MANA_REGEN_SYSTEM_H_


#include <active_system.h>
#include <mana_node.h>

class ManaRegenSystem : public ActiveSystem<ManaNode> {
  public:
    ManaRegenSystem() = default;

    void execute() override {
        static uint16_t tick = 60;

        if(--tick) {
            return;
        }

        tick = 60;

        for (auto &node : active_nodes) {
            auto mana_component = node->get_component<ManaComponent>();
            auto mana = mana_component->get_mana();
            auto max_mana = mana_component->get_max_mana();

            if (mana != max_mana) {
                auto regen_rate = mana_component->get_regen_rate();
                mana += regen_rate;

                if (mana > max_mana) {
                    mana = max_mana;
                }

                mana_component->set_mana(mana);
            }
        }
    }
};

#endif  // ACID_INCLUDE_MANA_MANA_REGEN_SYSTEM_H_
