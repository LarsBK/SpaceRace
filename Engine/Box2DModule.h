#ifndef BOX2DMODULE
#define BOX2DMODULE

#include <Box2D/Box2D.h>
#include <iostream>
#include "Engine.h"
#include "PhysicsObject.h"


namespace z {
	
	class Box2DModule : public Module {
		public:
		Box2DModule(Engine* e);
		void onPhysics(float now);
		void addObject(PhysicsObject* o);
		b2World* getWorld();

		private:
		float32 timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		float lastTime;

		b2Vec2* gravity;
		bool doSleep;
		b2World* world;

		b2BodyDef groundBodyDef;
		b2Body* groundBody;
		b2PolygonShape groundShape;

		b2Body* body;
		
	};
}

#endif
