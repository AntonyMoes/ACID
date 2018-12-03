#ifndef ACID_INCLUDE_SERVER_PLAYER_H_
#define ACID_INCLUDE_SERVER_PLAYER_H_


#include <framework/entity.h>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/System.hpp>
#include "single_world.h"
#include "collision_component.h"
#include "input_move_component.h"
#include "input_mouse_component.h"
#include <name_component.h>

class ServerPlayer : public Entity {
  public:
    ServerPlayer(uint16_t id, float x, float y) {
        b2BodyDef body_def;

        body_def.type = b2_dynamicBody;

        body_def.fixedRotation = true;
        body_def.position.Set(10.0f, 10.0f);

        auto world = SingleWorld::get_instance();
        b2Body* body = world->CreateBody(&body_def);

        b2PolygonShape shape;

        shape.SetAsBox(16.0f, 16.0f);

        body->CreateFixture(&shape, 1.0f);
        // Creating graph components
        auto* name_component = new NameComponent();
        name_component->set_network_id(id);
        auto* player_collision_component1 = new CollisionComponent(body);
        auto* input_move_component = new InputMoveComponent;
        auto* input_mouse_component = new InputMouseComponent;


        add_component(player_collision_component1);
        add_component(input_move_component);
        add_component(input_mouse_component);
        add_component(name_component);
    }
    explicit ServerPlayer(uint16_t id, b2Vec2 pos) : ServerPlayer(id, pos.x, pos.y) {}
    explicit ServerPlayer(uint16_t id, sf::Vector2f pos) : ServerPlayer(id, pos.x, pos.y) {}
};

#endif  // ACID_INCLUDE_SERVER_PLAYER_H_
