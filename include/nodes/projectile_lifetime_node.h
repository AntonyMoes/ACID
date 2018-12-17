#ifndef ACID_INCLUDE_PROJECTILE_LIFETIME_NODE_H_
#define ACID_INCLUDE_PROJECTILE_LIFETIME_NODE_H_


#include <node.h>
#include <lifetime_component.h>
#include <collision/collision_component.h>
#include <death_component.h>

class ProjectileLifetimeNode: public Node<ProjectileLifetimeNode> {
  public:
    ProjectileLifetimeNode() {
        add_component<LifetimeComponent>();
        add_component<CollisionComponent>();
        add_component<DeathComponent>();
    }
};

#endif  // ACID_INCLUDE_PROJECTILE_LIFETIME_NODE_H_
