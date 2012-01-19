#include "GameObject.h"

namespace z {

	void GameObject::draw(WindowModule* wm, float now) {
		sf::RenderWindow* w = wm->getWindow();
		if(body) {
			
			/*int width = w->GetWidth();
			if (screenWidth != width) {
				screenWidth = width;
				sprite = getDrawable();
			}*/

			if(sprite) {

				float deltaTime = (now - lastTime) / timeStep;

				b2Vec2 nextPos = body->GetPosition();
				b2Vec2 deltaPos = nextPos - lastPos;
				deltaPos *= deltaTime;
				b2Vec2 renderPos = lastPos + deltaPos;


				float rot = body->GetAngle();

				float scaleW = wm->meterToPixel(shapeWidth())
					/ (float) spriteWidth();
				float scaleH = wm->meterToPixel(shapeHeight())
					/ (float) spriteHeight();

				sprite->SetCenter(spriteWidth()/2.0f, spriteHeight()/2.0f);
				sprite->SetScale(scaleW, scaleH);
				sprite->SetRotation( -rot * (180/3.14));
				sprite->SetPosition(wm->meterToPixel(renderPos.x),
					wm->meterToPixel(renderPos.y));
				w->Draw(*sprite);
			}
		}
	}

	GameObject::GameObject() :PhysicsObject() {
		//sprite = new sf::Shape(sf::Shape::Rectangle(0,0,10.0f,10.0f, sf::Color::White,0.0f,sf::Color::Black));
		sprite = 0;
	}

	void GameObject::prePhysicsStep(float last, float t) {
		storeOldPos(last,t);
	}

	void GameObject::storeOldPos(float last, float t) {
		timeStep = t;
		lastPos = body->GetPosition();
		lastTime = last;
	}
}
