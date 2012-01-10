#include "RandomObject.h"

RandomObject::RandomObject(float xi, float yi) {
	x = xi;
	y = yi;

	dynamic = true;


	int randomShape = sf::Randomizer::Random(0,1);
	float randomSize = sf::Randomizer::Random(0.1f, 10.0f);

	int red = sf::Randomizer::Random(0,255);
	int green = sf::Randomizer::Random(0,255);
	int blue = sf::Randomizer::Random(0,255);

	spriteWidth = 64;
	spriteHeight = 64;

	if(randomShape) {
		shape = (b2Shape*) new b2CircleShape();
		shape-> m_radius = randomSize/2.0f;
		spr = sf::Shape::Circle(32,32,32, sf::Color(red, green, blue));
	} else {
		shape = (b2Shape*) new b2PolygonShape();
		((b2PolygonShape*) shape)->SetAsBox(randomSize/2.0f, randomSize/2.0f);
		spr = sf::Shape::Rectangle(0,0,64,64, sf::Color(red,green,blue));
	}

	sprite = &spr;
	shapeHeight = randomSize;
	shapeWidth = randomSize;

	fixedRotation = false;
	density = 1.0f;
	friction = 0.5;
	restitution = 0.1;

}

