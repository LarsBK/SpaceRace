#include "Camera.h"

namespace z {

	Camera::Camera(sf::View* v) {
		f = 0;
		view = v;
	}

	void Camera::follow(PhysicsObject* g) {
		f = g;
	}

	sf::View* Camera::getView() {
		if(f) {
			b2Vec2 vec = f->getBody()->GetPosition();
			float x = meterToPixel(vec.x);
			float y = meterToPixel(vec.y);
			view->SetCenter(x, y);
			
		}
		return view;
	}

	float Camera::meterToPixel(float m) {
		return m*ppm;
	}

	void Camera::setWindowSize(int w, int h) {
		view->SetHalfSize(w/2.0f, h/2.0f);
		ppm = w/METERINWIDTH;
	}
}
