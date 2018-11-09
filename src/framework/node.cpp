/*#include <node.h>
#include <proxy_singleton_observer.h>
#include <typeindex>

template <class T>
Node<T>::Node(const Node<T> &node) {
    for (const auto &component : node.components) {
        this->components[component.first] = component.second;
    }
    subscribe();
}


template <class T>
void Node<T>::subscribe() {
    for (auto i: this->components) {
        i.second->add_observer(this);
    }
    auto obs = ProxySingletonObserver<T>::get_instance();
    add_observer(&obs);
    obs.on_create(this);
}

template<class T>
void Node<T>::on_update(IComponent* sender) {
    this->update();
}


template <class T>
void Node<T>::on_delete(IComponent* sender) {
    for (auto i: this->observers) {
        i->on_delete(this);
    }
}

template<class T>
INode* Node<T>::clone() {
    auto node = new Node<T>;

    for (const auto &component : components) {
        node->components[component.first] = component.second;
    }
    node->subscribe();

    return node;
}

template<class T>
template<class C>
void Node<T>::add_component() {
    components[std::type_index(typeid(C)).hash_code()] = nullptr;
}

template<class T>
IComponent* Node<T>::get_component(size_t id) {
    auto component = components.find(id);
    if (component != components.end()) {
        return components[id];
    } else {
        return nullptr;
    }
}*/

//TODO: delete