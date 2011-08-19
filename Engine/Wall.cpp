#include "Wall.h"
#include "string.h"

Wall::Wall(float xi, float yi, float w, float h) {
	x = xi;
	y = yi;
	width = w;
	height = h;
	density = 0;
	restitution = 0;
	b2PolygonShape* s = new b2PolygonShape();
	s->SetAsBox(w/2,h/2);
	shape = s;
}

sf::Drawable* Wall::getDrawable() {
	sf::Drawable* d = new sf::Shape(sf::Shape::Rectangle(0,0,meterToPixel(width),meterToPixel(height),sf::Color::White));
	d->SetCenter(meterToPixel(width/2.0f),meterToPixel(height/2.0f));
	return d;
}
