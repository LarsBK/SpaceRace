#include "Game.h"

Game::~Game() {
	states.clear();
}

void Game::push(GameState* gs) {
	cout << "Loading " << gs->getName() << endl;
	if(gs->load(this) == 0) {
		states.push_back(gs);
		cout << "done!" << endl;
	} else {
		cout << "FAILED!" << endl;
	}
}

void Game::pop() {
	states.pop_back();
}

int Game::run() {
	int v = 0;
	while(states.size() > 0) {
		GameState* gs = states.back();
		states.pop_back();
		//cout << "Loading " << gs->getName() << "...";
		//if( gs->load(this) == 0) {
		//	cout << "done!" << endl;
			v = gs->run();
			if(v)
				return v;
		//} else
		//	cout << "Failed!" << endl;
	}
	return 0;
}
