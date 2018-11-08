#include <node.h>
#include <active_system.h>
#include <i_component.h>
#include <entity.h>
#include <game_loop.h>

#include <typeindex>
#include <iostream>

class FakeMoveComponent : public IComponent {
  public:
    std::string fake_move = "I honestly moved";
};

class GeneratorSystem : public ActiveSystem<void> {
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
        add_component<FakeMoveComponent>();
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

    /*auto *node_prototype = new FakeMoveNode;
    auto* node = reinterpret_cast<INode*>(node_prototype);
    iz_zapup.add_prototype(node);

    auto *system1 = new GeneratorSystem;
    system1->set_queue(iz_zapup.get_queue_ref());
    auto *Tsystem1 = reinterpret_cast<BaseSystem*>(system1);
    iz_zapup.add_system(Tsystem1);
    auto *system2 = new FakeMoveSystem;
    auto *Tsystem2 = reinterpret_cast<BaseSystem*>(system2);
    iz_zapup.add_system(Tsystem2);

    iz_zapup.run();*/
    return 0;
}