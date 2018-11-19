#ifndef ACID_INCLUDE_INPUT_MOVE_SYSTEM_H_
#define ACID_INCLUDE_INPUT_MOVE_SYSTEM_H_


#include <active_system.h>
#include <input_move_node.h>

class InputMoveSystem: public ActiveSystem<InputMoveNode> {
  public:
    void execute() const override {
        for (const auto& node : active_nodes) {
            auto component = node->get_component<InputMoveComponent>();
            auto keys = component->get_keys();

            keys[sf::Keyboard::W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            keys[sf::Keyboard::A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            keys[sf::Keyboard::S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            keys[sf::Keyboard::D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        }
    }
};

#endif  // ACID_INCLUDE_INPUT_MOVE_SYSTEM_H_
