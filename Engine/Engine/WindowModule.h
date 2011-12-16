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
	class FullscreenAction;

	class WindowModule : public Module {
		sf::RenderWindow* window;
		bool fullscreen;
		Camera* camera;
		FullscreenAction* fullscreenAction;

		bool* pressed;

		vector<Drawable*> drawList;

		public:
		WindowModule(Engine* e);
		~WindowModule();
		void update(float time);
		void onDraw(float time);

		void drawFps(int f);

		void vsync(bool v);
		void toggleFullscreen();
		Camera* getCamera();

		void add(Drawable* d);
	};

	class FullscreenAction : public Action {
		WindowModule* wm;
		public:
		FullscreenAction(WindowModule* w);
		void fire(Event* e);
		string getName();
		string toString();
	};

	class Drawable {
		public:
		virtual void draw(sf::RenderWindow* w) =0;

	};

	static string charToString(char c);

}


#endif
