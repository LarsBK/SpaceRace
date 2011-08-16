#include "Paddle.h"

Paddle::Paddle(string name, float xi, float yi, Engine* engine) {
	x = xi;
	y = yi;
	density = 10000;
	friction = 0;
	restitution = 10000;
	//fixedRotation = true;
	dynamic = true;
	float height = 100;
	float width = 10;

	b2PolygonShape* s = new b2PolygonShape();
	s->SetAsBox(width/2, height/2);
	shape = s;

	sprite = new sf::Shape(sf::Shape::Rectangle(0,0,width,height,sf::Color::White));
	sprite->SetCenter(width/2,height/2);

	//Actions
	moveUp = new Action(name+" up", this);
	moveDown = new Action(name+" down", this);
	engine->addAction(moveUp);
	engine->addAction(moveDown);
}

void Paddle::handleAction(Action* a) {
	if(a->getEvent()->state == Event::STARTED) {
		if(a == moveUp)
			setVelocity(0,-1000);
		else 
			setVelocity(0,1000);
	} else {
		setVelocity(0,0);
	}
}
