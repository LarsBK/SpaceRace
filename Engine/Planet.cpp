#include "Planet.h"

Planet::Planet(float xi, float yi, float radius, float mass, bool d,
		float xS, float yS,	string textureName, ResourceManager* man) :
			TexturedGameObject(textureName, man) {
	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = radius;
	dynamic = d;
	density = mass;
	fakeMass = mass;
	fixedRotation = false;
	friction = 0.9f;
	restitution = 0.01f;
	xSpeed = xS;
	ySpeed = yS;

	x = xi;
	y = yi;
}

void Planet::onSpawn() {
	setVelocity(xSpeed,ySpeed);
}

void Planet::onPhysicsStep() {
	b2World* w = body->GetWorld();

	b2Body* next = w->GetBodyList();
	while(next) {
		if(next != body) {
		b2Vec2 direction = body->GetPosition() - next->GetPosition();
		float length = direction.Length();
		direction.Normalize(); //range 0 to 1
		float forceOfGravity = 
			6.67384 * ( (fakeMass * next->GetMass()) /
			(length*length));

		direction*= forceOfGravity;
		next->ApplyForceToCenter(direction);
		}
		next = next->GetNext();
	}
}

