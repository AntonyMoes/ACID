#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <vector>

#include <i_system.h>

template <class T>
class ReactiveSystem : public ISystem<T> {
  public:
    virtual ~ReactiveSystem() = default;
    void on_update(T* node) final  {
        waiting_nodes.push_back(node);
    }
    void on_create(T* node) override {
        waiting_nodes.push_back(node);
    }
    void on_delete(T* node) override {
        waiting_nodes.remove(node);
    }
    void execute() const override = 0;
    void run() final {
        flush();
        execute();
    }

  protected:
    void flush() {
        reactive_nodes = std::move(waiting_nodes);
    }
    std::list<T*> reactive_nodes;
    std::list<T*> waiting_nodes;
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
