#ifndef GAME
#define GAME

#include <vector>
#include <string>
#include <iostream>
#include "GameState.h"

using namespace std;

class GameState;

class Game {

	vector <GameState*> states;

	
	public:
	~Game();
	virtual string getName() =0;
	void push(GameState* gs);
	void pop();
	int run();
};



#endif
