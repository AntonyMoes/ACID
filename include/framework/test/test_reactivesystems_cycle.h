#ifndef ACID_INCLUDE_TEST_REACTIVESYSTEMS_CYCLE_H_
#define ACID_INCLUDE_TEST_REACTIVESYSTEMS_CYCLE_H_


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <game_loop.h>
#include <active_system.h>
#include <reactive_system.h>

using ::testing::AtLeast;


class ReactFakeComponent : public IComponent {
  public:
    std::string fake = "ReactFakeComponent";
};

class ReactFakeNode : public Node<ReactFakeNode> {
  public:
    ReactFakeNode() : Node() {
        add_component<ReactFakeComponent>();
    }
};

class FakeGenSystem : public ActiveSystem<ReactFakeNode> {
  public:
    void execute() const override {
        Entity* entity = new Entity();
        auto* comp1 = new ReactFakeComponent;
        entity->add_component(comp1);

        queue->add_entity(entity);
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;
};

class FakeEditSystem : public ActiveSystem<ReactFakeNode> {
  public:
    void execute() const override {
        for (const auto& node: active_nodes) {
            auto component = node->get_component<ReactFakeComponent>();
            if (component == nullptr) {
                throw std::bad_typeid();
            }
            auto casted_comp = dynamic_cast<ReactFakeComponent*>(component);
            casted_comp->fake = "Overrided";
        }
    }

    void set_queue(EntityLifeQueue* _queue) {
        queue = _queue;
    }

  private:
    EntityLifeQueue* queue = nullptr;
};

class ReactiveFakeCheckerSystem: public ReactiveSystem<ReactFakeNode> {
  public:
    void execute() const override {
        for (const auto& node: reactive_nodes) {
            auto component = node->get_component<ReactFakeComponent>();
            if (component == nullptr) {
                throw std::bad_typeid();
            }
            auto casted_comp = dynamic_cast<ReactFakeComponent*>(component);
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

class MockFakeGenSystem: public FakeGenSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class MockFakeEditSystem: public FakeEditSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class MockReactiveFakeCheckerSystem: public ReactiveFakeCheckerSystem {
  public:
    MOCK_CONST_METHOD0(execute, void());
};

class SetupReactiveCycle: public ::testing::Test {
  protected:
    void SetUp() final {
        g_system = new MockFakeGenSystem;
        e_system = new MockFakeEditSystem;
        c_system = new MockReactiveFakeCheckerSystem;

        gm = new TestGameLoop;

        node = new ReactFakeNode;
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
    MockFakeGenSystem* g_system;
    MockFakeEditSystem* e_system;
    MockReactiveFakeCheckerSystem* c_system;
    ReactFakeNode* node;
};


#endif  // ACID_INCLUDE_TEST_REACTIVESYSTEMS_CYCLE_H_
