#ifndef PLANET_XGKTBIM

#define PLANET_XGKTBIM

#include "Engine/TexturedGameObject.h"

using namespace z;

class Planet : protected TexturedGameObject {
	
	float fakeMass;
	float xSpeed;
	float ySpeed;

	public:

	Planet(float xi, float yi, float r, float mass, bool d,
		float xS, float yS, string textureName, ResourceManager* man);
	virtual void onPhysicsStep();

	virtual float shapeWidth() { return shape->m_radius*2;}
	virtual float shapeHeight() {return shape->m_radius*2; }
	virtual void onSpawn();
	
};

#endif /* end of include guard: PLANET_XGKTBIM */
