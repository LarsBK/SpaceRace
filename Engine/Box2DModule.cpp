#include "Box2DModule.h"

namespace z {

	Box2DModule::Box2DModule(Engine* e) : Module(e) {
		name = "Box2DModule";
		gravity = new b2Vec2(0.0f, 9.81f);
		doSleep = true;
		world = new b2World(*gravity, doSleep);
		
		timeStep = 1.0f/engine->getTargetFramerate();
		velocityIterations = 6;
		positionIterations = 2;
		lastTime = 0;
		
		groundBodyDef.position.Set(0.0f, 100.0f);
		groundBodyDef.angle = 0.0f;
		groundBody = world->CreateBody(&groundBodyDef);

		groundShape.SetAsBox(200.0f, 5.0f);
		groundBody->CreateFixture(&groundShape, 0.0f);

		
	}

	void Box2DModule::addObject(PhysicsObject* o) {
		body = world->CreateBody(o->getBodyDef());
		//b2Body* body = world->CreateBody(o.getBodyDef());
		o->setBody(body);
		body->CreateFixture(o->getFixtureDef());
	}

	b2World* Box2DModule::getWorld() {
		return world;
	}

	void Box2DModule::onPhysics(float now) {
		//float delta = now - lastTime;
		/*while(lastTime+timeStep > now)
			sf::Sleep(timeStep/3);
		
*/
		unsigned int i = 0;

		while(lastTime+timeStep <= engine->getTime()) {
			world->Step(timeStep, velocityIterations, positionIterations);
			world->ClearForces();
			lastTime+=timeStep;
			i++;
			if(i > 5) {
				std::cout << "Trying to catch up " << i << std::endl;
			}
		}

		//std::cout << i << std::endl;
		
		if(i>0)
			engine->needToDraw();

	}
}
