#ifndef ACID_INCLUDE_SERVER_EXPBALL_SYNC_NODE_H_
#define ACID_INCLUDE_SERVER_EXPBALL_SYNC_NODE_H_


#include <node.h>
#include <drop_exp_component.h>
#include <body_component.h>

class ServerExpBallSyncNode: public Node<ServerExpBallSyncNode> {
  public:
    ServerExpBallSyncNode() {
        add_component<DropExpComponent>();
        add_component<BodyComponent>();
    }
};

#endif  // ACID_INCLUDE_SERVER_EXPBALL_SYNC_NODE_H_
