#ifndef ACID_INCLUDE_FIREBALL_CREATION_SYSTEM_H_
#define ACID_INCLUDE_FIREBALL_CREATION_SYSTEM_H_

#include <reactive_system.h>
#include <entity_life_system.h>
#include <fireball_creation_node.h>
#include <projectile.h>


class FireballCreationSystem : public ReactiveSystem<FireballCreationNode>, public EntityLifeSystem {
  public:
    void execute() final {
        for (const auto &node : reactive_nodes) {
            auto pos = node->get_component<BodyComponent>()->get_body()->GetPosition();
            auto direction = node->get_component<InputMouseComponent>()->get_mouse_pos();

            ACIDMath::get_unit_b2Vec2(direction);
            b2Vec2 real_pos {pos.x + direction.x * 20, pos.y + direction.y * 20};
            create_entity(new Projectile(real_pos, direction));
        }
    }
};

#endif  // ACID_INCLUDE_FIREBALL_CREATION_SYSTEM_H_
