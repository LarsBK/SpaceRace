#ifndef EARTHTEST_6WLGZ8TG
#define EARTHTEST_6WLGZ8TG

#include "Engine/TexturedGameObject.h"

using namespace z;

class EarthTest : protected TexturedGameObject {
	
	float fakeMass;

	public:

	EarthTest(ResourceManager* man, float xi, float yi);
	virtual void onPhysicsStep();

	virtual float shapeWidth() { return shape->m_radius*2;}
	virtual float shapeHeight() {return shape->m_radius*2; }
};

#endif /* end of include guard: EARTHTEST_6WLGZ8TG */
