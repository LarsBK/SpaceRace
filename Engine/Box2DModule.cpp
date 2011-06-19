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

		//Dynamic body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(0.0f, 4.0f);
		body = world->CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.0f, 1.0f);

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 1.0f;

		// Override the default friction.
		fixtureDef.friction = 0.3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);

		// Prepare for simulation. Typically we use a time step of 1/60 of a
		// second (60Hz) and 10 iterations. This provides a high quality simulation
		// in most game scenarios.
		timeStep = 1.0f / 60.0f;
		velocityIterations = 6;
		positionIterations = 2;
	
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
