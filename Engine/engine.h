#ifndef ZENGINE
#define ZENGINE

#include <iostream>
#include <vector>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>



using namespace std;

namespace z {

	class Engine;
	class Console;

	//MODULE
	//Modules are loaded into the engine class
	class Module {
		public:
		Module(Engine*);
		~Module();

		//Events
		//virtual void update(float deltaTime);
		virtual void update(); //Called at beginning of every cycle
		virtual void onDraw(); //Called when time to draw
		virtual void onPhysics(); //Called at fixed interval

		protected:
		Engine* engine;
		string name;
		int id;
	};


	//ENGINE
	//Zengine's main class, holds all modules
	class Engine
	{
		//sf::Clock clock;
		//sf::Clock deltaClock;

		//List over all currently loaded modules
		vector<Module*> updateList;
		vector<Module*> drawList;
		vector<Module*> physicsList;
		//unsigned int threads;

		void update();
		void physics();
		void draw();

		//State
		bool needsDraw; //game state changed

		public:
		//Pointers
		//console *ptr_console;
		//sf::RenderWindow* window;
		//sf::View view;
		//unsigned int window_width;
		//unsigned int window_height;
		//bool running;
		
		float getTime();
		Engine();
		~Engine();
		void run();
		
		//protected:
		//Register modules
		unsigned int addPhysics(Module* Module);
		unsigned int addDraw(Module* Module);
		unsigned int addUpdate(Module* Module);
		//int removeModule(unsigned int moduleId);
		//void update();

	};


	//CONSOLE
	//Zengine will automagically spawn a console for its own use, however multiple consoles may be spawned
	//Zengine's console can be acsessed with the pointer member ptr_console e.g. : (*engine.prt_console) << "Hello world"
	//Different levels of imprortance in messages
	const unsigned int error = 0;
	const unsigned int warning = 10;
	const unsigned int info = 20;
	const unsigned int debug = 30;

	class Console : public Module
	{
		public:
		Console(Engine*);

		//Level to return level to after each use of <<
		unsigned int defaultLevel;

		//Max level shown to user
		unsigned int maxShow;

		//Max level shown to developer/debugger
		unsigned int maxConsole;

		//Level of next message
		unsigned int level;

		//Use (*engine.ptr_console) << "Hello world"
		void operator <<(string msg);

		//List of all messages, not currently implemented
		//vector <string> list;
	};

}

#endif
