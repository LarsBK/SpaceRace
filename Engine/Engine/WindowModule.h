#ifndef WINDOWMODULE
#define WINDOWMODULE

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include <iostream>
#include <sstream>

#define METERINWIDTH 8.0f

namespace z {

	class Drawable;
	class Camera;

	class WindowModule : public Module, public ActionHandler {
		sf::RenderWindow* window;
		bool fullscreen;
		Camera* camera;

		Action* fullscreenAction;

		bool* pressed;

		vector<Drawable*> drawList;

		public:
		WindowModule(Engine* e);
		~WindowModule();
		void update(float time);
		void onDraw(float time);

		void drawFps(int f);

		void handleAction(Action* a);
		
		void vsync(bool v);
		void toggleFullscreen();
		Camera* getCamera();

		void add(Drawable* d);
	};

	class Drawable {
		public:
		virtual void draw(sf::RenderWindow* w) =0;

	};

	static string charToString(char c);

}


#endif
