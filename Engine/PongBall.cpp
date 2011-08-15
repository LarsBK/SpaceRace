#include "PongBall.h"

PongBall::PongBall() : GameObject() {
	x = 100;
	y = 100;
	radius = 5;

	density = 1;
	friction = 1;
	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = radius;
	
	sprite = new sf::Shape(sf::Shape::Circle(x,y,radius,sf::Color::Red));
	sprite->SetCenter(2.5,2.5);
}

/*sf::Drawable PongBall::getDrawable() {
	b2Vec2 vec = body->GetPosition();
	float x = vec.x;
	float y = vec.y;
	float radius = 1.0f;
	sf::Shape s = sf::Shape::Circle(x,y,radius,sf::Color::White);
	return s;
}*/
