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
            // HARDCODE, BUT IT'S OK FOR NOW
            bool is_active = keys->at(sf::Keyboard::F);
            bool is_active_now = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
            (*keys)[sf::Keyboard::F] = is_active_now;

            if (!is_active && is_active_now) {
                component->set_keys();
            }
        }
    }
};

#endif  // ACID_INCLUDE_SKILLS_INPUT_SKILL_SYSTEM_H_
