#include "Wall.h"
#include "string.h"

Wall::Wall(float xi, float yi, float w, float h) : GameObject(xi,yi) {
	x = xi;
	y = yi;
	width = w;
	height = h;
}

b2BodyDef Wall::getBodyDef() {
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x,y);
	return bodyDef;
}

b2FixtureDef Wall::getFixtureDef() {
	b2PolygonShape* shape = new b2PolygonShape;
	shape->SetAsBox(width,height);
	b2FixtureDef fix;
	fix.shape = shape;
	return fix;
}

void Wall::draw(sf::RenderWindow* w) {
	sf::Shape shape = sf::Shape::Rectangle(x,y,x+width,y+height,sf::Color::White, 0.0f, sf::Color::Black);
	w->Draw(shape);
}
