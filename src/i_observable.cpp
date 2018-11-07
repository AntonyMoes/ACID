#include <i_observable.h>

template <class T>
void IObservable<T>::update() {
    for (auto observer: observers) {
        observer->on
    }
}