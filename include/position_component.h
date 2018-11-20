#ifndef ACID_INCLUDE_POSITION_COMPONENT_H_
#define ACID_INCLUDE_POSITION_COMPONENT_H_


#include <iostream>


#include <i_component.h>
#include <SFML/System.hpp>


class PositionComponent: public IComponent {
  public:
    sf::Vector2f& get_coords() {
        return coordinate;
    }

    void set_coords(sf::Vector2f& coords) {
        coordinate = coords;
        /*
        std::cout << "x: " << coords.x << " y: " << coords.y << std::endl;
        std::cout << "UBDATE" << std::endl;
        std::cout << "x: " << coordinate.x << " y: " << coordinate.y << std::endl;
         */
        update();
    }

  private:
    sf::Vector2f coordinate;
};

#endif  // ACID_INCLUDE_POSITION_COMPONENT_H_
