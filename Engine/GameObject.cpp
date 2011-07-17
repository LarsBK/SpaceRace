#include "GameObject.h"

namespace z {

/*
	sf::Drawable GameObject::getDrawable() {
		drawable = sf::Shape::Rectangle(0,0,10,10);
		b2Vec2 vec = body->GetPosition();
		drawable.SetPosition(vec.x,vec.y);
		//update drawable
		return drawable;
	}
*/

	void GameObject::draw(sf::RenderWindow* w) {
		sf::Shape shape = sf::Shape::Rectangle(0.0f,0.0f,10.0f,10.0f, sf::Color::White, 0.0f, sf::Color::Black);
		b2Vec2 vec = body->GetPosition();
		shape.SetPosition(vec.x,vec.y);
		//update drawable
		w->Draw(shape);
	}

	GameObject::GameObject(float x, float y) :PhysicsObject(x,y) {
		//drawable = new sf::Shape

	}

}
