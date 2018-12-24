#ifndef A_C_I_D_HP_REGEN_COMPONENT_H
#define A_C_I_D_HP_REGEN_COMPONENT_H


#include <framework/i_component.h>

class HpRegenComponent : public IComponent {
  public:
    uint16_t get_hp_regen_rate() const {
        return hp_regen_rate;
    }

    uint16_t get_regen_rate_increase() const {
        return regen_rate_increase;
    }

    uint16_t get_hp_regen_lvl() const {
        return hp_regen_lvl;
    }

    void lvlup() {
        hp_regen_rate += regen_rate_increase;
        hp_regen_lvl++;
        update();
    }

  private:
    uint16_t hp_regen_rate = 5;
    uint16_t regen_rate_increase = 5;
    uint16_t hp_regen_lvl = 1;
};

#endif //A_C_I_D_HP_REGEN_COMPONENT_H
