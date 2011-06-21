#include "Box2DModule.h"

namespace z {

	Box2DModule::Box2DModule(Engine* e) : Module(e) {
		gravity = new b2Vec2(0.0f, -9.81f);
		doSleep = true;
		world = new b2World(*gravity, doSleep);
		
		groundBodyDef.position.Set(0.0f, -10.0f);
		groundBody = world->CreateBody(&groundBodyDef);

		groundShape.SetAsBox(50.0f, 10.0f);
		groundBody->CreateFixture(&groundShape, 0.0f);
	}

	void Box2DModule::addObject(PhysicsObject* o) {
		body = world->CreateBody(o->getBodyDef());
		//b2Body* body = world->CreateBody(o.getBodyDef());
		o->setBody(body);
		body->CreateFixture(o->getFixtureDef());
	}

	void Box2DModule::onPhysics() {
		world->Step(timeStep, velocityIterations, positionIterations);
		world->ClearForces();

		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();

		std::cout << "x: " << position.x << " y: " << position.y
			<< " angle: " << angle << std::endl;
	}
}
