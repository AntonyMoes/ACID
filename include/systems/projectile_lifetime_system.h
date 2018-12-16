#ifndef ACID_INCLUDE_PROJECTILE_LIFETIME_SYSTEM_H_
#define ACID_INCLUDE_PROJECTILE_LIFETIME_SYSTEM_H_


#include <active_system.h>
#include <projectile_lifetime_node.h>

class ProjectileLifetimeSystem: public ActiveSystem<ProjectileLifetimeNode> {
  public:
    void execute() override {
        for (auto& node : active_nodes) {
            auto collision_comp = node->get_component<CollisionComponent>();
            if (collision_comp->is_collide()) {
                auto death_comp = node->get_component<DeathComponent>();
                death_comp->set_state(true);
                return;
            }
            auto lifetime_comp = node->get_component<LifetimeComponent>();
            if (!lifetime_comp->is_alive()) {
                auto death_comp = node->get_component<DeathComponent>();
                death_comp->set_state(true);
                return;
            }
        }
    }
};

#endif  // ACID_INCLUDE_PROJECTILE_LIFETIME_SYSTEM_H_
