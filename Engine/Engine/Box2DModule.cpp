#include "Box2DModule.h"

namespace z {

	Box2DModule::Box2DModule(Engine* e, int fps, b2Vec2 gravity, bool allowSleep) : Module(e) {
		name = "Box2DModule";
		
		world = new b2World(gravity, allowSleep);
		timeStep = 1.0f/fps;
		velocityIterations = 8;
		positionIterations = 3;
		lastTime = e->getTime();
	}

	Box2DModule::~Box2DModule() {
		delete world;
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
			sf::Sleep(engine->getTime()-(lastTime+timeStep));
		

		unsigned int i = 0;

		while(lastTime+timeStep <= engine->getTime()) {
			world->Step(timeStep, velocityIterations, positionIterations);
			world->ClearForces();
			lastTime+=timeStep;
			i++;
			if(i > 30) {
				std::cout << "Trying to catch up " << i << std::endl;
			}
		}

		//Smoooooooth
		float smooth = engine->getTime()-lastTime;
		world->Step(smooth, velocityIterations, positionIterations);
		lastTime+=smooth;
		
		//if(i>0)
			engine->needToDraw();
		
	}
}
