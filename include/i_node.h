#ifndef ACID_INCLUDE_I_NODE_H_
#define ACID_INCLUDE_I_NODE_H_


#include <map>

#include <i_component.h>
#include <i_observable.h>
#include <i_observer.h>

template <class T>
class INode : public IObservable, IObserver<IComponent> {
  public:
    explicit INode();
    explicit INode(const INode<T>& node);
    virtual INode* clone() = 0;
    bool initialize_components(const std::map<size_t, IComponent*>& comps);
    
    void on_update(IComponent* component) final;
    void on_delete(IComponent* component) final;

  protected:
    template <class C>
    void add_component();
    std::map<size_t, IComponent*> components;

  private:
    void subscribe();
};

#endif  // ACID_INCLUDE_I_NODE_H_
