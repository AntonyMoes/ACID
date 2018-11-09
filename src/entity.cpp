#include <entity.h>
#include <typeindex>
#include <iostream>

Entity::Entity(size_t _id): id(_id) {

}

void Entity::add_component(IComponent* component)  {
	auto hash = typeid(*component).hash_code();
	components[hash] = component;
	component->set_parent_id(id);
}

void Entity::add_node(INode* node) {  // TODO:
	nodes.push_front(node);
}

const std::map<size_t, IComponent*>& Entity::get_components() {
	return components;
}

Entity::~Entity() {
	for (auto i: components) {
		delete i.second;
	}
	for (auto i: nodes) {
		delete i;
	}
}

size_t Entity::get_id() {
	return id;
}

void Entity::set_id(size_t _id) {
	for (auto i: components) {
		i.second->set_parent_id(_id);
	}
	id = _id;
}
