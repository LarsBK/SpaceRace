#ifndef SPACERACE

#define SPACERACE
#include "Engine/Game.h"
#include "Engine/Engine.h"
#include "Engine/WindowModule.h"
#include "InGameState.h"
#include <string>

using namespace std;

class SpaceRace : public Game {

	private:
	z::Engine* engine;
	z::WindowModule* window;

	public:
	SpaceRace();
	virtual string getName();

};

#endif /* end of include guard: SpaceRace */
