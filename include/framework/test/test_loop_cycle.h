#ifndef ACID_INCLUDE_TEST_LOOP_CYCLE_H_
#define ACID_INCLUDE_TEST_LOOP_CYCLE_H_


#include <gtest/gtest.h>

#include <game_loop.h>
#include <active_system.h>

class None {};

class FakeComponent : public IComponent {
  public:
    std::string fake = "FakeComponent";
};

class FakeNode : public Node<FakeNode> {
  public:
    FakeNode() : Node() {
        add_component<FakeComponent>();
    }
};

class EntityGeneratorSystem : public ActiveSystem<FakeNode> {
  public:
    void execute() const final {
        for (const auto &node : active_nodes) {
            auto id = std::type_index(typeid(FakeNode)).hash_code();

            auto component = node->get_component<FakeComponent>();
            if (component != nullptr) {
                auto true_component = dynamic_cast<FakeComponent *>(component);
                std::cout << true_component->fake << true_component->get_parent_id() << std::endl;
            }
        }
    }
};

class TestGameLoop: public GameLoop {
  public:
    TestGameLoop(): GameLoop() {}
    void run() {
        std::cout << "ЖОПА\n";
        cycle();
    }
};

class SetupLoopCycle: public ::testing::Test {
  protected:
    void SetUp() final {
        gm = new TestGameLoop;
        system = new EntityGeneratorSystem;
        node = new FakeNode;
        comp = new FakeComponent;
        gm->add_prototype(node);
        gm->add_system(system);
    }

    void TearDown() final {
        delete gm;
    }

    TestGameLoop* gm;
    EntityGeneratorSystem* system;
    FakeNode* node;
    FakeComponent* comp;
};

#endif  // ACID_INCLUDE_TEST_LOOP_CYCLE_H_

// Одна активная система, которая добавляет Entity, одну, которая меняет значения в компонентах,
// реактивную систему, которая смотрит на значения в компонентах и меняет в зависимости от этих значений
// другие компоненты. Активная система для проверки значений.