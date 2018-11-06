#ifndef ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
#define ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_


#include <i_singleton.h>
#include <i_update_observer.h>

template <class T>
class ProxySingletonObserver : public ISingleton, IUpdateObserver<T>{
  public:
    ~ProxySingletonObserver() final;
    void on_update(T* sender) final;
    // void on_update(T* sender) final; TODO(ukhachev): how do you like this???
    void add_observer(IUpdateObserver<T> *observer);

  private:
    IUpdateObserver<T>* observer;
};
#endif  // ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
