#ifndef ACID_INCLUDE_PHYSICAL_NODE_H_
#define ACID_INCLUDE_PHYSICAL_NODE_H_

#include <node.h>
#include <collision_component.h>
#include <death_component.h>


class PhysicalNode: public Node<PhysicalNode> {
  public:
    PhysicalNode() {
        add_component<CollisionComponent>();
        add_component<DeathComponent>();
    }
};

#endif  // ACID_INCLUDE_PHYSICAL_NODE_H_
