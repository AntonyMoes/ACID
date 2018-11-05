#ifndef ACID_INCLUDE_ENTITY_MANAGER_H_
#define ACID_INCLUDE_ENTITY_MANAGER_H_


#include <map>
#include <entity.h>
#include <node_manager.h>
#include <component_manager.h>
#include <event_manager.h>

class EntityManager {
  public:
	EntityManager(NodeManager* _node_manager, ComponentManager* _component_manager, 
					NodeManager* _node_manager);
	~EntityManager();
	Entity* add_entity(size_t type, size_t id = 0);
	Entity* get_entity(size_t id);
	void delete_entity(size_t id);

  private:
	std::map<size_t, Entity*> entity_map;
	ComponentManager* component_manager;
	NodeManager* node_manager;
	EventManager* event_manager;
};

#endif  // ACID_INCLUDE_ENTITY_MANAGER_H_ 
