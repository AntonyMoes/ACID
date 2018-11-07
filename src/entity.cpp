#include <entity.h>
#include <typeindex>

Entity::Entity(size_t _id = 0): id(_id) {

}

void Entity::add_component(IComponent* component) {
    components[std::type_index(typeid(component)).hash_code()] = component;
    component->set_parent_id(id);
}

void Entity::add_node(INode* node) {
	nodes->push_front(node);
}

const std::map<size_t, IComponent*>& Entity::get_components() {
	return components;
}

Entity::~Entity() {
	for (auto i = components.begin(); i != components.end(); ++i) {
		delete *i;
	}
	for (auto i = nodes.begin(); i != nodes.end(); ++i) {
		delete *i;
	}
}

size_t Entity::get_id() {
	return id;
}

void Entity::set_id(size_t _id) {
	for (auto i = components.begin(); i != components.end(); ++i) {
		i->set_parent_id(_id);
	}
	id = _id;
}