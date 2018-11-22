#ifndef ACID_INCLUDE_TEST_LOOP_CYCLE_H_
#define ACID_INCLUDE_TEST_LOOP_CYCLE_H_


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <game_loop.h>
#include <active_system.h>

using ::testing::AtLeast;


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
    void execute() const override {
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
    void execute() const override {
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

class EntityCheckerSystem: public ActiveSystem<FakeNode> {
  public:
    void execute() const override {
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

class MockEntityGeneratorSystem: public EntityGeneratorSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class MockEntityEditorSystem: public EntityEditorSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class MockEntityCheckerSystem: public EntityCheckerSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class SetupLoopCycle: public ::testing::Test {
  protected:
    void SetUp() final {
        g_system = new MockEntityGeneratorSystem;
        e_system = new MockEntityEditorSystem;
        c_system = new MockEntityCheckerSystem;

        gm = new TestGameLoop;

        node = new FakeNode;
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
    MockEntityGeneratorSystem* g_system;
    MockEntityEditorSystem* e_system;
    MockEntityCheckerSystem* c_system;
    FakeNode* node;
};


#endif  // ACID_INCLUDE_TEST_LOOP_CYCLE_H_
