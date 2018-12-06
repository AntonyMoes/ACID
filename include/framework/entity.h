#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>
#include <list>
#include <iostream>

#include <i_component.h>
#include <i_node.h>


class Entity {
  public:
    explicit Entity(uint16_t type_id = 0, uint16_t id = 0);
    ~Entity();

    void add_component(IComponent* component);
    void add_node(INode* node);
    const std::map<size_t, IComponent*>& get_components();
    uint16_t get_id();
    uint16_t get_type_id();
    void set_id(uint16_t id);
    void set_type_id(uint16_t type_id);
  private:
  	uint16_t id;
  	uint16_t type_id;
  	std::list<INode*> nodes;
  	std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_ENTITY_H_
