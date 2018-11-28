#ifndef ACID_INCLUDE_TEST_TOGGLE_DEATH_SYSTEM_H_
#define ACID_INCLUDE_TEST_TOGGLE_DEATH_SYSTEM_H_


#include <framework/active_system.h>
#include "test_death_node.h"

class TestToggleDeathSystem : public ActiveSystem<TestDeathNode> {
  public:
    void execute() const override {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
            for (auto &node : active_nodes) {
                node->get_component<DeathComponent>()->set_state(true);
                std::cout << "F" << std::endl;
            }
        }
    }
};

#endif  // ACID_INCLUDE_TEST_TOGGLE_DEATH_SYSTEM_H_
