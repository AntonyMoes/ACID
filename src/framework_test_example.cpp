#include <node.h>
#include <active_system.h>
#include <i_component.h>

#include <entity.h>
#include <game_loop.h>

#include <typeindex>
#include <iostream>
class None {};

class FakeMoveComponent : public IComponent {
  public:
    std::string fake_move = "I honestly moved";
};

class GeneratorSystem : public ActiveSystem<None> {
  public:
    void execute() const final {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 1) {
            i++;

            entity = new Entity();
            auto* comp = new FakeMoveComponent;
            entity->add_component(comp);

            queue->add_entity(entity);
        }
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;

};

class FakeMoveNode : public Node<FakeMoveNode> {
  public:
    FakeMoveNode() : Node() {
        /*Node<FakeMoveNode>::*/add_component<FakeMoveComponent>();
    }
};

class FakeMoveSystem : public ActiveSystem<FakeMoveNode> {
  public:
    void execute() const final {
        for (const auto &node : active_nodes) {
            auto id = std::type_index(typeid(FakeMoveNode)).hash_code();

            auto component = node->get_component(id);
            if (component == nullptr) {
                std::cout << "Alexa, this is so sad" << std::endl;
                continue;
            }

            auto true_component = dynamic_cast<FakeMoveComponent*>(component);
            std::cout << true_component->fake_move << std::endl;
        }
    }
};



int main() {
    GameLoop iz_zapup;

    auto *node_prototype = new FakeMoveNode;
    iz_zapup.add_prototype(node_prototype);


    auto *system1 = new GeneratorSystem;
    system1->set_queue(iz_zapup.get_queue_ref());
    iz_zapup.add_system(system1);


    auto *system2 = new FakeMoveSystem;
    iz_zapup.add_system(system2);

    iz_zapup.run();
    return 0;
}