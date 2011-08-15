#include "Wall.h"
#include "string.h"

Wall::Wall(float xi, float yi, float w, float h) {
	x = xi;
	y = yi;
	b2PolygonShape* s = new b2PolygonShape();
	s->SetAsBox(w,h);
	shape = s;
	sprite = new sf::Shape(sf::Shape::Rectangle(x,y,x+w,y+h,sf::Color::White));
}
