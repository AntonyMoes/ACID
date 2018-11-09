#include <node_manager.h>

void NodeManager::add_prototype(INode* node) {
	node_prototypes.push_back(node);
	std::cout << "Add proto" << std::endl;
}

void NodeManager::add_nodes(Entity* entity) {
	auto components = entity->get_components();

	for (auto i: node_prototypes) {
		if (i->initialize_components(components)) {
			auto new_node = i->clone();
			entity->add_node(new_node);
		}
	}
}
