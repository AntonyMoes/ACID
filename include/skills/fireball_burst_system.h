//
// Created by antonymo on 16.12.18.
//

#ifndef ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_
#define ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_


#include <framework/reactive_system.h>
#include <framework/entity_life_system.h>
#include <ACID_math.h>
#include <projectile.h>
#include <mana/mana_component.h>
#include "skill_node.h"

static uint16_t mana_needed = 10;

class FireballBurstSystem : public ReactiveSystem<SkillNode>, public EntityLifeSystem {
  public:
    void execute() override {
        for(auto &node : reactive_nodes) {
            auto input = node->get_component<InputSkillComponent>();
            if (input->get_keys()->at(sf::Keyboard::F)) {
                auto mana_comp = node->get_component<ManaComponent>();
                auto mana = mana_comp->get_mana();
                if (mana >= mana_needed) {
                    mana -= mana_needed;
                    mana_comp->set_mana(mana);

                    auto pos = node->get_component<BodyComponent>()->get_body()->GetPosition();

                    for (int ang = 0; ang < 360; ang += 10) {
                        auto direction = ACIDMath::get_b2Vec_from_angle(ang);

                        b2Vec2 real_pos{pos.x + direction.x * 30, pos.y + direction.y * 30};
                        create_entity(new Projectile(real_pos, direction));
                    }
                }
            }
        }
    }
};

#endif  // ACID_INCLUDE_SKILLS_FIREBALL_BURST_SYSTEM_H_
