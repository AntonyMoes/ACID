#ifndef ACID_INCLUDE_SERVER_PLAYER_H_
#define ACID_INCLUDE_SERVER_PLAYER_H_


#include <Box2D/Dynamics/b2Body.h>
#include <SFML/System.hpp>

#include <entity.h>
#include <single_world.h>
#include <collision/collision_component.h>
#include <input_move_component.h>
#include <input_mouse_component.h>
#include <name_component.h>
#include <health_component.h>
#include <death_component.h>
#include <exp_component.h>
#include <ACID_math.h>

class ServerPlayer : public Entity {
  public:
    explicit ServerPlayer(uint16_t id, float x, float y, bool is_player);
    explicit ServerPlayer(uint16_t id, b2Vec2 pos, bool is_player) : ServerPlayer(id, pos.x, pos.y, is_player) {}
    explicit ServerPlayer(uint16_t id, sf::Vector2f pos, bool is_player) : ServerPlayer(id, pos.x, pos.y, is_player) {}

  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};

#endif  // ACID_INCLUDE_SERVER_PLAYER_H_
