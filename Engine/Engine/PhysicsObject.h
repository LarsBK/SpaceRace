#ifndef PHYSICSOBJECT
#define PHYSICSOBJECT

#include <Box2D/Box2D.h>

namespace z {

	class PhysicsObject {
		protected:
		b2Body* body;
		
		b2Shape* shape;

		b2Vec2 force;

		float density;
		float friction;
		float x;
		float y;
		bool dynamic;
		bool fixedRotation;
		float restitution;
		
		public:

		virtual void onPhysicsStep();

		PhysicsObject();
		b2Body* getBody();
		void setBody(b2Body* b);
		b2BodyDef getBodyDef();
		virtual void onSpawn();
		void impulse(float x, float y);
		void setVelocity(float x, float y);

	};
/*
	class TestObject : public PhysicsObject {
		public:
		TestObject(float x, float y);
	};
*/
}

#endif
