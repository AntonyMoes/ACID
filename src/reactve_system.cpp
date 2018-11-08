#include <reactive_system.h>

template <class T>
void ReactiveSystem<T>::on_update(T* node) {
	reactive_nodes->push_back(node);
} 

template <class T>
void ReactiveSystem<T>::on_create(T* node) {
	reactive_nodes->push_back(node);
}

