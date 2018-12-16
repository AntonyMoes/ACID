//
// Created by sava on 16.12.18.
//

#ifndef ACID_HP_NODE_HPP

#include <node.h>
#include <health_component.h>
#include <camera_component.h>


class HPNode: public Node<HPNode> {
 public:
    HPNode() {
        add_component<CameraComponent>();
        add_component<HealthComponent>();
    }
};
#define ACID_HP_NODE_HPP
#endif //ACID_HP_NODE_HPP
