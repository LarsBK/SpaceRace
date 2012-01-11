#include "Wall.h"

Wall::Wall(float x1, float y1, float w, float h) {
	x = x1;
	y = y1;

	dynamic = false;

	shape = (b2Shape*) new b2PolygonShape();
	((b2PolygonShape*) shape)->SetAsBox(w/2.0f, h/2.0f);
	spr = sf::Shape::Rectangle(0,0,100*w,100*h, sf::Color::White);

	sprite = &spr;
	spWidth = 100*w;
	spHeight = 100*h;
	shHeight = h;
	shWidth = w;

}

