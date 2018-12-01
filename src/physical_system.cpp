#include <physical_system.h>

PhysicalSystem::PhysicalSystem() {
    b2Vec2 gravity(0.0f, 1.0f);
    b2World w(gravity);
    world = w;
}