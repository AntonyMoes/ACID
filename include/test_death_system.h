#ifndef ACID_INCLUDE_TEST_DEATH_SYSTEM_H_
#define ACID_INCLUDE_TEST_DEATH_SYSTEM_H_


#include <framework/reactive_system.h>
#include <framework/entity_life_system.h>
#include "test_death_node.h"

class TestDeathSystem : public ReactiveSystem<TestDeathNode>, public EntityLifeSystem {
  public:
    void execute() const override {
        for (auto& node : reactive_nodes) {
            auto death_comp = node->get_component<DeathComponent>();
            if (death_comp->get_state() == true) {
                sf::Texture texture;
                if (!texture.loadFromFile("../textures/40x40.png", sf::IntRect(0, 0, 32, 32))) {
                    throw std::bad_typeid();
                }

                auto texture_comp = node->get_component<TextureComponent>();
                auto sprite = texture_comp->get_sprite();
                sprite.setTexture(texture);
            }

            // TODO(AntonyMoes): 1) Add system, that changes death component
            //                   2) Change Texture or delete entity RANDOMLY

        }
    }
};

#endif  // ACID_INCLUDE_TEST_DEATH_SYSTEM_H_
