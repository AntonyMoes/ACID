#ifndef ACID_INCLUDE_ENTITY_DEATH_NODE_H_
#define ACID_INCLUDE_ENTITY_DEATH_NODE_H_


#include <i_node.h>
#include <animation_component.h>





va_list

#include <death_component.h>

class EntityDeathNode: public INode<EntityDeathNode> {
  public:
    EntityDeathNode() {
        add_component<AnimationComponent>;
        add_component<DeathComponent>;
    }
};

#endif  // ACID_INCLUDE_ENTITY_DEATH_NODE_H_
