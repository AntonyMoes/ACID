#ifndef ACID_INCLUDE_CLIENT_EXP_SYNC_NODE_H_
#define ACID_INCLUDE_CLIENT_EXP_SYNC_NODE_H_


#include <node.h>
#include <exp_component.h>
#include <name_component.h>

class ClientExpSyncNode: public Node<ClientExpSyncNode> {
  public:
    ClientExpSyncNode() {
        add_component<NameComponent>();
        add_component<ExpComponent>();
    }
};

#endif  // ACID_INCLUDE_CLIENT_EXP_SYNC_NODE_H_
