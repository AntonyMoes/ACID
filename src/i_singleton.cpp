#include <i_singleton.h>

template<class T>
T& ISingleton<T>::get_instance() {
    static T instance;
    return instance;
}
