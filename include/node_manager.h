#ifndef ACID_INCLUDE_NODE_MANAGER_H_
#define ACID_INCLUDE_NODE_MANAGER_H_


#include <map>
#include <i_node.h>
#include <event_manager.h>
#include <i_node.h>
#include <entity.h>

class NodeManager: IObserver<INode> {
  public:
	NodeManager(EventManager* _event_manager);
	~NodeManager();
	void add_nodes(Entity* entity);
	void on_delete(INode* sender) final;

  private:
	std::vector<INode*> nodes;
	EventManager* event_manager;
};

#endif  // ACID_INCLUDE_NODE_MANAGER_H_ 
 
