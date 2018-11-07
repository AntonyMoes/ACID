#ifndef ACID_INCLUDE_I_SYSTEM_H_
#define ACID_INCLUDE_I_SYSTEM_H_


#include <entity_life_queue.h>
#include <i_observer.h>
#include <i_node.h>

template <class T>
class ISystem: IObserver<T> {
  public:
    ISystem();
    ~ISystem() override = default;
    virtual void execute() = 0;
};

#endif  // ACID_INCLUDE_I_SYSTEM_H_