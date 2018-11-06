#include <proxy_singleton_observer.h>

template<class T>
void ProxySingletonObserver<T>::add_observer(IUpdateObserver<T> *observer) {
    this->observer = observer;
}

template<class T>
void ProxySingletonObserver<T>::on_update(T *sender) {
    observer->on_update(sender);
}
