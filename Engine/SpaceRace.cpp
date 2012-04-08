#include "SpaceRace.h"
#include "TestState.h"

string SpaceRace::getName() {
	string s;
	s += "Space Race! (built: ";
	s += __DATE__;
	s += " ";
	s += __TIME__;
	s += ")";
	return s;
}

SpaceRace::SpaceRace() {
	engine = new z::Engine(getName());
	window = new z::WindowModule(engine);
	engine->addModule(window);
	
	//push(new InGameState(engine, window));
	push(new TestState(engine, window));
	//push(new BenchmarkState(engine, window));
}

SpaceRace::~SpaceRace() {
	delete engine;
	delete window;
}
