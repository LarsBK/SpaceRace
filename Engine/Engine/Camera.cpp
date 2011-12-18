#include "Camera.h"

namespace z {

	void CameraZoom::fire(Event* e) {
		if(e->state == Event::STARTED)
			camera->zoom(factor);
	}



//Camera
	Camera::Camera(sf::Window* w, Engine* e) : zo(this,0.9,"out"), zi(this,1.1,"in") {
		f = 0;
		sf::Vector2f center(0,0);
		sf::Vector2f halfSize(w->GetWidth(), w->GetHeight());
		view = new sf::View(center, halfSize);

		xSpeed = 0;
		ySpeed = 0;

		e->addAction((Action*) &zo);
		e->addAction((Action*) &zi);
		e->bind("keyboard_z", zo.toString());
		e->bind("keyboard_x", zi.toString());
	}

	void Camera::follow(PhysicsObject* g) {
		f = g;
	}

	sf::View* Camera::getView() {
		update();
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

	void Camera::zoom(float f) {
		view->Zoom(f);
	}

	void Camera::setSpeed(float x, float y) {
		xSpeed = x;
		ySpeed = y;
	}

	void Camera::update() {
		float delta = lastUpdate.GetElapsedTime();
		lastUpdate.Reset();

		view->Move(xSpeed*delta, ySpeed*delta);
	}

	

}
