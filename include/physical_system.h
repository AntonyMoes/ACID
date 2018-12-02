#ifndef ACID_INCLUDE_PHYSICAL_SYSTEM_H_
#define ACID_INCLUDE_PHYSICAL_SYSTEM_H_


#include <active_system.h>
#include <physical_node.h>
#include <tmx_level.h>

class PhysicalSystem: public ActiveSystem<PhysicalNode> {
  public:
    explicit PhysicalSystem(b2World* world, const tmx_level& level): world(world) {
        auto static_objects = level.GetObjSizeLoc();
    }
    ~PhysicalSystem() final { delete world; }

    void execute() override {
        world->Step(1.0f / 60.0f, 1, 1);
    }

  private:
    b2World* world;
};

#endif  // ACID_INCLUDE_PHYSICAL_SYSTEM_H_
