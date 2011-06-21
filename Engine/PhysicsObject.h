#ifndef PHYSICSOBJECT
#define PHYSICSOBJECT

#include <Box2D/Box2D.h>

namespace z {

	class PhysicsObject {
		protected:
		b2Body* body;
		b2BodyDef* bodyDef;
		b2FixtureDef* fixtureDef;
		b2PolygonShape* shape;
		
		public:
		PhysicsObject();
		b2Body* getBody();
		void setBody(b2Body* b);
		b2BodyDef* getBodyDef();
		b2FixtureDef* getFixtureDef();
	};

	class TestObject : public PhysicsObject {
		public:
		TestObject(float x, float y);
	};
}

#endif
