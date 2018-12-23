//
// Created by vladimir on 23.12.18.
//

#ifndef A_C_I_D_ENEMY_MOVEMENT_SYSTEM_H
#define A_C_I_D_ENEMY_MOVEMENT_SYSTEM_H

#include <node.h>
#include <enemy_component.h>
#include <name_component.h>
#include <collision_component.h>
#include <active_system.h>
#include <ACID_math.h>
#include <math.h>
#include <projectile.h>
#include <entity_life_system.h>
class EnemyMovementNode: public Node<EnemyMovementNode> {
  public:
    EnemyMovementNode() {
        add_component<NameComponent>();
        add_component<CollisionComponent>();
    }
};

class EnemyMoementSystem: public ActiveSystem<EnemyMovementNode>, public EntityLifeSystem {
  public:
    void execute() final {
        static int i = 0;
        i++;
        if (i == 81) {
            i = 0;
        }
        for (auto node : active_nodes) {
            if (!node->get_component<NameComponent>()->is_player()) {
                auto pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
                EnemyMovementNode* target = nullptr;
                for (auto player_node: active_nodes) {
                    if (player_node->get_component<NameComponent>()->is_player()) {
                        if (target) {
                            auto target_distance = b2Distance(pos, target->get_component<CollisionComponent>()->get_body()->GetPosition());
                            auto player_distance = b2Distance(pos, player_node->get_component<CollisionComponent>()->get_body()->GetPosition());
                            if (player_distance < target_distance) {
                                target = player_node;
                            }
                        } else {
                            target = player_node;
                        }
                    }
                }
                if (target) {
                    auto target_pos = target->get_component<CollisionComponent>()->get_body()->GetPosition();
                    float angle = 0;
                    if (target_pos.x > pos.x) {
                        angle = ACIDMath::get_angle_from_b2Vec(target_pos - pos);
                    } else {
                        angle = ACIDMath::get_angle_from_b2Vec(pos -target_pos) + 180;
                    }

                    auto direction = ACIDMath::get_b2Vec_from_angle(angle);
                    direction = b2Vec2(direction.x / SCALE, direction.y / SCALE);

                    if (i == 80) {
                        b2Vec2 real_pos(pos.x * SCALE + direction.x * 40 *SCALE, pos.y * SCALE + direction.y * SCALE * 40);
                        create_entity(new Projectile(real_pos, direction));
                    }
                    node->get_component<CollisionComponent>()->get_body()->SetTransform(pos + direction, 0);
                }
            }
        }
    }
};
#endif //A_C_I_D_ENEMY_MOVEMENT_SYSTEM_H
