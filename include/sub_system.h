#ifndef ACID_INCLUDE_SUB_SYSTEM_H_
#define ACID_INCLUDE_SUB_SYSTEM_H_


#include <i_system.h>

class SubSystem : public ISystem {
    void execute() final;
};

#endif  // ACID_INCLUDE_SUB_SYSTEM_H_
