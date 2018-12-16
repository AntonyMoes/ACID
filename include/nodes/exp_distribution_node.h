#ifndef ACID_INCLUDE_EXP_DISTRIBUTION_NODE_H_
#define ACID_INCLUDE_EXP_DISTRIBUTION_NODE_H_


#include <node.h>
#include <drop_exp_component.h>
#include <collision_component.h>

class ExpDistributionNode: public Node<ExpDistributionNode> {
  public:
    ExpDistributionNode() {
        add_component<DropExpComponent>();
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_EXP_DISTRIBUTION_NODE_H_
