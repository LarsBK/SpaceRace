#ifndef WALL
#define WALL

#include "GameObject.h"

using namespace z;

class Wall : protected GameObject {
	
	float width,height;

	public:
	Wall(float x, float y, float w, float h);
	//virtual b2BodyDef getBodyDef();
	//virtual b2FixtureDef getFixtureDef();

};

#endif
