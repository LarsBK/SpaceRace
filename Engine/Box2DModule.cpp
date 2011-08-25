#include "Box2DModule.h"

namespace z {

	Box2DModule::Box2DModule(Engine* e) : Module(e) {
		name = "Box2DModule";
		gravity = new b2Vec2(0.0f, 0.0f);
		doSleep = true;
		world = new b2World(*gravity, doSleep);
		
		timeStep = 1.0f/120; //engine->getTargetFramerate();
		velocityIterations = 6;
		positionIterations = 2;
		lastTime = 0;
	}

	void Box2DModule::addObject(PhysicsObject* o) {
		b2BodyDef def = o->getBodyDef();
		b2Body* b = world->CreateBody(&def);
		o->setBody(b);
	}

	b2World* Box2DModule::getWorld() {
		return world;
	}

	void Box2DModule::onPhysics(float now) {

		//Saves cpu time, more inputlag
		while(lastTime+timeStep > engine->getTime())
			sf::Sleep(timeStep/3);
		

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
		
		if(i>0)
			engine->needToDraw();

	}
}
