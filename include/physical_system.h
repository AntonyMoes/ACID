#ifndef ACID_INCLUDE_PHYSICAL_SYSTEM_H_
#define ACID_INCLUDE_PHYSICAL_SYSTEM_H_


#include <active_system.h>
#include <physical_node.h>

class PhysicalSystem: public ActiveSystem<PhysicalNode> {
  public:
    PhysicalSystem(b2World* world): world(world) {}

    void execute() const override {

    }

  private:
    b2World* world;
};

#endif  // ACID_INCLUDE_PHYSICAL_SYSTEM_H_
