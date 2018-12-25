#ifndef A_C_I_D_HP_REGEN_NODE_H
#define A_C_I_D_HP_REGEN_NODE_H


#include <framework/node.h>
#include "hp_regen_component.h"
#include "health_component.h"

class HpRegenNode : public Node<HpRegenNode> {
  public:
    HpRegenNode() {
        add_component<HpRegenComponent>();
        add_component<HealthComponent>();
    }
};

#endif //A_C_I_D_HP_REGEN_NODE_H
