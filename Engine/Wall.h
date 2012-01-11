#ifndef WALL_QLA6VZCV
#define WALL_QLA6VZCV

#include "Engine/GameObject.h"

class Wall : public z::GameObject {

	sf::Shape spr;
	unsigned int spWidth;
	unsigned int spHeight;
	float shWidth;
	float shHeight;

	public:
	Wall(float x1, float y1, float w, float h);
	virtual unsigned int spriteHeight() {return spHeight;}
	virtual unsigned int spriteWidth() {return spWidth;}
	virtual float shapeHeight() {return shHeight;}
	virtual float shapeWidth() {return shWidth;}


};

#endif /* end of include guard: WALL_QLA6VZCV */
