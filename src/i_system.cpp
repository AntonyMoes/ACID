#include <i_system.h>
#include <proxy_singleton_observer.h>

template<class T>
ISystem<T>::ISystem(EventManager *manager, EntityLifeQueue *queue) :
    event_manager(manager), entity_life_queue(queue) {
    auto proxy = ProxySingletonObserver<T>::get_instance();
    proxy.add_observer(this);
}