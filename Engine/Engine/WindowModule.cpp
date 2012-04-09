#include "WindowModule.h"

namespace z {

	WindowModule::WindowModule(Engine* e) : Module(e), window() {
		name = "WindowModule";

		vsync(true);
		camera = new Camera(&window, e);
		setFullscreen(false);
		//camera->setWindowSize(window.GetWidth(), window.GetHeight());

		fullscreenAction = new FullscreenAction(this);
		engine->addAction( fullscreenAction);
		engine->bind("keyboard_f", fullscreenAction->toString());

		pressed = new bool[sf::Keyboard::KeyCount];
	}

	void WindowModule::vsync(bool v) {
		window.setVerticalSyncEnabled(v);
	}

	WindowModule::~WindowModule() {
		delete[] pressed;
		//delete window;
		delete fullscreenAction;
	}
/*
	void WindowModule::handleAction(Action* a) {
		if(a == fullscreenAction && a->getEvent()->state == Event::STARTED) {
			toggleFullscreen();
		}
	}
*/
	
	void WindowModule::setFullscreen(bool f) {
		fullscreen = f;
		if(fullscreen) {
			std::cout << "Fullscreen" << std::endl;
			window.create(sf::VideoMode::getDesktopMode(), engine->getName(), sf::Style::Fullscreen, windowSettings);
		} else {
			std::cout << "Windowmode" << std::endl;
			window.create(sf::VideoMode(720,480,32), engine->getName(),
				sf::Style::Close|sf::Style::Resize, windowSettings);
		}

		camera->setWindowSize(window.getSize());
	}

	void WindowModule::update(float time) {
		sf::Event event;
		Event* e;
		while(window.pollEvent(event)) {
			string s;
			s.append("keyboard_");
			if (event.type == sf::Event::Closed) 
				engine->quit("User quit");
			else if (event.type == sf::Event::Resized) {
				//fix here
				sf::Vector2u size(event.size.width, event.size.height);
				camera->setWindowSize(size);
			} else if (event.type == sf::Event::MouseMoved) {

			} else if (event.type == sf::Event::KeyReleased) {
				s.append(keyToString(event.key.code));
				pressed[event.key.code] = false;
				e = new Event(s);
				e->state = Event::STOPPED;
				engine->event(e);
				delete e;
			} else if (event.type == sf::Event::KeyPressed) {
				s.append(keyToString(event.key.code));
				if(!pressed[event.key.code]) {
					pressed[event.key.code] = true;
					e = new Event(s);
					e->state = Event::STARTED;
					engine->event(e);
					delete e;
				}
			} else if (event.type == sf::Event::TextEntered) {
			}

		}
	}

	void WindowModule::onDraw(float time) {
		window.clear();
		window.setView(*(camera->getView()));

		for(unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->draw(this,time);
		}
		window.setView(window.getDefaultView());
/*
		for(unsigned int i = 0; i < hudList.size(); i++) {
			hudList[i]->draw(window);
		}
*/
/*
		int fps = 1.0f/window.getFrameTime().asSeconds();
		engine->setFPS(fps);
		drawFps(fps);
*/
		window.display();
	}
/*
	void WindowModule::drawFps(int f) {
		std::stringstream ss;
		std::string fpsstring;
		ss << f;
		ss >> fpsstring;

		sf::String string;
		string.setText(fpsstring + " FPS");
		if (f >= 50)
			string.setColor(sf::Color::Green);
		else if (f >= 30)
			string.setColor(sf::Color::Yellow);
		else
			string.setColor(sf::Color::Red);

		window.draw(string);
	}
*/
	void WindowModule::add(Drawable* d) {
		drawList.push_back(d);
	}
	void WindowModule::add(GameObject* d) {
		add((Drawable*) d);
	}

	bool WindowModule::isFullscreen() {
		return fullscreen;
	}
	
	void WindowModule::add(Map* m) {
		vector<GameObject*>* list = m->getObjects();
		for(unsigned i = 0; i < list->size(); i++) {
			GameObject* g = (*list)[i];
			add(g);
		}
	}

	float WindowModule::meterToPixel(float m) {
		return camera->meterToPixel(m);
	}

	Camera* WindowModule::getCamera() {
		return camera;
	}

	FullscreenAction::FullscreenAction(WindowModule* w) {
		wm = w;
	}

	void FullscreenAction::fire(Event* e) {
		if(e->state == Event::STARTED) {
			wm->setFullscreen(!wm->isFullscreen());
		}
	}

	string FullscreenAction::getName() {
		return "Toggle fullscreen";
	}

	string FullscreenAction::toString() {
		return "fullscreen";
	}

	static string keyToString(sf::Keyboard::Key k) {
		stringstream ss;
		int c = k +	'a';
		if(c >= 0 && c <= 'z')
			ss << (char) c;
		else
			ss << "code_" << c;
		return ss.str();
	}

}
