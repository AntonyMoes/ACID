#include <i_system.h>

template<class T>
ISystem<T>::ISystem(EventManager *manager, EntityLifeQueue *queue) :
    event_manager(manager), entity_life_queue(queue) {
}