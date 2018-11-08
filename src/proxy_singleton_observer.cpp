#include <proxy_singleton_observer.h>

template<class T>
void ProxySingletonObserver<T>::on_update(T* sender) {
    for (auto i = this->observers.start(); i != this->observers.end(); ++i) {
		i->on_update(sender);
	}
}

template<class T>
void ProxySingletonObserver<T>::on_delete(T* sender) {
	for (auto i = this->observers.start(); i != this->observers.end(); ++i) {
		i->on_delete(sender);
	}
}

template<class T>
void ProxySingletonObserver<T>::on_create(T* sender) {
    for (auto i = this->observers.start(); i != this->observers.end(); ++i) {
		i->on_create(sender);
	}
}