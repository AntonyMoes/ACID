#ifndef ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
#define ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_


#include <i_singleton.h>
#include <i_observable.h>
#include <i_observer.h>

template <class T>
class ProxySingletonObserver : public ISingleton<ProxySingletonObserver<T>>, public IObserver<T>, public IObservable<T> {
  public:
  	ProxySingletonObserver() = default;
    ~ProxySingletonObserver() final = default;
    void on_update(T* sender) final {
		for (auto observer: this->observers) {
			observer->on_update(sender);
		}
    }
    void on_delete(T* sender) final {
		for (auto observer: this->observers) {
			observer->on_delete(sender);
		}
    }
    void on_create(T* sender) {
		for (auto observer: this->observers) {
			observer->on_create(sender);
		}
    }
};
#endif  // ACID_INCLUDE_PROXY_SINGLETON_OBSERVER_H_
