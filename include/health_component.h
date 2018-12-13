#ifndef ACID_INCLUDE_HEALTH_COMPONENT_H_
#define ACID_INCLUDE_HEALTH_COMPONENT_H_

#include <i_component.h>


class HealthComponent: public IComponent {
  public:
    explicit HealthComponent(int hp, int max_hp): hp(hp), max_hp(max_hp) {}

    int get_hp() const {
        return hp;
    }

    void set_hp(int hp) {
        this->hp = hp;
        if (hp > max_hp) {
            hp = max_hp;
        }
        update();
    }

  private:
    int hp;
    int max_hp;
};

#endif  // ACID_INCLUDE_HEALTH_COMPONENT_H_
