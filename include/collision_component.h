#ifndef ACID_INCLUDE_COLLISION_COMPONENT_H_
#define ACID_INCLUDE_COLLISION_COMPONENT_H_


#include <i_component.h>
#include <Box2D/Box2D.h>

class CollisionComponent: public IComponent {
  public:
    CollisionComponent(b2Body* body): body(body) {}

  private:
    b2Body* body;
};

#endif  // ACID_INCLUDE_COLLISION_COMPONENT_H_
