#ifndef ACID_INCLUDE_I_COMPONENT_H_
#define ACID_INCLUDE_I_COMPONENT_H_


#include <i_observable.h>


class IComponent : public IObservable<IComponent>{
  public:
    IComponent();
    virtual ~IComponent();
};

#endif  // ACID_INCLUDE_I_COMPONENT_H_
