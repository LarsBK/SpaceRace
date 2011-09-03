#ifndef CAMERA
#define CAMERA
#include "WindowModule.h"
#include "PhysicsObject.h"

namespace z {
	
	class Camera {

		private:
		sf::View* view;
		PhysicsObject* f;
		int ppm;

		public:
		Camera(sf::View* v);
		sf::View* getView();
		void setWindowSize(int w, int h);
		void follow(PhysicsObject* g);
		float meterToPixel(float m);

	};
}


#endif
