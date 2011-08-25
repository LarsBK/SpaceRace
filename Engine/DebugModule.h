#ifndef DEBUGDRAWMODULE
#define DEBUGDRAWMODULE

#include "DebugDraw.h"
#include "Engine.h"
#include "Box2DModule.h"
#include <SFML/Graphics.hpp>
#include <sstream>

namespace z {

	class DebugDrawModule : public Module {
		sf::RenderWindow* window;
		Box2DModule* box2d;
		DebugDraw* debug;

		//void drawFps();
		public:
		DebugDrawModule(Engine* e, Box2DModule* b);
		void onDraw(float time);
		void update(float time);
	};
}

#endif
