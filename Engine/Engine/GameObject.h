#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <Box2D/Box2D.h>
#include "PhysicsObject.h"
#include "WindowModule.h"

namespace z {

	class GameObject : protected PhysicsObject, protected Drawable {
		
		protected:
		sf::Transformable* sprite;

		//These are used to scale the sprite
		virtual unsigned int spriteHeight()=0;
		virtual unsigned int spriteWidth()=0;
		virtual float shapeHeight()=0;
		virtual float shapeWidth()=0;

		public:
		GameObject();
		virtual void draw(WindowModule* wm);

/*
		virtual void onPhysicsStep() {
			cout << "A";
		}
*/

	};
}

#endif
