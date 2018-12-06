#include <entity.h>
#include <typeindex>
#include <iostream>
#include <framework/entity.h>


Entity::Entity(uint16_t type_id, uint16_t id): id(id), type_id(type_id) {

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

	for (auto i: nodes) {
		delete i;
	}
    for (auto i: components) {
        delete i.second;
    }
}

uint16_t Entity::get_id() {
	return id;
}

void Entity::set_id(uint16_t _id) {
	for (auto i: components) {
		i.second->set_parent_id(_id);
	}
	id = _id;
}

uint16_t Entity::get_type_id() {
	return type_id;
}

void Entity::set_type_id(uint16_t type_id) {
	this->type_id = type_id;
}
