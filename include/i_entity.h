#ifndef ACID_INCLUDE_I_ENTITY_H_
#define ACID_INCLUDE_I_ENTITY_H_


#include <map>

#include <i_component.h>

class IEntity {
  public:
    IEntity() = delete;
    virtual ~IEntity();

  protected:
    std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_I_ENTITY_H_
