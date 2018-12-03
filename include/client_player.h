#ifndef ACID_INCLUDE_CLIENT_PLAYER_H_
#define ACID_INCLUDE_CLIENT_PLAYER_H_

#include <entity.h>
#include <position_component.h>
#include <texture_component.h>


class ClientPlayer: public Entity {
  public:
    explicit ClientPlayer(uint16_t id, float x, float y);
    explicit ClientPlayer(uint16_t id, b2Vec2 pos) : ClientPlayer(id, pos.x, pos.y) {}
    explicit ClientPlayer(uint16_t id, sf::Vector2f pos) : ClientPlayer(id, pos.x, pos.y) {}

  private:
    sf::Vector2f sizes = {32.0f, 32.0f};
};

#endif  // ACID_INCLUDE_CLIENT_PLAYER_H_
