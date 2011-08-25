#include "DynamicBox.h"

DynamicBox::DynamicBox(float x, float y) : GameObject(x,y) {

	//setAsDynamicBox(x,y,1.0f,1.0f);
	/*shape = s;
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(x,y);
	size = 4;
	b2PolygonShape shape;
	shape.SetAsBox(size/2, size/2);
	fixtureDef->shape = &shape;
	fixtureDef->density = 0.5;
	fixtureDef->friction = 0.5;
	*/

	//drawable = &sf::Shape::Rectangle(x,y,size,size,sf::Color::Red, 0.0f, sf::Color::Red);
}

/*
sf::Drawable DynamicBox::getDrawable() {
	b2Vec2 vec = body->GetPosition();
	float x = vec.x;
	float y = vec.y;
	drawable->SetPosition(x,y);
	return drawable;
}
*/
