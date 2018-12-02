#ifndef ACID_INCLUDE_HEALTH_COMPONENT_H_
#define ACID_INCLUDE_HEALTH_COMPONENT_H_


#include <i_component.h>

class HealthComponent: public IComponent {
  public:
    HealthComponent(int hp): hp(hp) {}

    int get_hp() const {
        return hp;
    }

    void set_hp(int hp) {
        this->hp = hp;
    }

  private:
    int hp;
};

#endif  // ACID_INCLUDE_HEALTH_COMPONENT_H_
