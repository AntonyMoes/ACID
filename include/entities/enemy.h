//
// Created by vladimir on 23.12.18.
//

#ifndef A_C_I_D_ENEMY_H
#define A_C_I_D_ENEMY_H

#include <Box2D/Dynamics/b2Body.h>
#include <SFML/System.hpp>

#include <entity.h>
#include <single_world.h>
#include <collision/collision_component.h>
#include <input_move_component.h>
#include <health_component.h>
#include <death_component.h>
#include <exp_component.h>

class Enemy : public Entity {
 public:
    explicit Enemy(float x, float y) {
        b2BodyDef body_def;

        body_def.type = b2_dynamicBody;

        body_def.fixedRotation = true;
        body_def.position.Set(x, y);

        auto world = SingleWorld::get_instance();
        b2Body* body = world->CreateBody(&body_def);

        b2PolygonShape shape;

        shape.SetAsBox(sizes.x / 2, sizes.y / 2);

        body->CreateFixture(&shape, 1.0f);
        // Creating graph components
        auto* player_collision_component = new CollisionComponent(body);
        body->SetUserData(player_collision_component);
        auto* health_component = new HealthComponent(100, 100);

        auto death_component = new DeathComponent;
        auto exp_component = new ExpComponent(20, 10, 2.0f, 2.0f);

        add_component(player_collision_component);
        add_component(health_component);
        add_component(death_component);
        add_component(exp_component);
    }
  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};
#endif //A_C_I_D_ENEMY_H
