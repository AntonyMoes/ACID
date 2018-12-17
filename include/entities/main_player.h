#ifndef ACID_INCLUDE_MAIN_PLAYER_H_
#define ACID_INCLUDE_MAIN_PLAYER_H_


#include <typeinfo>

#include <entity.h>
#include <single_world.h>
#include <texture_manager.h>
#include <camera_component.h>
#include <position_component.h>
#include <texture_component.h>
#include <input_mouse_component.h>
#include <input_move_component.h>
#include <name_component.h>
#include <collision_component.h>
#include <mana_component.h>
#include <health_component.h>
#include <death_component.h>

class MainPlayer: public Entity {
  public:
    explicit MainPlayer(uint16_t id, float x, float y);
    explicit MainPlayer(uint16_t id, b2Vec2 pos) : MainPlayer(id, pos.x, pos.y) {}
    explicit MainPlayer(uint16_t id, sf::Vector2f pos) : MainPlayer(id, pos.x, pos.y) {}

  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};

#endif  // ACID_INCLUDE_MAIN_PLAYER_H_
