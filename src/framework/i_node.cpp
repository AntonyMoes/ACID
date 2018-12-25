#include <typeindex>

#include <i_node.h>
#include <proxy_singleton_observer.h>
#include <iostream>

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




