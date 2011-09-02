#include "Game.h"

void Game::push(GameState* gs) {
	if(! gs->load(this))
		states.push_back(gs);
}

void Game::pop() {
	states.pop_back();
}

int Game::run() {
	int v = 0;
	while(states.size() > 0) {
		v = states.back()->run();
		states.pop_back();
		if(v)
			return v;
	}
	return 0;
}
