#include <i_observable.h>

template <class T>
void IObservable<T>::update() {
    for (auto observer: observers) {
        observer->on_update(this);
    }
}

template <class T>
void IObservable<T>::add_observer(IObserver<T>* observer) {
	observers->push_front(observer);
}

template <class T>
void IObservable<T>::delete_observer(IObserver<T>* observer) {
	observers.remove(observer);
}