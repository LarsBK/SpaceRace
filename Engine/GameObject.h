#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <Box2D/Box2D.h>
#include "PhysicsObject.h"
#include "WindowModule.h"

namespace z {

	class GameObject : protected PhysicsObject, protected Drawable {
		
		protected:
		sf::Drawable* sprite;

		public:
		GameObject();
		//virtual sf::Drawable getDrawable();
		virtual void draw(sf::RenderWindow* w);

	};
}

#endif
