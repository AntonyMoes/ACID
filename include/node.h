#ifndef ACID_INCLUDE_NODE_H_
#define ACID_INCLUDE_NODE_H_

#include <i_node.h>

template <class T>
class Node : public IObservable<T>, INode {
    Node(const Node<T>& node);

    INode* clone() final;
    void subscribe();

    void on_update(IComponent* sender) final;
    void on_delete(IComponent* sender) final;
};

#endif  // ACID_INCLUDE_NODE_H_
