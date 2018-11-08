#ifndef ACID_INCLUDE_GAME_LOOP_H_
#define ACID_INCLUDE_GAME_LOOP_H_


#include <cstdlib>
#include <vector>

#include <i_system.h>
#include "entity_manager.h"

class GameLoop {
  public:
    GameLoop();
    ~GameLoop();

    void run();
    void terminate();

  protected:
    virtual void init();
    virtual void cycle();
    //float tick_time;
    bool is_enabled = true;
    std::vector<ISystem*> systems;
    EntityLifeQueue queue;
    NodeManager n_manager;
    EntityManager e_manager = EntityManager(&n_manager);

};

#endif  // ACID_INCLUDE_GAME_LOOP_H_
