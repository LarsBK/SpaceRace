#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <Box2D/Box2D.h>
#include "PhysicsObject.h"
#include "WindowModule.h"

namespace z {

	class GameObject : public PhysicsObject, public Drawable {
		
		protected:
		b2Vec2 lastPos;
		float lastTime;
		float timeStep;

		//These are used to scale the sprite
		virtual unsigned int spriteHeight()=0;
		virtual unsigned int spriteWidth()=0;
		virtual float shapeHeight()=0;
		virtual float shapeWidth()=0;

		virtual sf::Drawable* getDrawable() = 0;
		virtual sf::Transformable* getTransformable() =0;

		public:
		virtual void draw(WindowModule* wm, float now);

		virtual void prePhysicsStep(float last, float t);
		void storeOldPos(float acc, float t);
	};
}

#endif
