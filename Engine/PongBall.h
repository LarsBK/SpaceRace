#ifndef PONGBALL
#define PONGBALL

#include "GameObject.h"

using namespace z;

class PongBall : public GameObject {

	public:
	PongBall();
	
	virtual b2BodyDef getBodyDef();
	virtual b2FixtureDef getFixtureDef();
	//sf::Drawable getDrawable();
};


#endif
