#ifndef PLANET_XGKTBIM

#define PLANET_XGKTBIM

#include "Engine/TexturedGameObject.h"

using namespace z;

class Planet : protected TexturedGameObject {
	
	float fakeMass;

	public:

	Planet(float xi, float yi, float r, float mass, string textureName, ResourceManager* man);
	virtual void onPhysicsStep();

	virtual float shapeWidth() { return shape->m_radius*2;}
	virtual float shapeHeight() {return shape->m_radius*2; }
};

#endif /* end of include guard: PLANET_XGKTBIM */
