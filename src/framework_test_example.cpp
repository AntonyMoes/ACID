#include <node.h>
#include <active_system.h>
#include <i_component.h>

#include <entity.h>
#include <game_loop.h>

#include <typeindex>
#include <iostream>
#include <framework/reactive_system.h>


class None {};

class FakeMoveComponent : public IComponent {
  public:
    std::string fake_move = "I honestly moved";
};

class FakeFartComponent : public IComponent {
  public:
    std::string fake_fart = "I honestly farted =======3   ";
};

class GeneratorSystem : public ActiveSystem<None>, public EntityLifeSystem {
  public:
    void execute() final {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 3) {
            i++;

            entity = new Entity();
            auto* comp1 = new FakeMoveComponent;
            entity->add_component(comp1);
            auto* comp2 = new FakeFartComponent;
            entity->add_component(comp2);

            create_entity(entity);
        }
    }
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
    void execute() final {
        for (const auto &node : active_nodes) {

            auto component = node->get_component<FakeMoveComponent>();
            if (component == nullptr) {
                std::cout << "Alexa, this is so sad" << std::endl;
                continue;
            }
            std::cout << component->fake_move << component->get_parent_id() <<std::endl;
        }
    }
};

class FakeFartSystem : public ActiveSystem<FakeFartNode> {
public:
    void execute() final {
        for (const auto &node : active_nodes) {
            auto component = node->get_component<FakeFartComponent>();
            if (component == nullptr) {
                std::cout << "Alexa, this is so sad" << std::endl;
                continue;
            }
            std::cout << component->fake_fart << component->get_parent_id() <<std::endl;
        }
    }
};

class FFakeFartSystem : public ReactiveSystem<FakeFartNode> {
public:
    void execute() final {
    }
};

class ShutDownSystem : public ActiveSystem<FakeMoveNode>, public TerminatorSystem, public EntityLifeSystem {
public:
    void execute() final {
        static int k = 0;

        if (k == 18) {
            for (const auto &node : active_nodes) {
                auto id = node->get_component<FakeMoveComponent>()->get_parent_id();
                delete_entity(id);
            }
        }

        if (k >= 18) {
            std::cout << "DELETED" << std::endl;
        }


        if (k == 20) {
            terminate();
        }
        
        k++;
    }
};


int main() {
    GameLoop iz_zapup;

    auto *node_prototype1 = new FakeMoveNode;
    iz_zapup.add_prototype(node_prototype1);

    auto *node_prototype2 = new FakeFartNode;
    iz_zapup.add_prototype(node_prototype2);

    auto *system1 = new GeneratorSystem;
    iz_zapup.register_life_system(system1);
    iz_zapup.add_system(system1);

    auto *system2 = new FakeMoveSystem;
    iz_zapup.add_system(system2);

    auto *system3 = new FakeFartSystem;
    iz_zapup.add_system(system3);

    auto *system4 = new FFakeFartSystem;
    iz_zapup.add_system(system4);

    auto *system5 = new ShutDownSystem;
    iz_zapup.register_term_system(system5);
    iz_zapup.register_life_system(system5);
    iz_zapup.add_system(system5);

    iz_zapup.run();
    return 0;
}