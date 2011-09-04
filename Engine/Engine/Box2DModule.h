#ifndef BOX2DMODULE
#define BOX2DMODULE

#include <Box2D/Box2D.h>
#include <iostream>
#include "Engine.h"
#include "PhysicsObject.h"


namespace z {
	
	/**The physics module
	*/
	class Box2DModule : public Module {
		public:
		/**
		* @param e pointer to the engine
		* @param fps the number of times physics will be updated per secound.
		* @param gravity the gravityvector of the world
		* @param allowSleep allow inactive objects to sleep to save cpu time
		*/
		Box2DModule(Engine* e, int fps, b2Vec2 gravity, bool allowSleep);
		~Box2DModule();
		void onPhysics(float now);
		void addObject(PhysicsObject* o);
		b2World* getWorld();

		private:
		float32 timeStep;
		int32 velocityIterations;
		int32 positionIterations;

		float lastTime;

		b2World* world;
		
	};
}

#endif
