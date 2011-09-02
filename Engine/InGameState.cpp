#include "InGameState.h"

string InGameState::getName() {
	return "Ingame state";
}

InGameState::InGameState(z::Engine* e, z::WindowModule* w) {
	engine = e;
	window = w;
}

int InGameState::load(Game* game) {
	box2d = new z::Box2DModule(engine);
	engine->addModule(box2d);
}

int InGameState::run() {
	engine->run();
}

void InGameState::spawn(z::GameObject* g) {
	box2d->addObject((z::PhysicsObject*) g);
	window->add((z::Drawable*) g);
}
