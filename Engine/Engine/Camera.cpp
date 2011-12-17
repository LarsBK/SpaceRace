#include "Camera.h"

namespace z {

	Camera::Camera(sf::View* v, Engine* e) {
		f = 0;
		view = v;
		zo = new CameraZoomOut(this);
		e->addAction((Action*) zo);
		e->bind("keyboard_z", zo->toString());
	}

	Camera::~Camera() {
		delete zo;
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
