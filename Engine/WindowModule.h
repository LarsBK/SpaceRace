#ifndef WINDOWMODULE
#define WINDOWMODULE

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

namespace z {

	class Drawable;

	class WindowModule : public Module, public ActionHandler {
		sf::RenderWindow* window;
		bool fullscreen;

		Action* fullscreenAction;

		bool* pressed;

		vector<Drawable*> drawList;

		public:
		WindowModule(Engine* e);
		void update(float time);
		void onDraw(float time);

		void handleAction(Action* a);
		void toggleFullscreen();

		void add(Drawable* d);
	};

	class Drawable {
		public:
		virtual void draw(sf::RenderWindow* w);
	};

	static string charToString(char c);

}


#endif
