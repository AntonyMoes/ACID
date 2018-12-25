#ifndef ACID_INCLUDE_SKILLS_INPUT_SKILL_COMPONENT_H_
#define ACID_INCLUDE_SKILLS_INPUT_SKILL_COMPONENT_H_


#include <map>

#include <SFML/Window/Keyboard.hpp>

#include <framework/i_component.h>


class InputSkillComponent : public IComponent {
public:
    InputSkillComponent() {
        keys.emplace(sf::Keyboard::F, false);
        keys.emplace(sf::Keyboard::K, false);
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

#endif  // ACID_INCLUDE_SKILLS_INPUT_SKILL_COMPONENT_H_
