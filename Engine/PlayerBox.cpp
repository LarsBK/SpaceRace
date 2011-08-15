#include "PlayerBox.h"

PlayerBox::PlayerBox(float xi, float yi, Engine* engine) : GameObject() {
	//bodyDef->type = b2_dynamicBody;
	//bodyDef->position.Set(x,y);
	//b2PolygonShape shape;
	//shape.SetAsBox(2.0f, 2.0f);
	//fixtureDef->shape = &shape;
	//fixtureDef->density = 1.0f;
	//fixtureDef->friction = 0.8f;
	x = xi;
	y = yi;
	density = 1;
	friction = 1;

	//Actions
	moveLeft = new Action("moveLeft", this);
	moveRight = new Action("moveRight", this);
	moveUp = new Action("moveUp", this);
	moveDown = new Action("moveDown", this);
	engine->addAction(moveLeft);

}

void PlayerBox::handleAction(Action* a) {
	b2Vec2 pos = body->GetWorldCenter();
	b2Vec2 force;
	if(a == moveLeft) {
		force.Set(-5000,0);
		body->ApplyLinearImpulse(force, pos);
	} else if(a == moveRight) {

	} else if(a == moveUp) {

	} else if(a == moveDown) {

	}
}

/*void PlayerBox::draw(sf::RenderWindow* w) {
	//w->DrawRect(	
}*/
