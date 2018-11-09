#ifndef ACID_INCLUDE_ENTITY_MANAGER_H_
#define ACID_INCLUDE_ENTITY_MANAGER_H_


#include <map>

#include <entity.h>
#include <node_manager.h>

class EntityManager {
  public:
	explicit EntityManager(NodeManager* _node_manager);
	~EntityManager();
	void add_entity(Entity *entity);
	Entity* get_entity(size_t id);
	void delete_entity(size_t id);

  private:
    size_t gen_id();
	NodeManager* node_manager;
	std::map<size_t, Entity*> entity_map;
};

#endif  // ACID_INCLUDE_ENTITY_MANAGER_H_ 
