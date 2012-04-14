#include "PhysicsObject.h"
#include <iostream>

namespace z {
	PhysicsObject::PhysicsObject() :force(0,0) {
		body = NULL;
		shape = NULL;
		dynamic = true;
		density = 1;
		friction = 0.5;
		x = 0;
		y = 0;

		fixedRotation = false;
		restitution = 0;
	}

	b2Body* PhysicsObject::getBody() {
		return body;
	}

	b2BodyDef PhysicsObject::getBodyDef() {
		b2BodyDef bodyDef;
		if(dynamic)
			bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(x,y);
		bodyDef.fixedRotation = fixedRotation;

		return bodyDef;
	}

	void PhysicsObject::setBody(b2Body* b) {
		b2FixtureDef fix;
		fix.shape = shape;
		fix.density = density;
		fix.friction = friction;
		fix.restitution = restitution;
		b->CreateFixture(&fix);
		body = b;
		onSpawn();
	}

	void PhysicsObject::onSpawn() {
	}

	void PhysicsObject::impulse(float xi, float yi) {
		b2Vec2 pos = body->GetWorldCenter();
		b2Vec2 force;
		force.Set(xi,yi);
		body->ApplyLinearImpulse(force,pos);
	}

	void PhysicsObject::setVelocity(float xi, float yi) {
		b2Vec2 vec;
		vec.x = xi;
		vec.y = yi;
		body->SetLinearVelocity(vec);
	}

	/*TestObject::TestObject(float x, float y) : PhysicsObject(x,y) {
	  std::cout << "TestObject" << std::endl;
	  }*/

	void PhysicsObject::prePhysicsStep(float now, float timeStep) {
		if(force.x != 0 || force.y != 0) {
			body->ApplyForceToCenter(body->GetWorldVector(force));
		}
	}

}
