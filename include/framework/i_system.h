#ifndef ACID_INCLUDE_I_SYSTEM_H_
#define ACID_INCLUDE_I_SYSTEM_H_


#include <i_observer.h>
#include <node.h>
#include <base_system.h>
#include <proxy_singleton_observer.h>

template <class T>
class ISystem: public BaseSystem, public IObserver<T> {
  public:
    ISystem() {
        auto proxy = ProxySingletonObserver<T>::get_instance();
        proxy->add_observer(this);
    }
    ~ISystem() override = default;
    void execute() override = 0;
    void run() override = 0;
};

#endif  // ACID_INCLUDE_I_SYSTEM_H_