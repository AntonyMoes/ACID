#ifndef ACID_INCLUDE_SERVER_HEALTH_SYNC_NODE_H_
#define ACID_INCLUDE_SERVER_HEALTH_SYNC_NODE_H_


#include <node.h>
#include <name_component.h>
#include <health_component.h>

class ServerHealthSyncNode: public Node<ServerHealthSyncNode> {
  public:
    ServerHealthSyncNode() {
        add_component<NameComponent>();
        add_component<HealthComponent>();
    }
};

#endif  // ACID_INCLUDE_SERVER_HEALTH_SYNC_NODE_H_
