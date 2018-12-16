//
// Created by antonymo on 16.12.18.
//

#ifndef ACID_INCLUDE_SKILLS_INPUT_SKILL_SYSTEM_H_
#define ACID_INCLUDE_SKILLS_INPUT_SKILL_SYSTEM_H_


#include <framework/active_system.h>
#include "input_skill_node.h"

class InputSkillSystem: public ActiveSystem<InputSkillNode> {
public:
    void execute() override {
        for (const auto& node : active_nodes) {
            auto component = node->get_component<InputSkillComponent>();
            auto keys = component->get_keys();
            (*keys)[sf::Keyboard::F] = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
            component->set_keys();
        }
    }
};

#endif  // ACID_INCLUDE_SKILLS_INPUT_SKILL_SYSTEM_H_
