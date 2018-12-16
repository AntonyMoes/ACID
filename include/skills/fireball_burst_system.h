//
// Created by antonymo on 16.12.18.
//

#ifndef ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_
#define ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_


#include <framework/reactive_system.h>
#include <framework/entity_life_system.h>
#include "skill_node.h"

class FireballBurstSystem : public ReactiveSystem<SkillNode>, public EntityLifeSystem {
  public:
    void execute() override {
        for(auto &node : reactive_nodes) {

            /*
            auto pos = node->get_component<BodyComponent>()->get_body()->GetPosition();
            auto direction = node->get_component<InputMouseComponent>()->get_mouse_pos();

            ACIDMath::get_unit_b2Vec2(direction);

            b2Vec2 real_pos {pos.x + direction.x * 30, pos.y + direction.y * 30};
            create_entity(new Projectile(real_pos, direction));
             */
        }
    }
};

#endif  // ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_
