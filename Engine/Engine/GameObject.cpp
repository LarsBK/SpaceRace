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

			sf::Drawable* d = getDrawable();
			sf::Transformable* t = getTransformable();

			if(t) {
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

				cout << "scale" << scaleW << endl;

				t->setOrigin(spriteWidth()/2.0f, spriteHeight()/2.0f);
				t->setScale(scaleW, scaleH);
				t->setRotation( rot * (180/3.14));
				t->setPosition(wm->meterToPixel(renderPos.x),
					wm->meterToPixel(renderPos.y));
			} else {
				cerr << "Gameobject without transformable" << endl;
			}

			if(d) {
				w->draw(*((sf::Drawable*) d));
			} else {
				cerr << "Gameobject without sprite" << endl;
			}
		} else {
			cerr << "GameObject without body" << endl;
		}
	}

	void GameObject::prePhysicsStep(float last, float t) {
		cout << "OMG" << endl;
		storeOldPos(last,t);
	}

	void GameObject::storeOldPos(float last, float t) {
		timeStep = t;
		lastPos = body->GetPosition();
		lastTime = last;
	}
}
