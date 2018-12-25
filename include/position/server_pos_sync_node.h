#ifndef ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_
#define ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_


#include <node.h>
#include <collision/collision_component.h>
#include <name_component.h>

class ServerPosSyncNode: public Node<ServerPosSyncNode> {
  public:
    ServerPosSyncNode() {
        add_component<CollisionComponent>();
        add_component<NameComponent>();
    }
};

#endif  // ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_
