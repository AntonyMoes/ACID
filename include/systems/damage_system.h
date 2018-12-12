#ifndef ACID_INCLUDE_DAMAGE_SYSTEM_H_
#define ACID_INCLUDE_DAMAGE_SYSTEM_H_


#include <reactive_system.h>
#include <damage_node.h>

class DamageSystem: public ReactiveSystem<DamageNode> {
  public:
    void execute() override {
        for (auto& node : reactive_nodes) {
            // Достаем из EntityManager то, с чем столкнулись, если у нее есть damage, отнимаем у health
        }
    }
};

#endif  // ACID_INCLUDE_DAMAGE_SYSTEM_H_
