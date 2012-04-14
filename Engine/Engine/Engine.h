#ifndef ZENGINE
#define ZENGINE

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include "Event.h"
#include "split.h"
#include "ResourceManager.h"

namespace z {

	class Engine;
	class Console;
	class ResourceManager;

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
	class Engine 
	{
		sf::Clock clock;
		sf::Clock frameTime;
		
		unsigned int targetFramerate;
		bool running;
		string gameName;
		unsigned int fps;

		//List over all currently loaded modules
		vector<Module*> updateList;
		//vector<Module*> drawList;
		//vector<Module*> physicsList;

		vector<EventBinding*> eventBindings;
		vector<Action*> actions;
		EventBinding* getEventBinding(string e);
		Action* getAction(string s);

		//Actions
		//Action* quitAction;

		void update();
		void physics();
		void draw();

		ResourceManager resMan;
		
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

		//Performance analysis
		float updateTime;
		float physicsTime;
		float drawTime;

		float getDrawTime();
		float getPhysicsTime();
		float getUpdateTime();


		//Register modules
		void addModule(Module* m);
		//int removeModule(unsigned int moduleId);

		//Event
		void event(Event* e); //An event has occured
		void addAction(Action* a); //Add supported action
		void bind(string e, string a); //Binds
		EventBinding* getBinding(string e);
		//void bind(Event* e, Action* a); //Binds

		//ActionHandler
		//void handleAction(Action* a);

		ResourceManager* resourceManager() {
			return &resMan;
		}
	};
/*
	class CommandEvent : public Event {
		public:
		vector<string> words;
		Event(string s) {
			words = split(s, ' ');
		}
		string toString() {
			return vector[0];
		}
	};


	class BindAction : public Action {
		Engine* engine;
		public:
		BindAction(Engine* e) {
			engine = e;
		}

		virtual void fire(Event* e) {
			string s = e->toString();
			int pos = e.find(" ");
			if(pos = npos) return;


			engine->bind( e->
		virtual void
*/

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
