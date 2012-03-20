#include "RandomObject.h"

RandomObject::RandomObject(float xi, float yi) {
	x = xi;
	y = yi;

	dynamic = true;
	srand(time(NULL));

	int randomShape = rand() % 2;
	randomSize = 0.1f * (rand() % 80); //0.1f, 8.0f);

	int red = rand() % 256;
	int green = rand() % 256;
	int blue = rand() % 256;

	if(randomShape) {
		shape = (b2Shape*) new b2CircleShape();
		shape-> m_radius = randomSize/2.0f;
		sprite = new sf::CircleShape();
	} else {
		sf::Vector2f sizevec(randomSize*10, randomSize*10);
		shape = (b2Shape*) new b2PolygonShape();
		((b2PolygonShape*) shape)->SetAsBox(randomSize/2.0f, randomSize/2.0f);
		sprite = new sf::RectangleShape(sizevec);
		//, sf::Color(red,green,blue));
	}

	((sf::Shape*) sprite)->setFillColor(sf::Color(red, green, blue));

	fixedRotation = false;
	density = 1.0f;
	friction = 0.5;
	restitution = 0.1;

}

void RandomObject::onSpawn() {
	impulse(0,10000);
}
