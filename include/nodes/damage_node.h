#ifndef ACID_INCLUDE_DAMAGE_NODE_H_
#define ACID_INCLUDE_DAMAGE_NODE_H_


#include <node.h>
#include <health_component.h>
#include <collision_component.h>

class DamageNode: public Node<DamageNode> {
  public:
    DamageNode() {
        std::cerr << "init\n";
        add_component<DamageComponent>();
        //add_component<HealthComponent>();
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_DAMAGE_NODE_H_
