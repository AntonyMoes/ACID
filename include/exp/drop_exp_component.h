#ifndef ACID_INCLUDE_DROP_EXP_COMPONENT_H_
#define ACID_INCLUDE_DROP_EXP_COMPONENT_H_


#include <i_component.h>

class DropExpComponent: public IComponent {
  public:
    DropExpComponent(size_t exp): exp(exp) {}

    size_t get_exp() const {
        return exp;
    }

  private:
    size_t exp;
};

#endif  // ACID_INCLUDE_DROP_EXP_COMPONENT_H_
