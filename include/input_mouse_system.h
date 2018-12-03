#ifndef ACID_INCLUDE_INPUT_MOUSE_SYSTEM_H_
#define ACID_INCLUDE_INPUT_MOUSE_SYSTEM_H_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <active_system.h>
#include <input_mouse_node.h>
#include <input_mouse_component.h>


class InputMouseSystem : public ActiveSystem<InputMouseNode> {
  public:
    explicit InputMouseSystem(const sf::Window* window) : window(window) {}
    void execute() final {
        static bool lmb_is_pressed = false;
        if (window->hasFocus()) {
            if (!lmb_is_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                lmb_is_pressed = true;

                auto mouse_pos_sf = sf::Mouse::getPosition(*window) -
                        sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2);
                b2Vec2 mouse_pos{static_cast<float32>(mouse_pos_sf.x),
                                 static_cast<float32>(mouse_pos_sf.y)};

                for (const auto &node : active_nodes) {
                    auto *comp = node->get_component<InputMouseComponent>();
                    comp->set_mouse_pos(mouse_pos);
                    std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;
                }
            } else if (lmb_is_pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                lmb_is_pressed = false;
            }
        }
    }

  private:
    const sf::Window* window;
};

#endif  // ACID_INCLUDE_INPUT_MOUSE_SYSTEM_H_
