#ifndef ACID_INCLUDE_TEST_DEATH_SYSTEM_H_
#define ACID_INCLUDE_TEST_DEATH_SYSTEM_H_


#include <framework/reactive_system.h>
#include <framework/entity_life_system.h>
#include "test_death_node.h"

class TestDeathSystem : public ReactiveSystem<TestDeathNode>, public EntityLifeSystem {
  public:
    void execute() override {
        for (auto& node : reactive_nodes) {
            auto death_comp = node->get_component<DeathComponent>();
            if (death_comp->get_state() == true) {
                std::cout << "TRULY F" << std::endl;
                //sf::Texture texture;
                //if (!texture.loadFromFile("../textures/40x40.png", sf::IntRect(0, 0, 32, 32))) {
                //    throw std::bad_typeid();
                //}

                //auto texture_comp = node->get_component<TextureComponent>();
                //auto sprite = texture_comp->get_sprite();
                //sprite.setTexture(texture);

                delete_entity(death_comp->get_parent_id());


                sf::Texture texture;
                if (!texture.loadFromFile("../textures/40x40.png", sf::IntRect(0, 0, 40, 40))) {
                    throw std::bad_typeid();
                }

                auto* player_sprite = new sf::Sprite;
                player_sprite->setTexture(texture);

                auto* entity = new Entity;
                auto* texture_comp = new TextureComponent(player_sprite);
                auto* camera_comp = new CameraComponent;
                sf::Vector2f pos = {0,0};
                auto* position_comp = new PositionComponent(pos);

                entity->add_component(texture_comp);
                entity->add_component(camera_comp);
                entity->add_component(position_comp);
                create_entity(entity);

                death_comp->set_state(false);
            }

            // TODO(AntonyMoes): 1) Add system, that changes death component    DONE
            //                   2) Change Texture or delete entity RANDOMLY

        }
    }
};

#endif  // ACID_INCLUDE_TEST_DEATH_SYSTEM_H_
