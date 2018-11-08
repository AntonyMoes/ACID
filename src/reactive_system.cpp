#include <reactive_system.h>

template <class T>
void ReactiveSystem<T>::on_update(T* node) {
	waiting_nodes.push_back(node);
} 

template <class T>
void ReactiveSystem<T>::on_create(T* node) {
	waiting_nodes.push_back(node);
}

template <class T>
void ReactiveSystem<T>::on_delete(T *node) {
    waiting_nodes.remove(node);
}

template<class T>
void ReactiveSystem<T>::run() {
    flush();
    execute();
}

template<class T>
void ReactiveSystem<T>::flush() {
    reactive_nodes = std::move(waiting_nodes);
}

