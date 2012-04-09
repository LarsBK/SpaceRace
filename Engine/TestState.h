#ifndef TESTSTATE_TRWH3NL2

#define TESTSTATE_TRWH3NL2

#include "Engine/GameState.h"
#include "Engine/Engine.h"
#include "Engine/Box2DModule.h"
#include "Engine/WindowModule.h"
#include "Engine/GameObject.h"
#include "RandomObject.h"
#include "Engine/ResourceManager.h"
#include "SpaceRaceMap.h"

#include "Engine/PerformanceMonitor.hpp"

#include <string>

using namespace std;

class TestState : public GameState {
	
	z::Engine* engine;
	z::Box2DModule* box2d;
	z::WindowModule* window;

	void spawn(z::GameObject* g);
	
	public:
	virtual int run();
	virtual int load(Game* g);
	virtual string getName();
	TestState(z::Engine* e, z::WindowModule* w);
	~TestState();
};

#endif /* end of include guard: TESTSTATE_TRWH3NL2 */
