#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <i_system.h>

class ActiveSystem : public ISystem {
    void execute() final;
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
