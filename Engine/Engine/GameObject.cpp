#include "GameObject.h"

namespace z {

	void GameObject::draw(WindowModule* wm) {
		sf::RenderWindow* w = wm->getWindow();
		if(body) {
			sf::Drawable* texture = getDrawable();
			
			/*int width = w->GetWidth();
			if (screenWidth != width) {
				screenWidth = width;
				sprite = getDrawable();
			}*/

			if(texture) {
				b2Vec2 vec = body->GetPosition();
				float rot = body->GetAngle();

				float scaleW = wm->meterToPixel(shapeWidth)
					/ (float) spriteWidth;
				float scaleH = wm->meterToPixel(shapeHeight)
					/ (float) spriteHeight;

				texture->SetScale(scaleW, scaleH);
				texture->SetRotation( -rot * (180/3.14));
				texture->SetPosition(wm->meterToPixel(vec.x),
					wm->meterToPixel(vec.y));
				w->Draw(*texture);
			}
		}
	}

	sf::Drawable* GameObject::getDrawable() {
		return sprite;
	}

	GameObject::GameObject() :PhysicsObject() {
		//sprite = new sf::Shape(sf::Shape::Rectangle(0,0,10.0f,10.0f, sf::Color::White,0.0f,sf::Color::Black));
	}

}
