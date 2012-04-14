#include "Thruster.hpp"

Thruster::Thruster(Engine* e) :
		TexturedGameObject("Earth.png", e->resourceManager()),
		ta(this) {
	e->addAction(&ta);

	dynamic = true;
	x = -200;
	y = -400;
	
	b2PolygonShape* b = new b2PolygonShape();
	b->SetAsBox(5,5);
	shape = b;

	fixedRotation = false;
	density = 1;
	friction = 0.5;
	restitution = 0.1;

	e->bind("keyboard_k", ta.toString());
}

ThrustAction::ThrustAction(Thruster* t) {
	thruster = t;
}

void ThrustAction::fire(Event* e) {
	if(e->state == Event::STARTED) {
		thruster->applyForce(b2Vec2(0,1000));
	} else {
		thruster->applyForce(b2Vec2(0,-1000));
	}

}
