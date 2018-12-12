#include <entity_manager.h>

EntityManager::EntityManager(NodeManager* _node_manager, bool _is_server):
			node_manager(_node_manager), is_server(_is_server) {

}

void EntityManager::add_entity(Entity *entity) {
	auto id = entity->get_id();
	if (id == 0) {
		id = gen_id();
	}
	entity->set_id(id);
	entity_map[id] = entity;
	node_manager->add_nodes(entity);
}

Entity* EntityManager::get_entity(uint16_t id) {
	return entity_map[id];
}

void EntityManager::delete_entity(uint16_t id) {
	delete entity_map[id];
	entity_map.erase(id);
}

EntityManager::~EntityManager() {
	for (auto i: entity_map) {
		delete i.second;
	}
}

uint16_t EntityManager::gen_id() {
	if (is_server) {
		static uint16_t server_id = 1;
		return server_id++;
	} else {
		static uint16_t client_id = 10000;
		return client_id;
	}
}
