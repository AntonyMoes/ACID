#ifndef ACID_INCLUDE_CLIENT_POS_SYNC_NODE_H_
#define ACID_INCLUDE_CLIENT_POS_SYNC_NODE_H_

#include <node.h>
#include <collision_component.h>
#include <name_component.h>
#include "camera/camera_component.h"

class ClientPosSyncNode: public Node<ClientPosSyncNode> {
  public:
    ClientPosSyncNode() {
        add_component<CollisionComponent>();
        add_component<NameComponent>();
    }
};

class PlayerPosSyncNode: public Node<PlayerPosSyncNode> {
public:
    PlayerPosSyncNode() {
        add_component<CollisionComponent>();
        add_component<CameraComponent>();
        add_component<NameComponent>();
    }
};


#endif  // ACID_INCLUDE_CLIENT_POS_SYNC_NODE_H_
