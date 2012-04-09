#include "Planet.h"

Planet::Planet(float xi, float yi, float radius, float den, bool d,
		float xS, float yS,	string textureName, ResourceManager* man) :
	TexturedGameObject(textureName, man) {
		shape = (b2Shape*) new b2CircleShape();
		shape->m_radius = radius;
		dynamic = d;
		density = den;
		fakeMass = den*M_PI*radius*radius;
		fixedRotation = false;
		friction = 0.9f;
		restitution = 0.01f;
		xSpeed = xS;
		ySpeed = yS;

		x = xi;
		y = yi;
	}

Planet::Planet(TiXmlElement* planet, z::Engine* e) : TexturedGameObject(e->resourceManager()) {

	TiXmlElement* dynamicNode = planet->FirstChildElement("dynamic");
	dynamic = false;
	if(dynamicNode) {
		dynamic = (string(dynamicNode->GetText()) == "true");
	}

	fixedRotation = false;
	friction = 0.9f;
	restitution = 0.01f;
	shape = (b2Shape*) new b2CircleShape();

	x = atof(planet->FirstChildElement("x")->GetText());
	y = atof(planet->FirstChildElement("y")->GetText());
	density = atof(planet->FirstChildElement("density")->GetText());
	shape->m_radius = atof(planet->FirstChildElement("radius")->GetText());
	fakeMass = density*M_PI*shape->m_radius*shape->m_radius;

	TiXmlElement* temp = 0;
	temp = planet->FirstChildElement("xSpeed");
	if(temp)
		xSpeed = atof(temp->GetText());
	temp = planet->FirstChildElement("ySpeed");
	if(temp)
		ySpeed = atof(temp->GetText());

	string texture = planet->FirstChildElement("texture")->GetText();
	setTexture(texture);
}

void Planet::onSpawn() {
	setVelocity(xSpeed,ySpeed);
}

void Planet::prePhysicsStep(float now, float t) {
	cout << "omg1" << endl;
	storeOldPos(now,t);
	b2World* w = body->GetWorld();

	b2Body* next = w->GetBodyList();
	while(next) {
		if(next != body) {
			b2Vec2 direction = body->GetPosition() - next->GetPosition();
			float length = direction.Length();
			direction.Normalize(); //range 0 to 1
			float forceOfGravity = 
				6.67384 * ( (fakeMass * next->GetMass()) /
						(length*length));

			direction*= forceOfGravity;
			next->ApplyForceToCenter(direction);
		}
		next = next->GetNext();
	}
}

