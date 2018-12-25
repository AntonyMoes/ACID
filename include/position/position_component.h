#ifndef ACID_INCLUDE_POSITION_COMPONENT_H_
#define ACID_INCLUDE_POSITION_COMPONENT_H_


#include <iostream>
#include <SFML/System.hpp>

#include <i_component.h>

class PositionComponent: public IComponent {
  public:
    PositionComponent() = default;

    explicit PositionComponent(sf::Vector2f coords) :
        coordinate(coords) {
    }

    sf::Vector2f& get_coords() {
        return coordinate;
    }

    void set_coords(sf::Vector2f& coords) {
        coordinate = coords;
        update();
    }

  private:
    sf::Vector2f coordinate;
};

#endif  // ACID_INCLUDE_POSITION_COMPONENT_H_
