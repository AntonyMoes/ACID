#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <i_system.h>

template <class T>
class ReactiveSystem : public ISystem<T> {
  public:
    virtual ~ReactiveSystem();
    void execute() final;

  protected:
    // Set of Nodes
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
