#ifndef ACID_INCLUDE_I_COMPONENT_H_
#define ACID_INCLUDE_I_COMPONENT_H_


#include <stdlib.h>

#include <i_observable.h>

class IComponent : public IObservable<IComponent> {
  public:
    IComponent() = default;
    virtual ~IComponent();
    void set_parent_id(uint16_t _parent_id);
    uint16_t get_parent_id();

  protected:
    void update();
    uint16_t parent_id = 0;
};

#endif  // ACID_INCLUDE_I_COMPONENT_H_
