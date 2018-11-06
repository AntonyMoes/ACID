#ifndef ACID_INCLUDE_ENTITY_H_
#define ACID_INCLUDE_ENTITY_H_


#include <map>

#include <i_component.h>

class Entity {
  public:
    Entity() = delete;

    template <class C>
    void add_component();  // Adds default component

  //protected:
    std::map<size_t, IComponent> components;
};

#endif  // ACID_INCLUDE_ENTITY_H_
