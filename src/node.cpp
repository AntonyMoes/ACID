#include <node.h>
#include <proxy_singleton_observer.h>

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
    for (auto i = this->observers.start(); i != this->observers.end(); ++i) {
        i->on_delete(this);
    }
}
