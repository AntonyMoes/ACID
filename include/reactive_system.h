#ifndef ACID_INCLUDE_REACTIVE_SYSTEM_H_
#define ACID_INCLUDE_REACTIVE_SYSTEM_H_


#include <i_system.h>

class ReactiveSystem : public ISystem {
  public:
    virtual ~ReactiveSystem();
    void execute() final;
};

#endif  // ACID_INCLUDE_REACTIVE_SYSTEM_H_
