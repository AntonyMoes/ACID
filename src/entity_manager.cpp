#include <entity_manager.h>

EntityManager::EntityManager(NodeManager* _node_manager): node_manager(_node_manager) {

}

void EntityManager::add_entity(Entity *entity) {
	auto id = entity->get_id();
	entity_map[id] = entity;
	node_manager->add_nodes(entity);
}

Entity* EntityManager::get_entity(size_t id) {
	return entity_map[id];
}

void EntityManager::delete_entity(size_t id) {
	delete entity_map[id];
	entity_map->erase(id);
}

EntityManager::~EntityManager() {
	for (auto i = entity_map.begin(); i != entity_map.end; ++i) {
		delete *i;
	}
}