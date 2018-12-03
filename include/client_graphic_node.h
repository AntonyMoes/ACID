#ifndef ACID_INCLUDE_GRAPHICAL_NODE_H_
#define ACID_INCLUDE_GRAPHICAL_NODE_H_


#include <node.h>
#include <texture_component.h>
#include <position_component.h>


class ClientGraphicNode: public Node<ClientGraphicNode> {
  public:
    ClientGraphicNode() {
        add_component<TextureComponent>();
        add_component<PositionComponent>();
    }
};

#endif  // ACID_INCLUDE_GRAPHICAL_NODE_H_
