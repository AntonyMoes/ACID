#ifndef ACID_INCLUDE_DAMAGE_SYSTEM_H_
#define ACID_INCLUDE_DAMAGE_SYSTEM_H_


#include <entity_manager.h>
#include <reactive_system.h>
#include <damage_node.h>
#include <damage_component.h>

class DamageSystem: public ReactiveSystem<DamageNode> {
  public:
    explicit DamageSystem(EntityManager* e_manager):
    e_manager(e_manager) {}

    void execute() override {
        for (auto& node : reactive_nodes) {
            auto collision_comp = node->get_component<CollisionComponent>();
            auto health_comp = node->get_component<HealthComponent>();
            std::cout << "Меня стукнули\n";

            size_t collide_id = collision_comp->get_collide_id();
            auto collide_entity = e_manager->get_entity(collide_id);
            auto damage_comp = collide_entity->get_component<DamageComponent>();
            if (damage_comp) {
                auto hp = health_comp->get_hp();
                hp -= damage_comp->get_dmg();
                health_comp->set_hp(hp);
            }
        }
    }

    EntityManager* e_manager;
};

#endif  // ACID_INCLUDE_DAMAGE_SYSTEM_H_
