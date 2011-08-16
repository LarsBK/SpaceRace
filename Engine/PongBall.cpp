#include "PongBall.h"

PongBall::PongBall() : GameObject() {
	x = 50;
	y = 30;
	radius = 5;
	dynamic = true;

	density = 0.1;
	friction = 1;
	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = radius;
	
	sprite = new sf::Shape(sf::Shape::Circle(0,0,radius,sf::Color::Red));
	//sprite->SetCenter(radius,radius);
}

void PongBall::onSpawn() {
	impulse(50000000000,0);
}

/*sf::Drawable PongBall::getDrawable() {
  b2Vec2 vec = body->GetPosition();
  float x = vec.x;
  float y = vec.y;
  float radius = 1.0f;
  sf::Shape s = sf::Shape::Circle(x,y,radius,sf::Color::White);
  return s;
  }*/
