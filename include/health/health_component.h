#ifndef ACID_INCLUDE_HEALTH_COMPONENT_H_
#define ACID_INCLUDE_HEALTH_COMPONENT_H_


#include <i_component.h>

class HealthComponent: public IComponent {
  public:
    HealthComponent(int _hp, int _max_hp): hp(_hp), max_hp(_max_hp) {}

    int get_hp() const {
        return hp;
    }

    void set_hp(int _hp) {
        this->hp = _hp;
        if (hp > max_hp) {
            hp = max_hp;
        }
        update();
    }

    int get_max_hp() {
        return max_hp;
    }

  private:
    int hp;
    int max_hp;
};

#endif  // ACID_INCLUDE_HEALTH_COMPONENT_H_
