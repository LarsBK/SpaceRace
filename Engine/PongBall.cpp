#include "PongBall.h"

PongBall::PongBall() : GameObject(100,100) {
	//float x = 100;
	//float y = 100;
	//float radius = 5;

	/*bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(x,y);
	
	b2CircleShape shape;
	fixtureDef->shape = &shape;
	fixtureDef->density = 1.0f;
	fixtureDef->friction = 0.8f;
	*/
}

/*sf::Drawable PongBall::getDrawable() {
	b2Vec2 vec = body->GetPosition();
	float x = vec.x;
	float y = vec.y;
	float radius = 1.0f;
	sf::Shape s = sf::Shape::Circle(x,y,radius,sf::Color::White);
	return s;
}*/
