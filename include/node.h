#ifndef ACID_INCLUDE_NODE_H_
#define ACID_INCLUDE_NODE_H_

#include <i_node.h>

template <class T>
class Node : public IObservable<T>, public INode {
  public:
    Node(const Node<T>& node);

    INode* clone() final;
    void subscribe();

    void on_update(IComponent* sender) final;
    void on_delete(IComponent* sender) final;

    IComponent* get_component(size_t id);  // TODO: check this solution


  protected:
    template <class C>
    void add_component();
    Node() = default;
};

#endif  // ACID_INCLUDE_NODE_H_
