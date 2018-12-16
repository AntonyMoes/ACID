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
            auto damage_comp = node->get_component<DamageComponent>();

            uint16_t collide_id = collision_comp->get_collide_id();
            auto collide_entity = e_manager->get_entity(collide_id);
            if (collide_entity) {
                auto health_comp = collide_entity->get_component<HealthComponent>();
                if (health_comp) {
                    auto hp = health_comp->get_hp();
                    hp -= damage_comp->get_dmg();
                    health_comp->set_hp(hp);
                    if (hp <= 0) {
                        auto death_comp = collide_entity->get_component<DeathComponent>();
                        if (death_comp) {
                            death_comp->set_state(true);
                        }
                    }
                    std::cout << "hp: " << hp << std::endl;
                }
            }
        }
    }

    EntityManager* e_manager;
};

#endif  // ACID_INCLUDE_DAMAGE_SYSTEM_H_
