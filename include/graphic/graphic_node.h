#ifndef ACID_INCLUDE_GRAPHICAL_NODE_H_
#define ACID_INCLUDE_GRAPHICAL_NODE_H_


#include <node.h>
#include <texture_component.h>
#include <collision/collision_component.h>

class GraphicNode: public Node<GraphicNode> {
  public:
    GraphicNode() {
        add_component<TextureComponent>();
        add_component<CollisionComponent>();
    }
};

#endif  // ACID_INCLUDE_GRAPHICAL_NODE_H_
