#include "Box2DModule.h"

namespace z {

	Box2DModule::Box2DModule(Engine* e, int fps, b2Vec2 gravity, bool allowSleep) : Module(e) {
		name = "Box2DModule";
		
		world = new b2World(gravity); //, allowSleep);
		world->SetAutoClearForces(true);
		world->SetAllowSleeping(allowSleep);
		timeStep = 1.0f/fps;
		velocityIterations = 8;
		positionIterations = 3;
		lastTime = e->getTime();
	}

	Box2DModule::~Box2DModule() {
		while(! list.empty()) {
			list.back()->setBody(0);
			list.pop_back();
		}
		delete world;
	}

	void Box2DModule::addObject(PhysicsObject* o) {
		b2BodyDef def = o->getBodyDef();
		b2Body* b = world->CreateBody(&def);
		o->setBody(b);
		list.push_back(o);
	}

	b2World* Box2DModule::getWorld() {
		return world;
	}

	void Box2DModule::onPhysics(float now) {

		//Saves cpu time, more inputlag
		//while(lastTime+timeStep > engine->getTime())
		//	sf::Sleep(engine->getTime()-(lastTime+timeStep));
		

		unsigned int i = 0;

		while(lastTime+timeStep <= engine->getTime()) {

			for(unsigned x = 0; x < list.size(); x++) {
				list[x]->onPhysicsStep();
			}

			world->Step(timeStep, velocityIterations, positionIterations);
			lastTime+=timeStep;
			i++;
			if(i % 120 == 0) {
				std::cout << "WARNING: physics fell 120 steps behind, fast-forwarding. Please report this as a bug." << std::endl;
				float ff;
				do {
					ff = engine->getTime() - lastTime;
					world->Step(ff,	velocityIterations, positionIterations);
					lastTime+=ff;
				} while(lastTime+timeStep < engine->getTime());

			}
		}

		if(i > 0) {
			/*
			//Smoooooooth
			float smooth = engine->getTime()-lastTime;
			world->Step(smooth, velocityIterations, positionIterations);
			lastTime+=smooth;
			*/
			
			//if(i>0)
				engine->needToDraw();
		}
		
	}
}
