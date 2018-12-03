#ifndef ACID_INCLUDE_MAIN_PLAYER_H_
#define ACID_INCLUDE_MAIN_PLAYER_H_

#include <entity.h>
#include <camera_component.h>
#include <position_component.h>
#include <texture_component.h>
#include <input_mouse_component.h>
#include <input_move_component.h>


class MainPlayer: public Entity {
  public:
    explicit MainPlayer(uint16_t id, sf::Vector2f pos);

  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};

#endif  // ACID_INCLUDE_MAIN_PLAYER_H_
