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

  private:
    bool is_dead = false;
};

#endif  // ACID_INCLUDE_DEATH_COMPONENT_H_
