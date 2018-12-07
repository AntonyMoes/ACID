#ifndef ACID_INCLUDE_INPUT_MOVE_COMPONENT_H_
#define ACID_INCLUDE_INPUT_MOVE_COMPONENT_H_

#include <map>
#include <SFML/Window/Keyboard.hpp>

#include <i_component.h>

class InputMoveComponent: public IComponent {
  public:
    InputMoveComponent() {
        keys.emplace(sf::Keyboard::W, false);
        keys.emplace(sf::Keyboard::A, false);
        keys.emplace(sf::Keyboard::S, false);
        keys.emplace(sf::Keyboard::D, false);
    }

    std::map<sf::Keyboard::Key, bool>* get_keys() {  // TODO: REWOOOOOOOOOOOOOOOOOOOOOOORK
        return &keys;
    }

    void set_keys() {
        update();
    }

  private:
    std::map<sf::Keyboard::Key, bool> keys;
};

#endif  // ACID_INCLUDE_INPUT_MOVE_COMPONENT_H_
