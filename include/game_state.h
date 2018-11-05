#ifndef ACID_INCLUDE_GAME_STATE_H_
#define ACID_INCLUDE_GAME_STATE_H_


#include <vector>

#include <i_node.h>

class GameState {
 public:
 	void add_node(INode* node);
 	void get_nodes_of_type(unsigned short type);
 	void clear();

 private:
	std::vector<INode*> updated_nodes; //TODO: hash table
};

#endif  // ACID_INCLUDE_GAME_STATE_H_