#ifndef ACID_INCLUDE_ENTITY_DEATH_NODE_H_
#define ACID_INCLUDE_ENTITY_DEATH_NODE_H_


#include <node.h>
#include <animation_component.h>
#include <health_component.h>

class EntityDeathNode: public Node<EntityDeathNode> {
  public:
    EntityDeathNode() {
        add_component<HealthComponent>();
    }
};

#endif  // ACID_INCLUDE_ENTITY_DEATH_NODE_H_
