#ifndef DEBUGDRAWMODULE
#define DEBUGDRAWMODULE

#include "DebugDraw.h"
#include "Engine.h"
#include "Box2DModule.h"

namespace z {

	class DebugDrawModule : public Module {
		sf::RenderWindow* window;
		Box2DModule* box2d;
		DebugDraw* debug;
		public:
		DebugDrawModule(Engine* e, Box2DModule* b);
		void onDraw();
	};
}

#endif
