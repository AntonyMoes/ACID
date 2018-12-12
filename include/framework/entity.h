#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>
#include <list>
#include <iostream>

#include <i_component.h>
#include <i_node.h>


class Entity {
  public:
    explicit Entity(uint16_t _id = 0);
    ~Entity();

    void add_component(IComponent* component);
    void add_node(INode* node);
    const std::map<size_t, IComponent*>& get_components();
    template <class T>
    T* get_component() {
        auto id = typeid(T).hash_code();
        auto component = components.find(id);
        if (component != components.end()) {
            return dynamic_cast<T*>(component->second);
        } else {
            return nullptr;
        }
    }
    uint16_t get_id();
    void set_id(uint16_t _id);
  private:
  	uint16_t id;
  	std::list<INode*> nodes;
  	std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_ENTITY_H_
