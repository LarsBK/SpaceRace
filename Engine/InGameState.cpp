#include "InGameState.h"

string InGameState::getName() {
	return "Ingame State";
}

InGameState::InGameState(z::Engine* e, z::WindowModule* w) {
	engine = e;
	window = w;
}

int InGameState::load(Game* game) {
	box2d = new z::Box2DModule(engine, 60, b2Vec2(0.0f, 9.81f), true);

	engine->addModule(box2d);
	return 0;
}

InGameState::~InGameState() {
	delete box2d;
}

int InGameState::run() {
	engine->run();
	return 0;
}

void InGameState::spawn(z::GameObject* g) {
	box2d->add((z::PhysicsObject*) g);
	window->add((z::Drawable*) g);
}
