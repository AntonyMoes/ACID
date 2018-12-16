//
// Created by antonymo on 16.12.18.
//

#ifndef ACID_INCLUDE_MANA_MANA_COMPONENT_H_
#define ACID_INCLUDE_MANA_MANA_COMPONENT_H_


#include <framework/i_component.h>

class ManaComponent : public IComponent {
  public:
    explicit ManaComponent(uint16_t _max_mana, uint16_t _regen_rate = 1)
        : max_mana(_max_mana), regen_rate(_regen_rate) {}

    uint16_t get_mana() {
        return curr_mana;
    }

    uint16_t get_max_mana() {
        return max_mana;
    }

    void set_mana(uint16_t _mana) {
        curr_mana = _mana;
        update();
    }

    void set_max_mana(uint16_t _max_mana) {
        max_mana = _max_mana;
        update();
    }

    void set_regen_rate(uint16_t _regen) {
        regen_rate = _regen;
    }

  private:
    uint16_t max_mana;
    uint16_t curr_mana = max_mana;
    uint16_t regen_rate;

};

#endif  // ACID_INCLUDE_MANA_MANA_COMPONENT_H_
