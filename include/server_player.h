#ifndef ACID_INCLUDE_SERVER_PLAYER_H_
#define ACID_INCLUDE_SERVER_PLAYER_H_

#include <Box2D/Dynamics/b2Body.h>
#include <SFML/System.hpp>

#include <entity.h>
#include <single_world.h>
#include <collision_component.h>
#include <input_move_component.h>
#include <input_mouse_component.h>
#include <name_component.h>
#include <health_component.h>
#include <death_component.h>


class ServerPlayer : public Entity {
  public:
    explicit ServerPlayer(uint16_t id, float x, float y);
    explicit ServerPlayer(uint16_t id, b2Vec2 pos) : ServerPlayer(id, pos.x, pos.y) {}
    explicit ServerPlayer(uint16_t id, sf::Vector2f pos) : ServerPlayer(id, pos.x, pos.y) {}

  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};

#endif  // ACID_INCLUDE_SERVER_PLAYER_H_
