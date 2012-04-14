#include "Engine.h"
#include <SFML/System.hpp>

namespace z
{

	Engine::Engine(string name) :
		resMan(this)
		
	{
		gameName = name;
		running = true;
	}

	Engine::~Engine() {
		while(eventBindings.size()) {
			EventBinding* eb = eventBindings.back();
			eventBindings.pop_back();
			delete eb;
		}

		actions.clear();
		//drawList.clear();
		//physicsList.clear();
		updateList.clear();
	}

	string Engine::getName() {
		return gameName;
	}

	void Engine::addModule(Module* m) {
		updateList.push_back(m);
	}

	void Engine::run() {
		frameTime.restart();
		running = true;
		clock.restart();
		while(running) { 
			cycle();
		}
	}

	void Engine::cycle() {
		update();
		physics();
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
		float pTime = clock.getElapsedTime().asSeconds();

		for (unsigned int i = 0; i < updateList.size(); i++) {
			updateList[i]->update(pTime);//delta);
		}
	}

	void Engine::physics() {
		float pTime = clock.getElapsedTime().asSeconds();

		for (unsigned int i = 0; i < updateList.size(); i++) {
			updateList[i]->onPhysics(pTime);//delta);
		}
	}

	void Engine::draw() {
		float pTime = clock.getElapsedTime().asSeconds();
		for (unsigned int i = 0; i < updateList.size(); i++) {
			updateList[i]->onDraw(pTime);//delta);
		}
	}

	float Engine::getTime() {
	  return clock.getElapsedTime().asSeconds();
	}

	unsigned int Engine::getFPS() {
		return fps;
	}

	//Event
	void Engine::event(Event* e) {
		EventBinding* eb = getBinding(e->toString());
		if(eb) {
			eb->fire(e);
		}
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
/*
	void Engine::unbind(string e, string a) {
		EventBinding* eb = getBinding(e);
*/		

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
	
	//MODULE
	Module::Module(Engine *e) {
		engine = e;
	}

	void Module::onDraw(float t) {
	}

	void Module::update(float t) {
	}

	void Module::onPhysics(float t) {
	}
}
	
