#ifndef ACID_INCLUDE_EVENT_MANAGER_H_
#define ACID_INCLUDE_EVENT_MANAGER_H_

#include "game_state.h"
#include "i_entity.h"

class EventManager {
	GameState game_state;
  public:
	EventManager();
	~EventManager();
	add_entity(IEntity* entity);
	delete_entity(IEntity* entity);
	GameState* get_gamestate(unsigned short node_type);
};

#endif