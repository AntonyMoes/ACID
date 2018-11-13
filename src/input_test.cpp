#include <SFML/Window/Keyboard.hpp>

#include <framework/reactive_system.h>
#include <input_node.h>
#include <framework/game_loop.h>
#include <input_system.h>

class FakeMovementSystem : public ReactiveSystem<InputNode> {
  public:
    void execute() const final {
        for (auto &node : reactive_nodes) {
            auto component = node->get_component<InputComponent>();
            if (component->get_keys()[sf::Keyboard::W]) {
                std::cout << "БЕГУ ВВЕРХ" << std::endl;
            }
        }
    }
};


class None{};

class GenSystem : public virtual ActiveSystem<None>, public virtual EntityLifeSystem<None> {
public:
    void execute() const final {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 3) {
            i++;

            entity = new Entity();
            auto* comp1 = new InputComponent;
            entity->add_component(comp1);

            create_entity(entity);
        }
    }

};

int main() {
    std::cout << sf::Keyboard::Key::Pause - sf::Keyboard::Key::A + 1<< std::endl;


    GameLoop loop;

    auto* node_prototype1 = new InputNode;
    loop.add_prototype(node_prototype1);

    auto* system1 = new GenSystem;
    system1->set_queue(loop.get_queue_ref());

    auto* system2 = new InputSystem;
    loop.add_system(system2);

    auto* system3 = new FakeMovementSystem;
    loop.add_system(system3);

    loop.run();
    return 0;
}

