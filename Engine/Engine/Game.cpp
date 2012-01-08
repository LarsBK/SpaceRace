#include "Game.h"

Game::~Game() {
	states.clear();
}

void Game::push(GameState* gs) {
//	if(! gs->load(this))
		states.push_back(gs);
}

void Game::pop() {
	states.pop_back();
}

int Game::run() {
	int v = 0;
	while(states.size() > 0) {
		GameState* gs = states.back();
		states.pop_back();
		cout << "Loading " << gs->getName() << "...";
		if( gs->load(this) == 0) {
			cout << "done!" << endl;
			v = gs->run();
			if(v)
				return v;
		} else
			cout << "Failed!" << endl;
	}
	return 0;
}
