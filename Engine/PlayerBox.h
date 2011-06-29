#ifndef PLAYERBOX
#define PLAYERBOX

#include "Engine.h"
#include "Event.h"
#include "PhysicsObject.h"
#include "WindowModule.h"

using namespace z;

class PlayerBox : public ActionHandler, public Drawable, public PhysicsObject {

	//Actions
	Action* moveLeft;
	Action* moveRight;
	Action* moveUp;
	Action* moveDown;

	public:
	PlayerBox(float x, float y);
	void handleAction(Action* a);
	void draw(sf::RenderWindow* w);
};

#endif
