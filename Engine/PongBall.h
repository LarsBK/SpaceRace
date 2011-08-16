#ifndef PONGBALL
#define PONGBALL

#include "GameObject.h"

using namespace z;

class PongBall : protected GameObject {

	float radius;

	public:
	PongBall();
	virtual void onSpawn();
	
	//virtual b2BodyDef getBodyDef();
	//virtual b2FixtureDef getFixtureDef();
	//sf::Drawable getDrawable();
};


#endif
