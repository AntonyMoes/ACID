//
// Created by vladimir on 23.12.18.
//

#ifndef A_C_I_D_ENEMY_COMPONENT_H
#define A_C_I_D_ENEMY_COMPONENT_H

#include <iostream>
#include <SFML/System.hpp>

#include <i_component.h>

class EnemyComponent: public IComponent {
  public:
    EnemyComponent(bool _is_static = true) : static_e(_is_static) {}
    const bool is_static() {
        return static_e;
    }
  private:
    const bool static_e;
};

#endif //A_C_I_D_ENEMY_COMPONENT_H
