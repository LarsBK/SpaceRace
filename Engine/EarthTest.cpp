#include "EarthTest.h"

EarthTest::EarthTest(ResourceManager* man, float xi, float yi) : TexturedGameObject("Earth.png", man) {
	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = 100;
	dynamic = false;
	density = 100000000000000000000000000000000.0f;
	fakeMass = 100000;//5.9736e1024;
	fixedRotation = false;
	friction = 0.9f;
	restitution = 0.01f;

	x = xi;
	y = yi;
}

void EarthTest::onPhysicsStep() {
	b2World* w = body->GetWorld();

	b2Body* next = w->GetBodyList();
	while(next) {
		b2Vec2 direction = body->GetPosition() - next->GetPosition();
		float length = direction.Length();
		direction.Normalize(); //range 0 to 1
		float forceOfGravity = 
			6.67384 * ( (fakeMass * next->GetMass()) /
			(length*length));

		direction*= forceOfGravity;
		next->ApplyForceToCenter(direction);
		next = next->GetNext();
	}
}

