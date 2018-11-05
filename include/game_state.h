#ifndef ACID_INCLUDE_GAME_STATE_H_
#define ACID_INCLUDE_GAME_STATE_H_

#include <vector>

class GameState {
 private:
	std::vector<INode*> updated_nodes; //TODO: hash table
 public:
 	void add_node(INode* node);
 	void get_nodes_of_type(unsigned short type);
 	void clear();
}

#endif // ACID_INCLUDE_GAME_STATE_H_