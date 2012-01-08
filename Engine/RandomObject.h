#ifndef RANDOMOBJECT_R2PK9YMN

#define RANDOMOBJECT_R2PK9YMN

#include "Engine/GameObject.h"
#include <SFML/System.hpp>

class RandomObject : public z::GameObject {

	sf::Shape spr;
	public:
	RandomObject(float xi, float yi);

};

#endif /* end of include guard: RANDOMOBJECT_R2PK9YMN */
