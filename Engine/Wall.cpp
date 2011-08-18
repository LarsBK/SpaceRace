#include "Wall.h"
#include "string.h"

Wall::Wall(float xi, float yi, float w, float h) {
	x = xi;
	y = yi;
	density = 0;
	restitution = 0;
	b2PolygonShape* s = new b2PolygonShape();
	s->SetAsBox(w/2,h/2);
	shape = s;
	sprite = new sf::Shape(sf::Shape::Rectangle(0,0,w*PM,h*PM,sf::Color::White));
	sprite->SetCenter(w/2.0f*PM,h/2.0f*PM);
}
