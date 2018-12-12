#ifndef ACID_INCLUDE_DAMAGE_SYSTEM_H_
#define ACID_INCLUDE_DAMAGE_SYSTEM_H_

#include <entity_manager.h>
#include <reactive_system.h>
#include <damage_node.h>

class DamageSystem: public ReactiveSystem<DamageNode> {
  public:
    explicit DamageSystem(EntityManager* e_manager):
    e_manager(e_manager) {}

    void execute() override {
        for (auto& node : reactive_nodes) {
            // Достаем из EntityManager то, с чем столкнулись, если у нее есть damage, отнимаем у health
        }
    }

    EntityManager* e_manager;
};

#endif  // ACID_INCLUDE_DAMAGE_SYSTEM_H_
