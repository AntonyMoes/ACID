#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>

#include <i_component.h>

class Entity {
  public:
    Entity() = delete;

  //protected:
    std::map<size_t, IComponent> components;
};

#endif  // ACID_INCLUDE_ENTITY_H_
