#ifndef ACID_INCLUDE_COLLISION_LISTENER_H_
#define ACID_INCLUDE_COLLISION_LISTENER_H_


#include <collision_component.h>

class CollisionListener: public b2ContactListener {
    void BeginContact(b2Contact* contact) {
        void* collision_comp = contact->GetFixtureA()->GetBody()->GetUserData();
        if (collision_comp) {
            collision = dynamic_cast<CollisionComponent>(collision_comp);
            if (collision) {
                collision->start_collision();
            }
        }
        collision_comp = contact->GetFixtureB()->GetBody()->GetUserData();
        if (collision_comp) {
            collision = dynamic_cast<CollisionComponent>(collision_comp);
            if (collision) {
                collision->start_collision();
            }
        }
    }

    void EndContact(b2Contact* contact) {
        void* collision_comp = contact->GetFixtureA()->GetBody()->GetUserData();
        if (collision_comp) {
            collision = dynamic_cast<CollisionComponent>(collision_comp);
            if (collision) {
                collision->end_collision();
            }
        }
        collision_comp = contact->GetFixtureB()->GetBody()->GetUserData();
        if (collision_comp) {
            collision = dynamic_cast<CollisionComponent>(collision_comp);
            if (collision) {
                collision->end_collision();
            }
        }
    }
};

#endif  // ACID_INCLUDE_COLLISION_LISTENER_H_
