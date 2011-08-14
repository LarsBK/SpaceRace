#include "PhysicsObject.h"
#include <iostream>

namespace z {
	PhysicsObject::PhysicsObject(float xi, float yi) {
		body = NULL;
		x = xi;
		y = yi;
		//bodyDef = new b2BodyDef();
		//shape = new b2PolygonShape();
		//fixtureDef = new b2FixtureDef();
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

	b2FixtureDef PhysicsObject::getFixtureDef() {
		b2PolygonShape* shape;
		shape->SetAsBox(10.0f,10.0f);
		
		b2FixtureDef fix;
		fix.shape = shape;
		fix.density = 1.0f;
		fix.friction = 0.8f;
		
		return fix;
	}
/*
	void PhysicsObject::setAsDynamicBox(float x, float y, float w, float h) {
		bodyDef->type = b2_dynamicBody;
		bodyDef->position.Set(x,y);
		b2PolygonShape shape;
		shape.SetAsBox(w, h);
		fixtureDef->shape = &shape;
		fixtureDef->density = 1.0f;
		fixtureDef->friction = 0.8f;
	}
*/


	void PhysicsObject::setBody(b2Body* b) {
		b2PolygonShape shape;
		shape.SetAsBox(10.0f,10.0f);
		
		b2FixtureDef fix;
		fix.shape = &shape;
		fix.density = 1.0f;
		fix.friction = 0.8f;
		b->CreateFixture(&fix);
		body = b;
	}

	TestObject::TestObject(float x, float y) : PhysicsObject(x,y) {
		std::cout << "lol2" << std::endl;
		//setAsDynamicBox(x,y,1.0f,1.0f);
	}

}
