#ifndef WINDOWMODULE
#define WINDOWMODULE

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

namespace z {

	class WindowModule : public Module, public ActionHandler {
		sf::RenderWindow* window;
		bool fullscreen;

		Action* fullscreenAction;

		public:
		WindowModule(Engine* e);
		void update(float time);
		void handleAction(Action* a);
		void toggleFullscreen();
	};
}


#endif
