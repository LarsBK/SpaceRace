#include "WindowModule.h"

namespace z {

	WindowModule::WindowModule(Engine* e) : Module(e) {
		name = "WindowModule";
		fullscreen = false;

		windowSettings.AntialiasingLevel = 8;

		if(fullscreen)
			window = new sf::RenderWindow(sf::VideoMode::GetMode(0), engine->getName(), sf::Style::Fullscreen, windowSettings);
		else
			window = new sf::RenderWindow(sf::VideoMode(1024,576,32), engine->getName(), sf::Style::Close|sf::Style::Resize, windowSettings);

		window->UseVerticalSync(true);
		camera = new Camera(&window->GetDefaultView(), e);
		camera->setWindowSize(window->GetWidth(), window->GetHeight());

		fullscreenAction = new FullscreenAction(this);
		engine->addAction( fullscreenAction);
		engine->bind("keyboard_f", fullscreenAction->toString());

		pressed = new bool[sf::Key::Count];
	}

	void WindowModule::vsync(bool v) {
		window->UseVerticalSync(v);
	}

	WindowModule::~WindowModule() {
		delete camera;
		delete[] pressed;
		delete window;
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
			window->Create(sf::VideoMode::GetMode(0), engine->getName(), sf::Style::Fullscreen, windowSettings);
		} else {
			std::cout << "Leaving fullscreen" << std::endl;
			window->Create(sf::VideoMode(720,480,32), engine->getName(),
				sf::Style::Close|sf::Style::Resize, windowSettings);
		}

		camera->setWindowSize(window->GetWidth(), window->GetHeight());
	}

	void WindowModule::update(float time) {
		sf::Event event;
		Event* e;
		while(window->GetEvent(event)) {
			string s;
			s.append("keyboard_");
			if (event.Type == sf::Event::Closed) 
				engine->quit("User quit");
			else if (event.Type == sf::Event::Resized) {
				//fix here
				camera->setWindowSize(event.Size.Width, event.Size.Height);

				//window->GetView().SetHalfSize(event.Size.Width/2.0f, event.Size.Height/2.0f);
			} else if (event.Type == sf::Event::MouseMoved) {

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
		window->Clear();

		window->SetView(*camera->getView());

		for(unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->draw(this);
		}
/*
		for(unsigned int i = 0; i < hudList.size(); i++) {
			hudList[i]->draw(window);
		}
*/
		window->SetView(window->GetDefaultView());

		int fps = 1.0f/window->GetFrameTime();
		engine->setFPS(fps);
		drawFps(fps);
		window->Display();
	}

	void WindowModule::drawFps(int f) {
		std::stringstream ss;
		std::string fpsstring;
		ss << f;
		ss >> fpsstring;

		sf::String string;
		string.SetText(fpsstring + " FPS");
		if (f >= 50)
			string.SetColor(sf::Color::Green);
		else if (f >= 30)
			string.SetColor(sf::Color::Yellow);
		else
			string.SetColor(sf::Color::Red);

		window->Draw(string);
	}

	void WindowModule::add(Drawable* d) {
		cerr << "D: " << (void*) d << endl;
		cerr << "L: " << (void*) &drawList << endl;
		cerr << drawList.size() << endl;

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
