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

class FakeFartComponent : public IComponent {
  public:
    std::string fake_fart = "I honestly farted =======3   ";
};

class GeneratorSystem : public ActiveSystem<None> {
  public:
    void execute() const final {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 3) {
            i++;

            entity = new Entity();
            auto* comp1 = new FakeMoveComponent;
            std::cout << "h1 = " << typeid(*comp1).hash_code() << std::endl;
            entity->add_component(comp1);
            std::cout << "h2 = " << typeid(FakeMoveComponent).hash_code() << std::endl;
            auto* comp2 = new FakeFartComponent;
            std::cout << "h1 = " << typeid(*comp2).hash_code() << std::endl;
            entity->add_component(comp2);
            std::cout << "h2 = " << typeid(FakeFartComponent).hash_code() << std::endl;

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

class FakeFartNode : public Node<FakeFartNode> {
public:
    FakeFartNode() : Node() {
        add_component<FakeFartComponent>();
    }
};

class FakeMoveSystem : public ActiveSystem<FakeMoveNode> {
  public:
    void execute() const final {
        for (const auto &node : active_nodes) {
            auto id = std::type_index(typeid(FakeMoveNode)).hash_code();

            auto component = node->get_component<FakeMoveComponent>();
            if (component == nullptr) {
                std::cout << "Alexa, this is so sad" << std::endl;
                continue;
            }

            auto true_component = dynamic_cast<FakeMoveComponent*>(component);
            std::cout << true_component->fake_move << true_component->get_parent_id() <<std::endl;
        }
    }
};

class FakeFartSystem : public ActiveSystem<FakeFartNode> {
public:
    void execute() const final {
        for (const auto &node : active_nodes) {
            auto component = node->get_component<FakeFartComponent>();
            if (component == nullptr) {
                std::cout << "Alexa, this is so sad" << std::endl;
                continue;
            }

            auto true_component = dynamic_cast<FakeFartComponent*>(component);
            std::cout << true_component->fake_fart << true_component->get_parent_id() <<std::endl;
        }
    }
};




int main() {
    GameLoop iz_zapup;

    auto *node_prototype1 = new FakeMoveNode;
    iz_zapup.add_prototype(node_prototype1);

    auto *node_prototype2 = new FakeFartNode;
    iz_zapup.add_prototype(node_prototype2);

    auto *system1 = new GeneratorSystem;
    system1->set_queue(iz_zapup.get_queue_ref());
    iz_zapup.add_system(system1);

    auto *system2 = new FakeMoveSystem;
    iz_zapup.add_system(system2);

    auto *system3 = new FakeFartSystem;
    iz_zapup.add_system(system3);

    iz_zapup.run();
    return 0;
}