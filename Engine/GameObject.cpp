#include "GameObject.h"

namespace z {

	void GameObject::draw(sf::RenderWindow* w) {
		b2Vec2 vec = body->GetPosition();
		float rot = body->GetAngle();
		sprite->SetRotation( -rot * (180/3.14));
		sprite->SetPosition(PM*vec.x,PM*vec.y);
		w->Draw(*sprite);
	}

	GameObject::GameObject() :PhysicsObject() {
		//sprite = new sf::Shape(sf::Shape::Rectangle(0,0,10.0f,10.0f, sf::Color::White,0.0f,sf::Color::Black));
	}

}
