#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <i_system.h>

template <class T>
class ReactiveSystem : public virtual ISystem<T> {
  public:
    virtual ~ReactiveSystem();
    void on_update(T* node) final;
    void on_create(T* node) final;

  protected:
    std::vector<T*> reactive_nodes;
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
