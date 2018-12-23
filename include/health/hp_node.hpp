#ifndef ACID_INCLUDE_HP_NODE_HPP_
#define ACID_INCLUDE_HP_NODE_HPP_


#include <node.h>
#include <health_component.h>
#include <mana_component.h>
#include <camera_component.h>

class HPNode: public Node<HPNode> {
  public:
    HPNode() {
        add_component<CameraComponent>();
        add_component<HealthComponent>();
        add_component<ManaComponent>();
        add_component<ExpComponent>();
    }
};

#endif  // ACID_INCLUDE_HP_NODE_HPP_
