#include "GameObject.h"

namespace z {

	void GameObject::draw(WindowModule* wm) {
		sf::RenderWindow* w = wm->getWindow();
		if(body) {
			
			/*int width = w->GetWidth();
			if (screenWidth != width) {
				screenWidth = width;
				sprite = getDrawable();
			}*/

			if(sprite) {


				b2Vec2 vec = body->GetPosition();
				float rot = body->GetAngle();

				float scaleW = wm->meterToPixel(shapeWidth())
					/ (float) spriteWidth();
				float scaleH = wm->meterToPixel(shapeHeight())
					/ (float) spriteHeight();

				sprite->setOrigin(spriteWidth()/2.0f, spriteHeight()/2.0f);
				sprite->setScale(scaleW, scaleH);
				sprite->setRotation( -rot * (180/3.14));
				sprite->setPosition(wm->meterToPixel(vec.x),
					wm->meterToPixel(vec.y));
				w->draw(*((sf::Drawable*) sprite));
			}
		}
	}

	GameObject::GameObject() :PhysicsObject() {
		//sprite = new sf::Shape(sf::Shape::Rectangle(0,0,10.0f,10.0f, sf::Color::White,0.0f,sf::Color::Black));
		sprite = 0;
	}

}
