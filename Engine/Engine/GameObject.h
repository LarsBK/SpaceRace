#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <Box2D/Box2D.h>
#include "PhysicsObject.h"
#include "WindowModule.h"

//#define SCREEN_WIDTH 1024
//#define PM (SCREEN_WIDTH/8.0f)
//#define MP (1.0f/PM)


namespace z {

	class GameObject : protected PhysicsObject, protected Drawable {
		
		private:
		sf::Drawable* sprite;
		sf::RenderWindow* window;
		int screenWidth;
		protected:
		virtual sf::Drawable* getDrawable();
		float meterToPixel(float m);

		public:
		GameObject();
		//virtual sf::Drawable getDrawable();
		virtual void draw(sf::RenderWindow* w);

	};
}

#endif
