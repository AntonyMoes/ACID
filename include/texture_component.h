#ifndef ACID_INCLUDE_TEXTURE_COMPONENT_H_
#define ACID_INCLUDE_TEXTURE_COMPONENT_H_


#include <SFML/Graphics.hpp>

#include <i_component.h>

class TextureComponent: public IComponent {
  public:
    TextureComponent() = default;
    ~TextureComponent() = default;

  private:
    sf::Texture* texture = nullptr;
};

#endif  // ACID_INCLUDE_TEXTURE_COMPONENT_H_
