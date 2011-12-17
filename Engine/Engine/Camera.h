#ifndef CAMERA
#define CAMERA
#include "WindowModule.h"
#include "PhysicsObject.h"

namespace z {

	class CameraAction;
	class CameraZoomOut;
	
	class Camera {

		private:
		sf::View* view;
		PhysicsObject* f;
		int ppm;

		float xSpeed;
		float ySpeed;
		sf::Clock lastUpdate;

		void update();

		CameraZoomOut* zo;

		public:
		Camera(sf::View* v, Engine* e);
		~Camera();
		sf::View* getView();
		void setWindowSize(int w, int h);
		void follow(PhysicsObject* g);
		float meterToPixel(float m);
		void zoom(float f);
		void setSpeed(float x, float y);

	};

	class CameraAction : Action {
		protected:
		Camera* camera;

		public:
		CameraAction(Camera* c) {
			camera = c;
		}
	};

	class CameraZoomOut : protected CameraAction {
		public:
		CameraZoomOut(Camera* c) : CameraAction(c) {}

		virtual string toString() {
			return "camera_zoom_out";
		}

		virtual void fire(Event* e) {
			if(e->state == Event::STARTED)
				camera->zoom(0.5f);
		}
	};
}


#endif
