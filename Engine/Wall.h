#ifndef WALL_QLA6VZCV
#define WALL_QLA6VZCV

#include "Engine/GameObject.h"

class Wall : public z::GameObject {

	sf::Shape spr;
	public:
	Wall(float x1, float y1, float w, float h);

};

#endif /* end of include guard: WALL_QLA6VZCV */
