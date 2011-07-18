#ifndef PHYSICSOBJECT
#define PHYSICSOBJECT

#include <Box2D/Box2D.h>

namespace z {

	class PhysicsObject {
		protected:
		b2Body* body;
		//b2BodyDef* bodyDef;
		//b2FixtureDef* fixtureDef;
		//b2Shape* shape;
		float x;
		float y;
		
		public:
		PhysicsObject(float x, float y);
		b2Body* getBody();
		void setBody(b2Body* b);
		virtual b2BodyDef getBodyDef() =0;
		virtual b2FixtureDef getFixtureDef() =0;

		void setAsDynamicBox(float x, float y, float w, float h);
	};

	class TestObject : public PhysicsObject {
		public:
		TestObject(float x, float y);
	};
}

#endif
