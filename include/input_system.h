#ifndef ACID_INCLUDE_INPUT_SYSTEM_H_
#define ACID_INCLUDE_INPUT_SYSTEM_H_

#include <framework/active_system.h>
#include <input_node.h>
#include <SFML/Window/Keyboard.hpp>

class InputSystem : public ActiveSystem<InputNode> {
  public:
    void execute() const final {
        std::array<bool, 101> keyboard = {};
        size_t keys_count = 0;

        for (size_t i = sf::Keyboard::A; i <= sf::Keyboard::Pause; ++i) {
            keyboard[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i));

            if(keyboard[i]) {
                keys_count++;
            }
        }

        for (const auto &node : active_nodes) {
            auto component = node->get_component<InputComponent>();

            if (component->get_keys() != keyboard) {
                component->set_keys_and_count(keyboard, keys_count);
            }
        }
    }
};

#endif  // ACID_INCLUDE_INPUT_SYSTEM_H_
