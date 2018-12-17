#ifndef ACID_INCLUDE_TEXTURE_COMPONENT_H_
#define ACID_INCLUDE_TEXTURE_COMPONENT_H_


#include <SFML/Graphics.hpp>

#include <i_component.h>

class TextureComponent: public IComponent {
  public:
    TextureComponent(sf::Sprite* sprite):
    sprite(sprite) {}

    ~TextureComponent() {
        delete sprite;
    };

    sf::Sprite& get_sprite() {
        return *sprite;
    }

  private:
    sf::Sprite* sprite = nullptr;
};

#endif  // ACID_INCLUDE_TEXTURE_COMPONENT_H_
