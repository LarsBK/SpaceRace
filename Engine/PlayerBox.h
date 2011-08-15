#ifndef PLAYERBOX
#define PLAYERBOX

#include "Engine.h"
#include "Event.h"
#include "PhysicsObject.h"
#include "WindowModule.h"
#include "GameObject.h"

using namespace z;

class PlayerBox : public ActionHandler, protected GameObject {

	//Actions
	Action* moveLeft;
	Action* moveRight;
	Action* moveUp;
	Action* moveDown;

	public:
	PlayerBox(float x, float y, Engine* engine);
	void handleAction(Action* a);
	//void draw(sf::RenderWindow* w);
};

#endif
