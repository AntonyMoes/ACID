#ifndef ACID_INCLUDE_CLIENT_HEALTH_SYNC_NODE_H_
#define ACID_INCLUDE_CLIENT_HEALTH_SYNC_NODE_H_


#include <node.h>
#include <name_component.h>
#include <health_component.h>

class ClientHealthSyncNode: public Node<ClientHealthSyncNode> {
  public:
    ClientHealthSyncNode() {
        add_component<HealthComponent>();
        add_component<NameComponent>();
        add_component<DeathComponent>();
    }
};

#endif  // ACID_INCLUDE_CLIENT_HEALTH_SYNC_NODE_H_
