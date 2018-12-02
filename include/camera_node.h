#ifndef ACID_INCLUDE_CAMERA_NODE_H_
#define ACID_INCLUDE_CAMERA_NODE_H_

#include <node.h>
#include <collision_component.h>
#include <camera_component.h>

class CameraNode: public Node<CameraNode> {
  public:
    CameraNode() {
        add_component<CameraComponent>();
        add_component<CollisionComponent>();
    }
};


#endif  // ACID_INCLUDE_CAMERA_NODE_H_
