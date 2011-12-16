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
		
		protected:
		sf::Drawable* sprite;

		//These are used to scale the sprite
		unsigned int spriteWidth;
		unsigned int spriteHeight;
		float shapeWidth;
		float shapeHeight;

		virtual sf::Drawable* getDrawable();

		public:
		GameObject();
		virtual void draw(WindowModule* wm);

	};
}

#endif
