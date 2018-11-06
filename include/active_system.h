#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <i_system.h>

template <class T>
class ActiveSystem : public ISystem<T> {
  public:
    virtual ~ActiveSystem();
    void execute() final;
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
