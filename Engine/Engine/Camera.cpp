#include "Camera.h"

namespace z {

	void CameraZoom::fire(Event* e) {
		if(e->state == Event::STARTED)
			camera->zoom(factor);
		else
			camera->zoom(0);
	}

	void CameraMove::fire(Event* e) {
		if(e->state == Event::STARTED) {
			camera->setSpeed(x,y);
		} else {
			camera->setSpeed(-x,-y);
		}
	}
/*
	void CameraRotate::fire(Event* e) {
		if(e->state == Event::STARTED) {
			camera->setRotation(r);
		} else {
			camera->setRotation(-r);
		}
	}
*/

//Camera
	Camera::Camera(sf::Window* w, Engine* e) :
			zo(this,0.9,"out"),
			zi(this,-0.9,"in"),
			ml(this,-8,0,"left"),
			mr(this,8,0,"right"),
			mu(this,0,-8,"up"),
			md(this,0,8,"down") {
		f = 0;
		sf::Vector2f center(0,0);
		sf::Vector2f halfSize(w->GetWidth(), w->GetHeight());
		view = new sf::View(center, halfSize);
		ppm = halfSize.x/METERINWIDTH;
		view->Zoom(0.2);

		xSpeed = 0;
		ySpeed = 0;

		e->addAction((Action*) &zo);
		e->addAction((Action*) &zi);
		e->addAction((Action*) &ml);
		e->addAction((Action*) &mr);
		e->addAction((Action*) &mu);
		e->addAction((Action*) &md);

		e->bind("keyboard_z", zo.toString());
		e->bind("keyboard_x", zi.toString());
		e->bind("keyboard_w", mu.toString());
		e->bind("keyboard_a", ml.toString());
		e->bind("keyboard_s", md.toString());
		e->bind("keyboard_d", mr.toString());
	}

	void Camera::follow(PhysicsObject* g) {
		f = g;
	}

	sf::View* Camera::getView() {
		//update();
		if(f) {
			b2Vec2 vec = f->getBody()->GetPosition();
			float x = meterToPixel(vec.x);
			float y = meterToPixel(vec.y);
			view->SetCenter(x, y);
			
		} else {
			view->Move(xSpeed*lastMove.GetElapsedTime(), ySpeed*lastMove.GetElapsedTime());
			lastMove.Reset();
			
			if(zoomFactor != 0) {
				view->Zoom(1.0f + zoomFactor*lastZoom.GetElapsedTime()); //lastZoomFactor);
				lastZoom.Reset();
			}
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
		zoomFactor = f;
		lastZoom.Reset();
	}

	void Camera::setSpeed(float x, float y) {
		xSpeed += meterToPixel(x);
		ySpeed += meterToPixel(y);
		lastMove.Reset();
	}

/*
	void Camera::update() {
		float delta = lastUpdate.GetElapsedTime();
		lastUpdate.Reset();

		view->Move(xSpeed*delta, ySpeed*delta);
	}
*/
	

}
