#include "Game.h"

void Game::push(GameState* gs) {
	states.push_back(gs);
}

void Game::pop() {
	states.pop();
}

int run() {
	int v = 0;
	while(states.size() > 0) {
		for(unsigned int i = 0; i < states.size(); i++) {
			v = states[i]->step();
			if(v)
				return v;
		}
	}
	return 0;
}
