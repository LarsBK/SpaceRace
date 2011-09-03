#include "Paddle.h"

Paddle::Paddle(string name, float xi, float yi, Engine* engine) {
	x = xi;
	y = yi;
	density = 5;
	friction = 0;
	restitution = 0.5;
	//fixedRotation = true;
	dynamic = true;
	height = 0.6;
	width = 0.08;

	b2PolygonShape* s = new b2PolygonShape();
	s->SetAsBox(width/2, height/2);
	shape = s;

	//Actions
	moveUp = new Action(name+" up", this);
	moveDown = new Action(name+" down", this);
	engine->addAction(moveUp);
	engine->addAction(moveDown);
}

sf::Drawable* Paddle::getDrawable() {
	sf::Drawable* d = new sf::Shape(sf::Shape::Rectangle(0,0,meterToPixel(width),meterToPixel(height),sf::Color::White));
	d->SetCenter(meterToPixel(width/2),meterToPixel(height/2));
	return d;
}

void Paddle::handleAction(Action* a) {
	if(a->getEvent()->state == Event::STARTED) {
		if(a == moveUp)
			setVelocity(0,-0.8);
		else 
			setVelocity(0,0.8);
	} else {
		setVelocity(0,0);
	}
}
