#ifndef CAMERA
#define CAMERA
#include "WindowModule.h"
#include "PhysicsObject.h"

namespace z {

	class Camera;

	class CameraAction : Action {
		protected:
		Camera* camera;

		public:
		CameraAction(Camera* c) {
			camera = c;
		}
	};

	class CameraZoom : protected CameraAction {
		float factor;
		string str;
		public:
		CameraZoom(Camera* c, float f, string s) : CameraAction(c) {
			factor = f;
			str = s;
		}
		virtual string toString() {return "camera_zoom_" + str;}
		virtual void fire(Event* e);
	};

	class Camera {

		private:
		sf::View* view;
		PhysicsObject* f;
		int ppm;

		float xSpeed;
		float ySpeed;
		sf::Clock lastUpdate;

		void update();

		CameraZoom zo; //zoom out
		CameraZoom zi; //zoom in
		//CameraMove ml

		public:
		Camera(sf::Window* w, Engine* e);
		~Camera();
		sf::View* getView();
		void setWindowSize(int w, int h);
		void follow(PhysicsObject* g);
		float meterToPixel(float m);
		void zoom(float f);
		void setSpeed(float x, float y);

	};

//	class CameraMove : protected CameraAction {
//		public
}


#endif
