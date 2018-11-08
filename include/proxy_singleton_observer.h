#ifndef ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
#define ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_


#include <i_singleton.h>
#include <i_observable.h>
#include <i_observer.h>

template <class T>
class ProxySingletonObserver : public ISingleton<T>, IObserver<T>, IObservable<T> {
  public:
  	ProxySingletonObserver() = default;
    ~ProxySingletonObserver() final;
    void on_update(T* sender) final;
    void on_delete(T* sender) final;
    void on_create(T* sender) final;
};
#endif  // ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
