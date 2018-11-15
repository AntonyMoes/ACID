#include <SFML/Window/Keyboard.hpp>

#include <framework/reactive_system.h>
#include <input_node.h>
#include <framework/game_loop.h>
#include <input_system.h>

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
class None{};

class GenSystem : public ActiveSystem<None>, public EntityLifeSystem {
public:
    void execute() const final {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 1) {
            i++;

            entity = new Entity();
            auto* comp1 = new InputComponent;
            entity->add_component(comp1);

            create_entity(entity);
        }
    }

};

int main() {
    GameLoop loop;

    auto* node_prototype1 = new InputNode;
    loop.add_prototype(node_prototype1);

    auto* system1 = new GenSystem;
    loop.register_life_system(system1);
    loop.add_system(system1);

    auto* system2 = new InputSystem;
    loop.add_system(system2);

    auto* system31 = new FakeRMovementSystem;
    loop.add_system(system31);

    auto* system32 = new FakeAMovementSystem;
    loop.add_system(system32);

    auto* system4 = new GameEndSystem;
    loop.register_term_system(system4);
    loop.add_system(system4);

    loop.run();
    return 0;
}

