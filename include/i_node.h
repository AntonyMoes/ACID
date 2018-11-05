#ifndef ACID_INCLUDE_I_NODE_H_
#define ACID_INCLUDE_I_NODE_H_


#include <map>

#include <i_component.h>
#include <i_observable.h>
#include <i_observer.h>

class INode : public IObservable, IObserver {
  public:
    INode() = delete;
    virtual ~INode();
    void add(IComponent* component);


  protected:
  	size_t type;
    std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_I_NODE_H_
