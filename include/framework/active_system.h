#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <vector>

#include <i_system.h>

template <class T>
class ActiveSystem : public ISystem<T> {
  public:
    ActiveSystem<T>() = default;
    virtual ~ActiveSystem() = default;

    void on_create(T* node) final {
        active_nodes.push_back(node);
    }

    void on_delete(T* node) final {
        for (auto i: active_nodes) {
            if (i == node) {
                //active_nodes.remove(i);   // TODO(vladimir): uncomment this
            }
        }
    }
    void run() final {
        execute();
    }
    void execute() const override = 0;

  protected:
    std::vector<T*> active_nodes;
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
