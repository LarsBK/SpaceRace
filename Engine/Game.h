#ifndef GAME
#define GAME

#include <vector>
#include "GameState.h"

class Game {

	vector<GameState*> states;
	
	virtual string getName() =0;
	void push(GameState* gs);
	void pop();
	int run();
}



#endif
