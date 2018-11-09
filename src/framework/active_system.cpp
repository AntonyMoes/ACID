/*#include <active_system.h>

template <class T>
void ActiveSystem<T>::on_create(T* node) {
	active_nodes.push_back(node);
}

template <class T>
void ActiveSystem<T>::on_delete(T* node) {
	for (auto i: active_nodes) {
		if (i == node) {
			active_nodes.erase(i);
		}
	}
}

template<class T>
void ActiveSystem<T>::run() {
	execute();
}
*/

//TODO: delete