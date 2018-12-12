#ifndef ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_
#define ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_


#include <reactive_system.h>
#include <entity_death_node.h>

class EntityDeathSystem: public ReactiveSystem<EntityDeathNode> {
  public:
    void execute() override {

    }
};

#endif   // ACID_INCLUDE_ENTITY_DEATH_SYSTEM_H_
