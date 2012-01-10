#include "Engine.h"
#include <SFML/System.hpp>

namespace z
{

	Engine::Engine(string name) {
		gameName = name;
		running = true;
		targetFramerate = 60;

		//Commands
		//quitAction = new Action("quit", this);
		//addAction(quitAction);
		//bind(new Event("quit"), quitAction);
	}

	Engine::~Engine() {
		eventBindings.clear();
		actions.clear();
		drawList.clear();
		physicsList.clear();
		updateList.clear();
	}

	string Engine::getName() {
		return gameName;
	}

	unsigned int Engine::addModule(Module* m) {
		updateList.push_back(m);
		physicsList.push_back(m);
		drawList.push_back(m);
		return updateList.size();
	}

	unsigned int Engine::getTargetFramerate() {
		return targetFramerate;
	}

	void Engine::run() {
		frameTime.Reset();
		running = true;
		clock.Reset();
		while(running) { 
			cycle();
		}
	}

	void Engine::cycle() {
		update();
		physics();
		if(needsDraw)
			draw();
	}

	void Engine::quit(string reason) {
		std::cout << "Quiting: " << reason << std::endl;
		running = false;
	}

	void Engine::quit() {
		quit("no reason given");
	}
	
	bool Engine::isRunning() {
		return running;
	}

	void Engine::update() {	
		float pTime = clock.GetElapsedTime();

		for (unsigned int i = 0; i < updateList.size(); i++) {
			updateList[i]->update(pTime);//delta);
		}
	}

	void Engine::physics() {
		float pTime = clock.GetElapsedTime();

		for (unsigned int i = 0; i < physicsList.size(); i++) {
			physicsList[i]->onPhysics(pTime);//delta);
		}
	}

	void Engine::draw() {
		needsDraw = false;
		float pTime = clock.GetElapsedTime();
		for (unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->onDraw(pTime);//delta);
		}
	}

	void Engine::needToDraw() {
		needsDraw = true;
	}

	float Engine::getTime() {
	  return clock.GetElapsedTime();
	}

	unsigned int Engine::getFPS() {
		return fps;
	}

	void Engine::setFPS(unsigned int f) {
		fps = f;
	}

	//Event
	void Engine::event(Event* e) {
		EventBinding* eb = getBinding(e->toString());
		cout << "Event: " << e->toString() << endl;
		if(eb) {
			eb->fire(e);
		}
/*
		for(unsigned int i = 0; i < eventBindings.size(); i++) {
			eventBindings[i]->fire(e);
		}
*/
	}

	void Engine::addAction(Action* a) {
		actions.push_back(a);
	}
	
	Action* Engine::getAction(string s) {
		for(unsigned int i = 0; i < actions.size(); i++) { 
			if(actions[i]->toString() == s)
				return actions[i];
		}
		std::cout << "no such action: " << s << std::endl;
		return NULL;
	}

	EventBinding* Engine::getBinding(string e) {
		for(int i = 0; i < eventBindings.size(); i++) {
			if(eventBindings[i]->equals(e)) {
				return eventBindings[i];
			}
		}
		return 0;
	}

	void Engine::bind(string e, string a) {
		EventBinding* eb = getBinding(e);
		if(eb == 0) {
			eb = new EventBinding(e);
			eventBindings.push_back(eb);
		}

		Action* c = getAction(a);
		if(c) {
			//bind(eb,c);
			eb->addAction(c);
			cout << e << " bound to " << c->toString() << endl;
		}
	}
/*
	void Engine::bind(Event* e, Action* a) {
		EventListener* l = new EventListener(e);
		l->addAction(a);
		eventListeners.push_back(l);
	}
*/
	//MODULE
	Module::Module(Engine *e) {
		engine = e;
	}

	void Module::onDraw(float t) {
		//cout << "onDraw() not implemented in " << name << endl;
	}

	void Module::update(float t) {
		//cout << "update() not implemented in " << name << endl;
	}

	void Module::onPhysics(float t) {
		//cout << "onPhysics() not implemented in " << name << endl;
	}

/*
	//CONSOLE
	void Console::operator <<(string msg)
	{
		if (level <= maxShow)
		{
			//messagebox
			cout << "Message: " << msg << endl;
		}
		if (level <= maxConsole)
		{
			//console
			cout << "Console: " << msg << endl;
		}
		level = defaultLevel;
	}

	Console::Console(Engine* e) : Module(e)
		{
			name = "ZConsole";
			defaultLevel = debug;
			maxShow = 0;
			maxConsole = debug;
			level = debug;
		}
*/
}
	
