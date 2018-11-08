#ifndef ACID_INCLUDE_GAME_LOOP_H_
#define ACID_INCLUDE_GAME_LOOP_H_


#include <cstdlib>
#include <vector>

#include <base_system.h>
#include <entity_life_queue.h>
#include <entity_manager.h>

class GameLoop {
  public:
    GameLoop();
    ~GameLoop();

    void run();
    void terminate();

    void add_prototype(INode* node);  // TODO: reimplement this temporal solution later
    EntityLifeQueue* get_queue_ref();  //TODO: JESUS FUCKING CHRIST, this too
    void add_system(BaseSystem* system);  //TODO: ...

  protected:
    virtual void init();
    virtual void cycle();
    void process_lifetime();
    bool is_enabled = true;
    std::vector<BaseSystem*> systems;
    EntityLifeQueue queue;
    NodeManager n_manager;
    EntityManager e_manager = EntityManager(&n_manager);

};

#endif  // ACID_INCLUDE_GAME_LOOP_H_
