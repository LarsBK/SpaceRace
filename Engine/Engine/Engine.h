#ifndef ZENGINE
#define ZENGINE

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include "Event.h"

namespace z {

	class Engine;
	class Console;

	/** Modules are loaded into the engine class
	* The will be called to do work three times
	* per step. update(), onDraw() and onPhysics()
	*/
	class Module {
		public:
			Module(Engine*);

			//Events
			//virtual void update(float deltaTime);
			virtual void update(float time); //Called at beginning of every cycle
			virtual void onDraw(float time); //Called when time to draw
			virtual void onPhysics(float time); //Called at fixed interval

		protected:
			Engine* engine;
			string name;
			int id;
	};


	//ENGINE
	//Zengine's main class, holds all modules
	class Engine : public ActionHandler
	{
		sf::Clock clock;
		sf::Clock frameTime;
		
		unsigned int targetFramerate;
		bool running;
		string gameName;
		unsigned int fps;

		//List over all currently loaded modules
		vector<Module*> updateList;
		vector<Module*> drawList;
		vector<Module*> physicsList;

		vector<EventListener*> eventListeners;
		vector<Action*> actions;
		EventListener* getEventListener(Event* e);
		Action* getAction(string s);

		//Actions
		Action* quitAction;

		void update();
		void physics();
		void draw();

		//State
		bool needsDraw; //game state changed

		public:
		float getTime();
		Engine(string name);
		~Engine();
		void run();
		void cycle();
		void quit(string reason);
		void quit();
		bool isRunning();
		string getName();
		unsigned int getTargetFramerate();
		unsigned int getFPS();
		void setFPS(unsigned int f);

		void needToDraw();

		//Register modules
		unsigned int addModule(Module* m);
		//int removeModule(unsigned int moduleId);

		//Event
		void event(Event* e); //An event has occured
		void addAction(Action* a); //Add supported action
		void bind(Event* e, string a); //Binds
		void bind(Event* e, Action* a); //Binds

		//ActionHandler
		void handleAction(Action* a);
	};

/*
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
*/
}

#endif
