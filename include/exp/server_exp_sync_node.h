#ifndef ACID_INCLUDE_SERVER_EXP_SYNC_NODE_H_
#define ACID_INCLUDE_SERVER_EXP_SYNC_NODE_H_


#include <node.h>
#include <exp_component.h>
#include <name_component.h>

class ServerExpSyncNode: public Node<ServerExpSyncNode> {
  public:
    ServerExpSyncNode() {
        add_component<NameComponent>();
        add_component<ExpComponent>();
    }
};

#endif  // ACID_INCLUDE_SERVER_EXP_SYNC_NODE_H_
