#ifndef ACID_INCLUDE_ANIMATION_COMPONENT_H_
#define ACID_INCLUDE_ANIMATION_COMPONENT_H_


#include <SFML/Graphics/Sprite.hpp>

#include <i_component.h>

class AnimationComponent: public IComponent {
  public:
    AnimationComponent(sf::Sprite* sprite, uint16_t time):
    sprite(sprite),
    animation_timer(time) {}

    ~AnimationComponent() {
        delete sprite;
    }

    sf::Sprite& get_sprite() {
        return *sprite;
    }

  private:
    sf::Sprite* sprite = nullptr;
    uint16_t animation_timer;
};

#endif  // ACID_INCLUDE_ANIMATION_COMPONENT_H_
