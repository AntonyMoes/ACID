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
            auto death_comp = node->get_component<DeathComponent>();
            if (death_comp->get_state()) {
                delete_entity(death_comp->get_parent_id());
                std::cout << "Сдох" << std::endl;
            }
        }
    }
};

#endif   // ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_
