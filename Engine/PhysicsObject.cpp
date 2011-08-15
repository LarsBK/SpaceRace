#include "PhysicsObject.h"
#include <iostream>

namespace z {
	PhysicsObject::PhysicsObject() {
		body = NULL;
		shape = NULL;
		density = 0;
		friction = 0;
		x = 0;
		y = 0;

		b2PolygonShape* s = new b2PolygonShape();
		s->SetAsBox(10.0f,10.0f);
		shape = s;
		density = 0.8;
		friction = 1;
	}

	b2Body* PhysicsObject::getBody() {
		return body;
	}

	b2BodyDef PhysicsObject::getBodyDef() {
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(x,y);
		
		return bodyDef;
	}

	void PhysicsObject::setBody(b2Body* b) {
		b2FixtureDef fix;
		fix.shape = shape;
		fix.density = density;
		fix.friction = friction;
		b->CreateFixture(&fix);
		body = b;
	}

	/*TestObject::TestObject(float x, float y) : PhysicsObject(x,y) {
		std::cout << "TestObject" << std::endl;
	}*/

}
