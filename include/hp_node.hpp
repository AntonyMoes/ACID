//
// Created by sava on 16.12.18.
//

#ifndef ACID_HP_NODE_HPP
#define ACID_HP_NODE_HPP

#include <node.h>
#include <health_component.h>
#include <mana/mana_component.h>
#include <camera/camera_component.h>
class HPNode: public Node<HPNode> {
 public:
    HPNode() {
        add_component<CameraComponent>();
        add_component<HealthComponent>();
        add_component<ManaComponent>();
    }
};

#endif //ACID_HP_NODE_HPP
