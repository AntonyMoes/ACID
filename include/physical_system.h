#ifndef ACID_INCLUDE_PHYSICAL_SYSTEM_H_
#define ACID_INCLUDE_PHYSICAL_SYSTEM_H_


#include <active_system.h>
#include <physical_node.h>
#include <tmx_level.h>

class PhysicalSystem: public ActiveSystem<PhysicalNode> {
  public:
    explicit PhysicalSystem(b2World* world, const tmx_level& level): world(world) {
        auto static_objects = level.GetObjSizeLoc();
        for (const auto &object : static_objects) {

            b2BodyDef bodyDef;

            bodyDef.type = b2_staticBody;
            bodyDef.position.Set(object.first.x, object.first.y);  // TODO

            b2Body* body = world->CreateBody(&bodyDef);

            b2PolygonShape shape;

            shape.SetAsBox(object.second.y/2, object.second.x/2);

            body->CreateFixture(&shape,1.0f);
        }
    }
    ~PhysicalSystem() final { delete world; }

    void execute() override {
        world->Step(1.0f / 60.0f, 1, 1);
    }

  private:
    b2World* world;
};

#endif  // ACID_INCLUDE_PHYSICAL_SYSTEM_H_
