#include "PongBall.h"

PongBall::PongBall(float start) : GameObject() {
	x = 4;
	y = 2.25;
	startSpeed = start;
	radius = 0.05;
	dynamic = true;

	density = 1;
	restitution = 1.07;
	friction = 0;
	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = radius;
	
	sprite = new sf::Shape(sf::Shape::Circle(0,0,radius*PM,sf::Color::White));
	//sprite->SetCenter(radius*PM,radius*PM);
}

void PongBall::onSpawn() {
	setVelocity(startSpeed,0.1);
}

/*sf::Drawable PongBall::getDrawable() {
  b2Vec2 vec = body->GetPosition();
  float x = vec.x;
  float y = vec.y;
  float radius = 1.0f;
  sf::Shape s = sf::Shape::Circle(x,y,radius,sf::Color::White);
  return s;
  }*/
