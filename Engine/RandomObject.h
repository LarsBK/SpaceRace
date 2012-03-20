#ifndef RANDOMOBJECT_R2PK9YMN

#define RANDOMOBJECT_R2PK9YMN

#include "Engine/GameObject.h"
#include <SFML/System.hpp>
#include <time.h>

class RandomObject : public z::GameObject {

	float randomSize;
	public:
	RandomObject(float xi, float yi);

	virtual void onSpawn();

	virtual unsigned int spriteHeight() {return 100;}
	virtual unsigned int spriteWidth() {return 100;}
	virtual float shapeHeight() {return randomSize;}
	virtual float shapeWidth() {return randomSize;}

};

#endif /* end of include guard: RANDOMOBJECT_R2PK9YMN */
