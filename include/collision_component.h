#ifndef ACID_INCLUDE_COLLISION_COMPONENT_H_
#define ACID_INCLUDE_COLLISION_COMPONENT_H_


#include <i_component.h>
#include <Box2D/Box2D.h>
#include "single_world.h"

class CollisionComponent: public IComponent {
  public:
    explicit CollisionComponent(b2Body* body): body(body) {}
    ~CollisionComponent() override {
        auto* world = SingleWorld::get_instance();
        world->DestroyBody(body);
    }

    b2Body* get_body() {
        return body;
    }

  private:
    b2Body* body;
};

#endif  // ACID_INCLUDE_COLLISION_COMPONENT_H_
