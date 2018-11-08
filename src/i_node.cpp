#include <typeindex>

#include <i_node.h>
#include <proxy_singleton_observer.h>


//template<class C>
//void INode::add_component() {
//    components[std::type_index(typeid(C)).hash_code()] = nullptr;
//}


bool INode::initialize_components(const std::map<size_t, IComponent*> &comps) {
	for (auto i: components) {
		auto component = comps.find(i.first);
		if (component != comps.end()) {
			components[i.first] = component->second;
		} else {
			return false;
		}
	}
	return true;
}




