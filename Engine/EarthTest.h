#include "Engine/TexturedGameObject.h"

using namespace z;

class EarthTest : protected TexturedGameObject {
	public:

	EarthTest(ResourceManager* man, float xi, float yi) : TexturedGameObject("Earth.png", man) {
		shape = (b2Shape*) new b2CircleShape();
		shape->m_radius = 5;
		dynamic = true;
		density = 5.0f;
		fixedRotation = false;
		friction = 0.9f;
		restitution = 0.01f;

		x = xi;
		y = yi;
	}

	virtual float shapeWidth() { return 10;}
	virtual float shapeHeight() {return 10;}
};
