#ifndef ACID_INCLUDE_COLLISION_LISTENER_H_
#define ACID_INCLUDE_COLLISION_LISTENER_H_


#include <collision_component.h>

class CollisionListener: public b2ContactListener {
    void BeginContact(b2Contact* contact) override {
        std::cout << "12" << std::endl;
        if (contact->IsTouching()) {
            auto collision_compA = contact->GetFixtureA()->GetBody()->GetUserData();
            auto collision_compB = contact->GetFixtureB()->GetBody()->GetUserData();
            if (collision_compA && collision_compB) {
                auto collisionA = static_cast<CollisionComponent*>(collision_compA);
                auto collisionB = static_cast<CollisionComponent*>(collision_compB);

                uint16_t id_a = collisionA->get_parent_id();
                uint16_t id_b = collisionB->get_parent_id();

                collisionA->start_collision(id_b);
                collisionB->start_collision(id_a);
            } else if (collision_compA) {
                auto collisionA = static_cast<CollisionComponent*>(collision_compA);
                collisionA->start_collision(0);
            } else if (collision_compB) {
                auto collisionB = static_cast<CollisionComponent*>(collision_compB);
                collisionB->start_collision(0);
            }
        }
    }

    void EndContact(b2Contact* contact) override {
        auto collision_compA = contact->GetFixtureA()->GetBody()->GetUserData();
        auto collision_compB = contact->GetFixtureB()->GetBody()->GetUserData();
        if (collision_compA && collision_compB) {
            auto collisionA = static_cast<CollisionComponent*>(collision_compA);
            auto collisionB = static_cast<CollisionComponent*>(collision_compB);
            collisionA->end_collision();
            collisionB->end_collision();
        } else if (collision_compA) {
            auto collisionA = static_cast<CollisionComponent*>(collision_compA);
            collisionA->end_collision();
        } else if (collision_compB) {
            auto collisionB = static_cast<CollisionComponent*>(collision_compB);
            collisionB->end_collision();
        }
    }
};

#endif  // ACID_INCLUDE_COLLISION_LISTENER_H_
