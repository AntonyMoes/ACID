#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <vector>

#include <i_system.h>
#include <set>

template <class T>
class ReactiveSystem : public ISystem<T> {
  public:
    virtual ~ReactiveSystem() = default;
    void on_update(T* node) final  {
        if (waiting_nodes.find(node) == waiting_nodes.end()) {
            on_node_update(node);
        }
        waiting_nodes.insert(node);


    }
    void on_create(T* node) override {
        if (waiting_nodes.find(node) == waiting_nodes.end()) {
            on_node_create(node);
        }
        waiting_nodes.insert(node);

    }
    void on_delete(T* node) override {
        if (waiting_nodes.find(node) == waiting_nodes.end()) {
            on_node_delete(node);
        }
        waiting_nodes.erase(node);
    }
    void execute() override = 0;
    void run() final {
        flush();
        execute();
        //waiting_nodes.clear();
    }

  protected:
    void flush() {
        reactive_nodes = std::move(waiting_nodes);
    }
    virtual void on_node_create(T* node) {

    }
    virtual void on_node_delete(T* node) {

    }
    virtual void on_node_update(T* node) {

    }
    std::set<T*> reactive_nodes;
    std::set<T*> waiting_nodes;
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
