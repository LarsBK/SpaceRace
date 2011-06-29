#include "PlayerBox.h"

PlayerBox::PlayerBox(float x, float y) {
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(x,y);
	shape->SetAsBox(2.0f, 2.0f);
	fixtureDef->shape = shape;
	fixtureDef->density = 1.0f;
	fixtureDef->friction = 0.8f;

	//Actions
	moveLeft = new Action("moveLeft", this);
	moveRight = new Action("moveRight", this);
	moveUp = new Action("moveUp", this);
	moveDown = new Action("moveDown", this);
}

void PlayerBox::handleAction(Action* a) {
	b2Vec2 pos = body->GetWorldCenter();
	b2Vec2 force;
	if(a == moveLeft) {
		force.Set(10,0);
		body->ApplyForce(force, pos);
	} else if(a == moveRight) {

	} else if(a == moveUp) {

	} else if(a == moveDown) {

	}
}

void PlayerBox::draw(sf::RenderWindow* w) {
	
}
