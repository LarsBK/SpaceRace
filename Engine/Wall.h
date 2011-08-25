#ifndef WALL
#define WALL

#include "GameObject.h"

using namespace z;

class Wall : protected GameObject {
	
	float width,height;

	protected:
	sf::Drawable* getDrawable();

	public:
	Wall(float x, float y, float w, float h);

};

#endif
