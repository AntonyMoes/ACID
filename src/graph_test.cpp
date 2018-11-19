#include <game_loop.h>
#include <graphic_system.h>
#include <input_system.h>
#include <camera_system.h>
#include <displayer_system.h>
#include <reactive_system.h>


class FakeRMovementSystem : public ReactiveSystem<InputNode> {
public:
    void execute() const final {
        for (auto &node : reactive_nodes) {
            auto component = node->get_component<InputComponent>();
            if (component->get_keys()[sf::Keyboard::W]) {
                std::cout << "Начал бежать вверх" << std::endl;
            } else {
                std::cout << "Больше не бегу" << std::endl;
            }
        }
    }
};

class FakeAMovementSystem : public ActiveSystem<InputNode> {
public:
    void execute() const final {
        for (auto &node : active_nodes) {
            auto component = node->get_component<InputComponent>();
            if (component->get_keys()[sf::Keyboard::W]) {
                std::cout << "БЕГУ ВВЕРХ" << std::endl;
            }
        }
    }
};

class GameEndSystem : public  ReactiveSystem<InputNode>, public TerminatorSystem {
public:
    void execute() const final {
        for (const auto &node : reactive_nodes) {
            auto* component = node->get_component<InputComponent>();

            if (component->get_keys()[sf::Keyboard::Escape]) {
                terminate();
            }
        }
    }
};

class GenSystem : public ActiveSystem<None>, public EntityLifeSystem {
  public:
    void execute() const override {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 1) {
            i++;

            entity = new Entity();

            // Creating drawable object
            sf::Texture texture;
            texture.loadFromFile("../textures/texture.jpg", sf::IntRect(0, 0, 32, 32));
            texture.setSmooth(true);
            texture.setRepeated(true);
            sf::Sprite* player_sprite = new sf::Sprite;
            player_sprite->setTexture(texture);

            sf::Vector2f player_coords(0.f, 0.f);

            // Creating graph components
            TextureComponent* player_texture_component = new TextureComponent(player_sprite);
            PositionComponent* player_pos_component = new PositionComponent;
            player_pos_component->set_coords(player_coords);

            entity->add_component(player_texture_component);
            entity->add_component(player_pos_component);

            create_entity(entity);
        }
    }
};


int main() {
    GameLoop gameloop;

    // Creating window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ACID");
    window.setFramerateLimit(60);

    //Creating camera
    CameraSystem camera;

    // Creating graph system
    GraphicSystem graph_system(&window, &camera);

    // Create displayer system
    DisplayerSystem displayer_system(&window);

    // Create terminator system
    GameEndSystem game_ender;

    gameloop.add_system(&camera);
    gameloop.add_system(&displayer_system);
    gameloop.add_system(&graph_system);
    gameloop.add_system(&game_ender);

    gameloop.run();

    return 0;
}