#ifndef ACID_INCLUDE_GAME_LOOP_H_
#define ACID_INCLUDE_GAME_LOOP_H_


#include <cstdlib>
#include <vector>

#include <base_system.h>
#include <entity_life_queue.h>
#include <entity_manager.h>
#include <entity_life_system.h>
#include <terminator_system.h>

class GameLoop {
  public:
    GameLoop(bool is_server);
    ~GameLoop();

    void run();
    void terminate();

    void add_prototype(INode* node);  // TODO: reimplement this temporal solution later
    void add_system(BaseSystem* system);  // TODO: ...

    void register_life_system(EntityLifeSystem* system) {
        system->set_queue(&queue);
    }

    EntityManager* get_entity_manager() {
        return &e_manager;
    }

    void register_term_system(TerminatorSystem* system) {  // TODO: reimplement later
        system->set_terminator(&is_enabled);
    }

  protected:
    virtual void init();
    virtual void cycle();
    void process_lifetime();
    bool is_enabled = true;
    std::vector<BaseSystem*> systems;
    EntityLifeQueue queue;
    NodeManager n_manager;
    EntityManager e_manager;

};

#endif  // ACID_INCLUDE_GAME_LOOP_H_
