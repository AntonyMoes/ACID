#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <vector>

#include <i_system.h>

template <class T>
class ReactiveSystem : public ISystem<T> {
  public:
    virtual ~ReactiveSystem() = default;
    void on_update(T* node) final;
    void on_create(T* node) override;
    void on_delete(T* node) override;
    void execute() const override = 0;
    void run() final;

  protected:
    void flush();
    std::list<T*> reactive_nodes;
    std::list<T*> waiting_nodes;
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
