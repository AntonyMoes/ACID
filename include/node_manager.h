#ifndef ACID_INCLUDE_NODE_MANAGER_H_
#define ACID_INCLUDE_NODE_MANAGER_H_


#include <map>
#include <node.h>
#include <event_manager.h>
#include <node.h>
#include <entity.h>

class NodeManager: IObserver<Node> {
  public:
	NodeManager(EventManager* _event_manager);
	~NodeManager();
	void add_nodes(Entity* entity);
	void on_delete(Node* sender) final;

  private:
	std::vector<Node*> nodes;
	EventManager* event_manager;
};

#endif  // ACID_INCLUDE_NODE_MANAGER_H_ 
 
