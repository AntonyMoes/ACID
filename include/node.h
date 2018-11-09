#ifndef ACID_INCLUDE_NODE_H_
#define ACID_INCLUDE_NODE_H_

#include <typeindex>

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

    IComponent* get_component(size_t id) {
        auto component = components.find(id);
        if (component != components.end()) {
            return components[id];
        } else {
            return nullptr;
        }
    }  // TODO: check this solution


  protected:
    template <class C>
    void add_component() {
        components[std::type_index(typeid(C)).hash_code()] = nullptr;
    }
    Node() = default;
};

#endif  // ACID_INCLUDE_NODE_H_
