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
        Entity* entity = new Entity();
        auto* comp1 = new FakeComponent;
        entity->add_component(comp1);

        queue->add_entity(entity);
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;
};

class EntityEditorSystem : public ActiveSystem<FakeNode> {
  public:
    void execute() const final {
        for (const auto& node: active_nodes) {
            auto component = node->get_component<FakeComponent>();
            if (component == nullptr) {
                throw std::bad_typeid();
            }
            auto casted_comp = dynamic_cast<FakeComponent*>(component);
            casted_comp->fake = "Overrided";
        }
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;
};

class EntityChecherSystem: public ActiveSystem<FakeNode> {
  public:
    void execute() const final {
        for (const auto& node: active_nodes) {
            auto component = node->get_component<FakeComponent>();
            if (component == nullptr) {
                throw std::bad_typeid();
            }
            auto casted_comp = dynamic_cast<FakeComponent*>(component);
            if (casted_comp->fake != "Overrided") {
                throw std::bad_typeid();
            }
        }
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;
};

class TestGameLoop: public GameLoop {
  public:
    TestGameLoop(): GameLoop() {}
    void run() {
        cycle();
    }
};

class SetupLoopCycle: public ::testing::Test {
  protected:
    void SetUp() final {
        gm = new TestGameLoop;
        g_system = new EntityGeneratorSystem;
        e_system = new EntityEditorSystem;
        c_system = new EntityChecherSystem;
        node = new FakeNode;
        comp = new FakeComponent;
        gm->add_prototype(node);
        EntityLifeQueue* tmp = gm->get_queue_ref();
        g_system->set_queue(tmp);
        e_system->set_queue(tmp);
        c_system->set_queue(tmp);
        gm->add_system(g_system);
        gm->add_system(e_system);
        gm->add_system(c_system);
    }

    void TearDown() final {
        delete gm;
    }

    TestGameLoop* gm;
    EntityGeneratorSystem* g_system;
    EntityEditorSystem* e_system;
    EntityChecherSystem* c_system;
    FakeNode* node;
    FakeComponent* comp;
};

#endif  // ACID_INCLUDE_TEST_LOOP_CYCLE_H_

// Одна активная система, которая добавляет Entity, одну, которая меняет значения в компонентах,
// реактивную систему, которая смотрит на значения в компонентах и меняет в зависимости от этих значений
// другие компоненты. Активная система для проверки значений.