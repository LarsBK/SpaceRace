#include "Engine.h"
#include <SFML/System.hpp>

namespace z
{

	//ENGINE
	Engine::Engine() {
		running = true;
		//threads = 4;
		//ptr_console = new console(this);
		//ptr_console->level = debug;
		//window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "SFML Window");
		//view = window->GetView();				
		//(*ptr_console) << "Zengine started...";
		targetFramerate = 60;

		//Commands
		addAction(new Action("test action", this));
		bind(new Event("test event"), "test action");
	}

	void Engine::handleAction(Action* a) {
		std::cout << a->getName() << std::endl;
	}

	Engine::~Engine()
	{
		drawList.clear();
		physicsList.clear();
		updateList.clear();
		//moduleList.clear();
		//Using this instead to print the name of all modules as they are unloaded
		//(*ptr_console) << "Unloading all modules...";
		//for (unsigned int i = moduleList.size(); i > 0; i--)
		//{
		//	removeModule(i);
		//	//moduleList.erase(moduleList.begin()+i-1);
		//}
		//delete moduleList;
		//delete ptr_console;
		//delete window;
		//delete view;

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

	/*unsigned int Engine::addUpdate(Module* module) {
		updateList.push_back(module);
		//cout << Module->name << " module loaded." << endl;
		return updateList.size();
	}



	unsigned int Engine::addPhysics(Module* module) {
		physicsList.push_back(module);
		//cout << Module->name << " module loaded." << endl;
		return physicsList.size();
	}

	unsigned int Engine::addDraw(Module* module) {
		drawList.push_back(module);
		//cout << Module->name << " module loaded." << endl;
		return drawList.size();
	}

	int Engine::removeModule(unsigned int nr) {
	  cout << "Unloading module " << moduleList[nr-1]->name << endl;
	  moduleList.erase(moduleList.begin()+nr-1);
	}*/

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

		if(frameTime.GetElapsedTime() > 0.0f)
			fps = 1.0f/frameTime.GetElapsedTime();
		else
			fps = 1337;
		frameTime.Reset();

		//if(fps > 240)
		//	sf::Sleep(0.01);
		/*if(fps <= 0) {
			std::cout << "ZOMG" << frameTime.GetElapsedTime()<< std::endl;
		}*/

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
		//sf::Thread* t = new sf::Thread[moduleList.size()]();
		//for(int i = 0; i < t.length; i++) {
		//	t[i] = new sf::Thread(

		//float delta = deltaClock.GetElapsedTime();
		//deltaClock.Reset();
		float pTime = clock.GetElapsedTime();

		//cout << "Updating " << moduleList.size() << " modules..." << endl;
		for (unsigned int i = 0; i < updateList.size(); i++) {
			//cout << "updating " << moduleList[i] << endl;
			//t[i] = new Thread(&moduleList[i]->update(delta));
			//t[i].Launch();
			updateList[i]->update(pTime);//delta);
		}
		//delete t;
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

	float Engine::getFps() {
		return fps;
	}

	//Event

	void Engine::event(Event* e) {
		std::cout << "event: " << e->getString() << std::endl;
		EventListener* l = getListener(e);
		if(l)
			l->fire();
	}
//fix
	void Engine::addEventListener(Event* e, string a) {
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
	}

	EventListener* Engine::getEventListener(string l) {
		for(unsigned int i = 0; i < eventListeners.size(); i++) {
			if(eventListeners[i]->equals(l))
				return eventListeners[i];
		}
		std::cout << "No such eventListener: " << l << std::endl;
		return NULL;
	}

	//MODULE
	Module::Module(Engine *e)
	{
		engine = e;
		//id = parentEngine->addModule(this);
		cout << "Added module!" << endl;
	}

	Module::~Module()
	{
		//engine->removeModule(id);
	}

	/*void module::update(float delta) {
	  cout << "update not implemented in " << name << endl;
	  }*/

	void Module::onDraw(float t) {
		//cout << "onDraw() not implemented in " << name << endl;
	}

	void Module::update(float t) {
		//cout << "update() not implemented in " << name << endl;
	}

	void Module::onPhysics(float t) {
		//cout << "onPhysics() not implemented in " << name << endl;
	}


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

	}
