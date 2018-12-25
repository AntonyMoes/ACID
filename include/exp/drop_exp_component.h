#ifndef ACID_INCLUDE_DROP_EXP_COMPONENT_H_
#define ACID_INCLUDE_DROP_EXP_COMPONENT_H_


#include <i_component.h>

class DropExpComponent: public IComponent {
  public:
    DropExpComponent(uint16_t exp): exp(exp) {}

    uint16_t get_exp() const {
        return exp;
    }

  private:
    uint16_t exp;
};

#endif  // ACID_INCLUDE_DROP_EXP_COMPONENT_H_
