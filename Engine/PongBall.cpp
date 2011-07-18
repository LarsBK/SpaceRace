#include "PongBall.h"

PongBall::PongBall() : GameObject(50,50) {
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

b2BodyDef PongBall::getBodyDef() {
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position.Set(100,100);
	return def;
}

b2FixtureDef PongBall::getFixtureDef() {
	b2CircleShape* shape = new b2CircleShape;
	shape->m_radius = 1;
	b2FixtureDef fix;
	fix.shape = shape;
	fix.density = 1.0f;
	fix.friction = 0;
	fix.restitution = 1.2f;
	return fix;
}

/*sf::Drawable PongBall::getDrawable() {
  b2Vec2 vec = body->GetPosition();
  float x = vec.x;
  float y = vec.y;
  float radius = 1.0f;
  sf::Shape s = sf::Shape::Circle(x,y,radius,sf::Color::White);
  return s;
  }*/
