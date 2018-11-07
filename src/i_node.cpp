#include <typeindex>

#include <i_node.h>
#include <proxy_singleton_observer.h>

template <class T>
INode<T>::INode() {
    auto obs = ProxySingletonObserver<T>::get_instance();
    add_observer(&obs);
}

template<class T>
template<class C>
void INode<T>::add_component() {
    components[std::type_index(typeid(C)).hash_code()] = nullptr;
}

template<class T>
bool INode<T>::initialize_components(const std::map<size_t, IComponent> &comps) {
	for (auto i = components.begin(); i != components.end(); ++i) {
		auto component = comps.find(i->key);
		if (component != comps.end) {
			components[i->key] = component->value;
		} else {
			return false;
		}
	}
	return true;
}

template<class T>
void INode<T>::on_update(IComponent* component) final {
	update();
}

void INode<T>::on_delete(IComponent* component) final {
	//TODO: some stuff. Maybe blank.
}



