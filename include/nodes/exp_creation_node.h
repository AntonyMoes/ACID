#ifndef ACID_INCLUDE_EXP_CREATE_NODE_H_
#define ACID_INCLUDE_EXP_CREATE_NODE_H_


#include <node.h>
#include <exp_component.h>
#include <body_component.h>
#include <death_component.h>

class ExpCreationNode: public Node<ExpCreationNode> {
  public:
    ExpCreationNode() {
        add_component<BodyComponent>();
        add_component<ExpComponent>();
        add_component<DeathComponent>();
    }
};

#endif  // ACID_INCLUDE_EXP_CREATE_NODE_H_
