#ifndef GAME
#define GAME

#include <vector>
#include <string>
#include "GameState.h"

using namespace std;

class Game {

	vector <GameState*> states;
	
	public:
	virtual string getName() =0;
	void push(GameState* gs);
	void pop();
	int run();
};



#endif
