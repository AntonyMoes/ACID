#ifndef ACID_INCLUDE_NODE_MANAGER_H_
#define ACID_INCLUDE_NODE_MANAGER_H_


#include <vector>

#include <i_node.h>
#include <i_node.h>
#include <entity.h>

class NodeManager {
  public:
	NodeManager() = default;
	~NodeManager() = default; // TODO: maybe it will manage prototype's memory
	void add_prototype(INode* node);
	void add_nodes(Entity* entity);

  private:
	std::vector<INode*> node_prototypes;
};

#endif  // ACID_INCLUDE_NODE_MANAGER_H_ 
 
