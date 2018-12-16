#ifndef ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_
#define ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_


#include <reactive_system.h>
#include <entity_death_node.h>
#include <entity_life_system.h>
#include <single_world.h>

class EntityDeathSystem: public ReactiveSystem<EntityDeathNode>, public EntityLifeSystem {
  public:
    void execute() override {
        for (auto& node : reactive_nodes) {
            auto health_comp = node->get_component<HealthComponent>();
            if (health_comp->get_hp() <= 0) {
                std::cout << "подох" << std::endl;
                delete_entity(health_comp->get_parent_id());
            }
        }
    }
};

#endif   // ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_
