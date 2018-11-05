#ifndef ACID_INCLUDE_EVENT_MANAGER_H_
#define ACID_INCLUDE_EVENT_MANAGER_H_


#include "game_state.h"
#include "entity.h"

class EventManager : public IObserver<INode> {
  public:
	EventManager();
	~EventManager();
	void add_entity(IEntity* entity);
	void delete_entity(IEntity* entity);
	GameState* get_gamestate(unsigned short node_type);

  private:
    GameState game_state;
};

#endif  // ACID_INCLUDE_EVENT_MANAGER_H_