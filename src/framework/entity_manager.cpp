#include <entity_manager.h>

EntityManager::EntityManager(NodeManager* _node_manager): node_manager(_node_manager) {

}

void EntityManager::add_entity(Entity *entity) {
	//auto id = entity->get_id();  // TODO: for heaven's sake reimplement this line
	auto id = entity->get_id();
	auto type_id = entity->get_type_id();
	entity_map[type_id][id] = entity;
	node_manager->add_nodes(entity);
}

Entity* EntityManager::get_entity(uint16_t type_id, uint16_t id) {
	return entity_map[type_id][id];
}

void EntityManager::delete_entity(uint16_t type_id, uint16_t id) {
	delete entity_map[type_id][id];
	entity_map.erase(id);
}

EntityManager::~EntityManager() {
	for (auto& sub_map: entity_map) {
		for (auto &entity : sub_map.second) {
			delete entity.second;
		}
	}
}

size_t EntityManager::gen_id() {
    static size_t id = 1;
    return id++;
}
