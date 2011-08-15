#ifndef PONGBALL
#define PONGBALL

#include "GameObject.h"

using namespace z;

class PongBall : protected GameObject {

	float radius;

	public:
	PongBall();
	//sf::Drawable getDrawable();
};


#endif
