#ifndef ACID_INCLUDE_CLIENT_POSITION_SYNC_NODE_H_
#define ACID_INCLUDE_CLIENT_POSITION_SYNC_NODE_H_

#include <node.h>
#include <position_component.h>


class ClientPosSyncNode: public Node<ClientPosSyncNode> {
  public:
    ClientPosSyncNode() {
        add_component<PositionComponent>();
    }
};

#endif  // ACID_INCLUDE_CLIENT_POSITION_SYNC_NODE_H_
