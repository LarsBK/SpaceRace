#include "Planet.h"

class Asteroid : Planet {

	Asteroid(float x, float y, float r, float mass,
		string textureName, ResourceManager* man) :
		Planet(x,y,r,mass,textureName,man) {

		dynamic = true;
	}
};
