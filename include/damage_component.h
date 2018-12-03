#ifndef ACID_INCLUDE_DAMAGE_COMPONENT_H_
#define ACID_INCLUDE_DAMAGE_COMPONENT_H_

#include <i_component.h>


class DamageComponent: public IComponent {
  public:
    explicit DamageComponent(int dmg): dmg(dmg) {}

    int get_dmg() {
        return dmg;
    }

    void set_dmg() {
        this->dmg = dmg;
    }

  private:
    int dmg;
};

#endif  // ACID_INCLUDE_DAMAGE_COMPONENT_H_
