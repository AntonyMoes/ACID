#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <vector>
#include <set>

#include <i_system.h>

template <class T>
class ActiveSystem : public ISystem<T> {
  public:
    ActiveSystem<T>() = default;
    virtual ~ActiveSystem() = default;

    void on_create(T* node) final {
        active_nodes.insert(node);
        on_node_create(node);
    }

    void on_delete(T* node) final {
        auto iter = active_nodes.find(node);
        if (iter != active_nodes.end()) {
            active_nodes.erase(iter);
        }
        on_node_delete(node);
    }

    void run() final {
        execute();
    }

    void execute() override = 0;

  protected:
    virtual void on_node_create(T* node) {
    }
    virtual void on_node_delete(T* node) {
    }

    std::set<T*> active_nodes;
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
