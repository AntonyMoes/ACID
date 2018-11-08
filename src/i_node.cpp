#include <typeindex>

#include <i_node.h>
#include <proxy_singleton_observer.h>

template <class T>
INode<T>::INode() {

}

template <class T>
INode<T>::INode(const INode<T>& node): components(node.components) {
	subscribe();
}

template <class T>
void INode<T>::subscribe() {
	for (auto i = components.begin(); i != components.end(); ++i) {
		i->second->add_observer(this);
	}
	auto obs = ProxySingletonObserver<T>::get_instance();
	add_observer(&obs);
	obs.on_create(this);
}

template<class T>
template<class C>
void INode<T>::add_component() {
    components[std::type_index(typeid(C)).hash_code()] = nullptr;
}

template<class T>
bool INode<T>::initialize_components(const std::map<size_t, IComponent*> &comps) {
	for (auto i = components.begin(); i != components.end(); ++i) {
		auto component = comps.find(i->first);
		if (component != comps.end()) {
			components[i->first] = component->second;
		} else {
			return false;
		}
	}
	return true;
}

template<class T>
void INode<T>::on_update(IComponent* sender) {
	this->update();
}

template <class T>
void INode<T>::on_delete(IComponent* sender) {
	for (auto i = this->observers.start(); i != this->observers.end(); ++i) {
		i->on_delete(this);
	}
}



