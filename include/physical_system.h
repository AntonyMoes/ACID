#ifndef ACID_INCLUDE_PHYSICAL_SYSTEM_H_
#define ACID_INCLUDE_PHYSICAL_SYSTEM_H_


#include <active_system.h>
#include <physical_node.h>

class PhysicalSystem: public ActiveSystem<PhysicalNode> {
  public:
    explicit PhysicalSystem(b2World* world, ): world(world) {}
    ~PhysicalSystem() final { delete world; }

    void execute() override {
        world->Step(1.0f / 60.0f, 1, 1);
    }

  private:
    b2World* world;
};

#endif  // ACID_INCLUDE_PHYSICAL_SYSTEM_H_
