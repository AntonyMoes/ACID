#ifndef ACID_INCLUDE_NODE_H_
#define ACID_INCLUDE_NODE_H_

#include <typeindex>
#include <iostream>

#include <i_node.h>
#include <proxy_singleton_observer.h>

template <class T>
class Node : public IObservable<T>, public INode {
  public:
    Node(const Node<T>& node) {
        for (const auto &component : node.components) {
            this->components[component.first] = component.second;
        }
        subscribe();

        std::cout << "I was created! (Node)" << std::endl;
        for (const auto &component : components) {
            size_t n = 0;
            std::cout << "Component # " << n++ << " id is " << component.first << std::endl;
        }
    }

    INode* clone() final {
        auto node = new Node<T>(*this);
        return node;
    }

    void subscribe() {
        for (auto i: this->components) {
            i.second->add_observer(this);
        }
        auto obs = ProxySingletonObserver<T>::get_instance();
        this->add_observer(obs);
        obs->on_create(dynamic_cast<T*>(this));
    }

    void on_update(IComponent* sender) final {
        for (auto i: this->observers) {
            i->on_update(dynamic_cast<T*>(this));
        }
    }
    void on_delete(IComponent* sender) final {
        for (auto i: this->observers) {
            i->on_delete(dynamic_cast<T*>(this));
        }
    }

    template <class C>
    IComponent* get_component(/*size_t id*/) {
        auto iter = this->components.begin();
        auto id = std::type_index(typeid(C)).hash_code();
        std::cout << "Find id " << id << std::endl;
        for (const auto &component : this->components) {
            size_t n = 0;
            std::cout << "Component # " << n++ << " id is " << component.first << std::endl;
        }
        auto component = this->components.find(id);
        if (component != this->components.end()) {
            return this->components[id];
        } else {
            return nullptr;
        }
    }  // TODO: check this solution


  protected:
    template <class C>
    void add_component() {
        auto hash = std::type_index(typeid(C)).hash_code();
        std::cout << "Hash: " << hash << std::endl;
        std::cout << "Another hash try: " << std::type_index(typeid(C)).hash_code() << std::endl;
        std::cout << "Name (in node): " << std::type_index(typeid(C)).name() << std::endl;
        components[hash] = nullptr;
    }
    Node() = default;
};

#endif  // ACID_INCLUDE_NODE_H_
