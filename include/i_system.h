#ifndef ACID_INCLUDE_I_SYSTEM_H_
#define ACID_INCLUDE_I_SYSTEM_H_


#include <entity_life_queue.h>
#include <i_observer.h>
#include <i_node.h>
#include <base_system.h>

template <class T>
class ISystem: BaseSystem, IObserver<T> {
  public:
    ISystem();
    ~ISystem() override = default;
    void execute() const override = 0;
    void run() override = 0;
};

#endif  // ACID_INCLUDE_I_SYSTEM_H_