#ifndef ACID_INCLUDE_COLLISION_COMPONENT_H_
#define ACID_INCLUDE_COLLISION_COMPONENT_H_

#include <Box2D/Box2D.h>

#include <i_component.h>
#include <single_world.h>


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

    void start_collision(size_t collide_id) {
        is_collision = true;
        this->collide_id = collide_id;
        update();
    }

    void end_collision() {
        is_collision = false;
        update();
    }

    bool is_collide() {
        return is_collision;
    }

    size_t get_collide_id() {
        return collide_id;
    }

  private:
    b2Body* body;
    bool is_collision = false;
    size_t collide_id = 0;
};

#endif  // ACID_INCLUDE_COLLISION_COMPONENT_H_
