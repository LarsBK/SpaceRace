#ifndef DYNAMICBOX
#define DYNAMICBOX

#include "Engine.h"
#include "PhysicsObject.h"
#include "WindowModule.h"
#include "GameObject.h"

using namespace z;

class DynamicBox : protected GameObject {

	unsigned int size;

	public:
	//void draw(sf::RenderWindow* w);
	DynamicBox(float x, float y);
	//sf::Drawable getDrawable();

};

#endif
