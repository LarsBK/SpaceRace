#include "PhysicsObject.h"

namespace z {
	PhysicsObject::PhysicsObject() {
		body = NULL;
		bodyDef = new b2BodyDef();
		shape = new b2PolygonShape();
		fixtureDef = new b2FixtureDef();
	}

	b2Body* PhysicsObject::getBody() {
		return body;
	}

	b2BodyDef* PhysicsObject::getBodyDef() {
		return bodyDef;
	}

	b2FixtureDef* PhysicsObject::getFixtureDef() {
		return fixtureDef;
	}

	void PhysicsObject::setBody(b2Body* b) {
		body = b;
	}

	TestObject::TestObject(float x, float y) {
		bodyDef->type = b2_dynamicBody;
		bodyDef->position.Set(x,y);
		bodyDef->angle = 3.2/4;
		shape->SetAsBox(1.0f, 1.0f);
		fixtureDef->shape = shape;
		fixtureDef->density = 1.0f;
		fixtureDef->friction = 0.8f;

	}

}
