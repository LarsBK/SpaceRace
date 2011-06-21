#include "Engine.h"

namespace z
{

	//ENGINE
	Engine::Engine() {
		//running = true;
		//threads = 4;
		//ptr_console = new console(this);
		//ptr_console->level = debug;
		//window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "SFML Window");
		//view = window->GetView();				
		//(*ptr_console) << "Zengine started...";
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

	unsigned int Engine::addUpdate(Module* module) {
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

	/*int Engine::removeModule(unsigned int nr)
	{
		cout << "Unloading module " << moduleList[nr-1]->name << endl;
		moduleList.erase(moduleList.begin()+nr-1);
	}*/

	void Engine::run() {
		//sf::Thread[]* t = new sf::Thread[threads];
		//for(int i = 0; i < t.length; i++) {
		//	t[i] = new sf::Thread(
		unsigned int i = 0;
		while(i < 10) {
			update();
			physics();
			draw();
			i++;
		}
	}
	
	void Engine::update() {	
		//sf::Thread* t = new sf::Thread[moduleList.size()]();
		//for(int i = 0; i < t.length; i++) {
		//	t[i] = new sf::Thread(

		//float delta = deltaClock.GetElapsedTime();
		//deltaClock.Reset();

		//cout << "Updating " << moduleList.size() << " modules..." << endl;
		for (unsigned int i = 0; i < updateList.size(); i++) {
			//cout << "updating " << moduleList[i] << endl;
			//t[i] = new Thread(&moduleList[i]->update(delta));
			//t[i].Launch();
			updateList[i]->update();//delta);
		}
		//delete t;
	}

	void Engine::physics() {	
		for (unsigned int i = 0; i < physicsList.size(); i++) {
			physicsList[i]->onPhysics();//delta);
		}
	}


	void Engine::draw() {	
		for (unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->onDraw();//delta);
		}
	}

	/*float Engine::getTime() {
		return clock.GetElapsedTime();
	}*/


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

	void Module::onDraw() {
		cout << "onDraw() not implemented in " << name << endl;
	}

	void Module::update() {
		cout << "update() not implemented in " << name << endl;
	}

	void Module::onPhysics() {
		cout << "onPhysics() not implemented in " << name << endl;
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
