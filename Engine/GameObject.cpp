#include "GameObject.h"

namespace z {

	void GameObject::draw(sf::RenderWindow* w) {
		if(body) {
			int width = w->GetWidth();
			if (screenWidth != width) {
				screenWidth = width;
				sprite = getDrawable();
			}
			if(sprite) {
				b2Vec2 vec = body->GetPosition();
				float rot = body->GetAngle();
				sprite->SetRotation( -rot * (180/3.14));
				sprite->SetPosition(meterToPixel(vec.x),meterToPixel(vec.y));
				w->Draw(*sprite);
			}
		}
	}

	float GameObject::meterToPixel(float m) {
		int ppm = screenWidth/METERINWIDTH;
		return m*ppm;
	}

	sf::Drawable* GameObject::getDrawable() {
		return NULL;
	}

	GameObject::GameObject() :PhysicsObject() {
		//sprite = new sf::Shape(sf::Shape::Rectangle(0,0,10.0f,10.0f, sf::Color::White,0.0f,sf::Color::Black));
	}

}
