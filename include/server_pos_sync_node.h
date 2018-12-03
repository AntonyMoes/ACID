#ifndef ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_
#define ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_

#include <node.h>
#include <collision_component.h>


class ServerPosSyncNode: public Node<ServerPosSyncNode> {
  public:
    ServerPosSyncNode() {
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_SERVER_POS_SYNC_NODE_H_
