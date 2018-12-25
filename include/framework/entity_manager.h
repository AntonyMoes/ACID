#ifndef ACID_INCLUDE_ENTITY_MANAGER_H_
#define ACID_INCLUDE_ENTITY_MANAGER_H_


#include <map>

#include <entity.h>
#include <node_manager.h>

class EntityManager {
  public:
	EntityManager(NodeManager* _node_manager, bool _is_server);
	~EntityManager();
	void add_entity(Entity *entity);
	Entity* get_entity(uint16_t id);
	void delete_entity(uint16_t id);

  private:
    uint16_t gen_id();
	NodeManager* node_manager;
	std::map<uint16_t, Entity*> entity_map;
    bool is_server;
};

#endif  // ACID_INCLUDE_ENTITY_MANAGER_H_ 
