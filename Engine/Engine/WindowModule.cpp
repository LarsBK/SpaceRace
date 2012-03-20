#include "WindowModule.h"

namespace z {

	WindowModule::WindowModule(Engine* e) : Module(e) {
		name = "WindowModule";
		fullscreen = true; //Flipped

		windowSettings.antialiasingLevel = 8;
/*
		if(fullscreen)
			window = new sf::RenderWindow(sf::VideoMode::getMode(0), engine->getName(), sf::Style::Fullscreen, windowSettings);
		else
			window = new sf::RenderWindow(sf::VideoMode(1024,576,32), engine->getName(), sf::Style::Close|sf::Style::Resize, windowSettings);
*/
		vsync(true);
		camera = new Camera(&window, e);
		toggleFullscreen();
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
	void WindowModule::toggleFullscreen() {
		fullscreen = !fullscreen;

		if(fullscreen) {
			std::cout << "Entering fullscreen" << std::endl;
			window.create(sf::VideoMode::getDesktopMode(), engine->getName(), sf::Style::Fullscreen, windowSettings);
		} else {
			std::cout << "Leaving fullscreen" << std::endl;
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
				camera->setWindowSize(event.size.width, event.size.height);

				//window.GetView().SetHalfSize(event.Size.Width/2.0f, event.Size.Height/2.0f);
			} else if (event.type == sf::Event::MouseMoved) {

			} else if (event.Type == sf::Event::KeyReleased) {
				char c = event.Text.Unicode;
				s.append(charToString(c));
				pressed[event.Key.Code] = false;
				e = new Event(s);
				e->state = Event::STOPPED;
				engine->event(e);
			} else if (event.Type == sf::Event::KeyPressed) {
				char c = event.Text.Unicode;
				s.append(charToString(c));
				if(!pressed[event.Key.Code]) {
					pressed[event.Key.Code] = true;
					e = new Event(s);
					e->state = Event::STARTED;
					engine->event(e);
					delete e;
				}
			}

		}
	}

	void WindowModule::onDraw(float time) {
		window.clear();

		window.setView(*(camera->getView()));

		for(unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->draw(this);
		}
/*
		for(unsigned int i = 0; i < hudList.size(); i++) {
			hudList[i]->draw(window);
		}
*/
		window.setView(window.getDefaultView());

		int fps = 1.0f/window.getFrameTime().asSeconds();
		engine->setFPS(fps);
		drawFps(fps);
		window.display();
	}

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

	void WindowModule::add(Drawable* d) {
		drawList.push_back(d);
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
			wm->toggleFullscreen();
		}
	}

	string FullscreenAction::getName() {
		return "Toggle fullscreen";
	}

	string FullscreenAction::toString() {
		return "fullscreen";
	}

	static string charToString(char c) {
		stringstream ss;
		ss << c;
		return ss.str();
	}

}
