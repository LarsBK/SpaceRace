#ifndef INGAMESTATE

#define INGAMESTATE
#include "Engine/GameState.h"
#include "Engine/Engine.h"
#include "Engine/Box2DModule.h"
#include "Engine/WindowModule.h"
#include "Engine/GameObject.h"
#include <string>

using namespace std;

class InGameState : public GameState {
	
	z::Engine* engine;
	z::Box2DModule* box2d;
	z::WindowModule* window;

	void spawn(z::GameObject* g);
	
	public:
	virtual int run();
	virtual int load(Game* g);
	virtual string getName();
	InGameState(z::Engine* e, z::WindowModule* w);
};


#endif /* end of include guard: INGAMESTATE */
