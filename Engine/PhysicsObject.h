#ifndef PHYSICSOBJECT
#define PHYSICSOBJECT

#include <Box2D/Box2D.h>

namespace z {

	class PhysicsObject {
		protected:
		b2Body* body;
		
		b2Shape* shape;
		float density;
		float friction;
		float x;
		float y;
		
		public:
		PhysicsObject();
		b2Body* getBody();
		void setBody(b2Body* b);
		virtual b2BodyDef getBodyDef();

	};
/*
	class TestObject : public PhysicsObject {
		public:
		TestObject(float x, float y);
	};
*/
}

#endif
