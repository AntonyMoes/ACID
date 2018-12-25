#ifndef ACID_INCLUDE_CLIENT_CAMERA_NODE_H_
#define ACID_INCLUDE_CLIENT_CAMERA_NODE_H_


#include <node.h>
#include <position_component.h>
#include <camera_component.h>

class ClientCameraNode: public Node<ClientCameraNode> {
  public:
    ClientCameraNode() {
        add_component<CameraComponent>();
        add_component<PositionComponent>();
    }
};

#endif  // ACID_INCLUDE_CLIENT_CAMERA_NODE_H_
