#ifndef ACID_INCLUDE_I_NODE_H_
#define ACID_INCLUDE_I_NODE_H_


#include <map>

#include <i_component.h>
#include <i_observable.h>
#include <i_observer.h>

class INode : public IObserver<IComponent> {
  public:
    virtual INode* clone() = 0;
    bool initialize_components(const std::map<size_t, IComponent*>& comps);


    //template <class C>
    //void add_component();

  protected:
    std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_I_NODE_H_
