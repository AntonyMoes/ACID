#ifndef ACID_INCLUDE_SINGLE_WORLD_H_
#define ACID_INCLUDE_SINGLE_WORLD_H_

#include <i_singleton.h>
#include <Box2D/Dynamics/b2World.h>


class SingleWorld : public ISingleton<b2World> {
  public:
    static b2World* get_instance() {
        static b2World instance({0, 0});
        return &instance;
    }
};

#endif  // ACID_INCLUDE_SINGLE_WORLD_H_
