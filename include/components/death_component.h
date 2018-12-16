#ifndef ACID_INCLUDE_DEATH_COMPONENT_H_
#define ACID_INCLUDE_DEATH_COMPONENT_H_


#include <i_component.h>

class DeathComponent: public IComponent {
  public:
    bool get_state() {
        return is_dead;
    }

    void set_state(bool _state) {
        is_dead = _state;
        update();
    }

    void set_killer_id(uint16_t killer) {
        killer_id = killer;
    }

    uint16_t get_killer_id() const {
        return killer_id;
    }

  private:
    bool is_dead = false;
    uint16_t killer_id = 0;
};

#endif  // ACID_INCLUDE_DEATH_COMPONENT_H_
