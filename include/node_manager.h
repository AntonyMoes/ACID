#ifndef ACID_INCLUDE_NODE_MANAGER_H_
#define ACID_INCLUDE_NODE_MANAGER_H_


#include <map>
#include <i_node.h>
#include <event_manager.h>
#include <i_node.h>
#include <entity.h>

class NodeManager {
  public:
	NodeManager();
	~NodeManager();
	void add_prototype(INode* node);
	void add_nodes(Entity* entity);

  private:
	std::vector<INode*> node_prototypes;
};

#endif  // ACID_INCLUDE_NODE_MANAGER_H_ 
 
