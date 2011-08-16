#include "Engine.h"
#include <SFML/System.hpp>

namespace z
{

	//ENGINE
	Engine::Engine(string name) {
		gameName = name;
		running = true;
		targetFramerate = 60;

		//Commands
		quitAction = new Action("quit", this);
		addAction(quitAction);
		bind(new Event("quit"), quitAction);
	}

	string Engine::getName() {
		return gameName;
	}

	void Engine::handleAction(Action* a) {
		if(a == quitAction)
			quit("Event");
		std::cout << a->getName() << std::endl;
	}

	Engine::~Engine() {
		drawList.clear();
		physicsList.clear();
		updateList.clear();
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

	//Event
	void Engine::event(Event* e) {
		std::cout << "event occured: " << e->getString() << std::endl;
		//EventListener* l = getEventListener(e);
		for(unsigned int i = 0; i < eventListeners.size(); i++) {
			eventListeners[i]->fire(e);
		}
	}

	void Engine::addAction(Action* a) {
		std::cout << "added action " << a->getName() << std::endl;
		actions.push_back(a);
	}
	
	//buggy
	Action* Engine::getAction(string s) {
		for(unsigned int i = 0; i < actions.size(); i++) { 
			if(actions[i]->equals(s))
				return actions[i];
		}
		std::cout << "no such action" << s << std::endl;
		return NULL;
	}

	void Engine::bind(Event* e, string a) {
		Action* c = getAction(a);
		if(c)
			bind(e,c);
	}

	void Engine::bind(Event* e, Action* a) {
		EventListener* l = new EventListener(e);
		l->addAction(a);
		eventListeners.push_back(l);
	}

	/*void Engine::addEventListener(Event* e, string a) {
		Action* c = getAction(a);
		if(c) {
			EventListener* l = new EventListener(e);
			l->addAction(c);
			eventListeners.push_back(l);
		}
	}

	void Engine::bind(Event* e, Action* a) {
		Event* e = getEvent(event);
		EventListener* l = getEventListener(listener);

		if(e == NULL) {
			e = new Event(event);
			events.push_back(e);
		}

		if(l)
			e->addEventListener(l);
	}

	Event* Engine::getEvent(string e) {
		for(unsigned int i = 0; i < events.size(); i++) {
			if(events[i]->equals(e))
				return events[i];
		}
		std::cout << "No such event: " << e << std::endl;
		return NULL;
	}*/

	/*EventListener* Engine::getEventListener(Event* e) {
		for(unsigned int i = 0; i < eventListeners.size(); i++) {
			if(eventListeners[i]->equals(e))
				return eventListeners[i];
		}
		std::cout << "No such eventListener: " << e->getString() << std::endl;
		return NULL;
	}*/

	//MODULE
	Module::Module(Engine *e)
	{
		engine = e;
	}

	Module::~Module()
	{
		//engine->removeModule(this);
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
	
