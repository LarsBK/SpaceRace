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
	
	//sprite = new sf::Shape(sf::Shape::Circle(0,0,radius*PM,sf::Color::White));
	//sprite->SetCenter(radius*PM,radius*PM);
}


void PongBall::onSpawn() {
	setVelocity(startSpeed,0.1);
}

sf::Drawable* PongBall::getDrawable() {
  return new sf::Shape(sf::Shape::Circle(0,0,meterToPixel(radius),sf::Color::White));
}
