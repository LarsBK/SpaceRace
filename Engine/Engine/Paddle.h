#ifndef PADDLE
#define PADDLE

#include "Engine.h"
#include "Event.h"
#include "GameObject.h"
#include "WindowModule.h"

using namespace z;

class Paddle : public ActionHandler, protected GameObject {

	//Actions
	Action* moveUp;
	Action* moveDown;
	float height,width;

	protected:
	virtual sf::Drawable* getDrawable();

	public:
	Paddle(string name, float x, float y, Engine* engine);
	void handleAction(Action* a);
};

#endif
