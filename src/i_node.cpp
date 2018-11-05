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
void INode<T>::initialize_components(const std::map<size_t, IComponent> &comps) {
    for (auto& pair : components) {
        pair.second = &comps.at(pair.first);  // TODO(AntonyMoes): лови эксепшн и перепрокидывай другой(не может построиться)
    }
}



/*
 * node.add<Component1>()
 * add<T>():
 *  T* pointer;
 *  map.add(...typeof(T)...)
 */



