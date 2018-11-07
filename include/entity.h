#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>
#include <list>
#include <i_component.h>

class Entity {
  public:
    Entity();
    ~Entity();
    void add_component(IComponent* component);
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
