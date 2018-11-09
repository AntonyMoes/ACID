#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>
#include <list>
#include <typeindex>
#include <iostream>

#include <i_component.h>
#include <i_node.h>

class Entity {
  public:
    explicit Entity(size_t _id = 0);
    ~Entity();
    template <class C>
    void add_component(IComponent* component) {
        auto hash = std::type_index(typeid(C)).hash_code();
        std::cout << "Hash: " << hash << std::endl;
        std::cout << "Another hash try: " << std::type_index(typeid(C)).hash_code() << std::endl;
        std::cout << "Name (in entity): " << std::type_index(typeid(C)).name() << std::endl;
        components[hash] = component;
        component->set_parent_id(id);
    }

    void add_node(INode* node);
    const std::map<size_t, IComponent*>& get_components();
    size_t get_id();
    void set_id(size_t _id);
  private:
  	size_t id;
  	std::list<INode*> nodes;
  	std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_ENTITY_H_
