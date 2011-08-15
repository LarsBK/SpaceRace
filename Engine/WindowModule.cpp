#include "WindowModule.h"

namespace z {

	WindowModule::WindowModule(Engine* e) : Module(e) {
		name = "WindowModule";

		if(fullscreen)
			window = new sf::RenderWindow(sf::VideoMode::GetMode(0), engine->getName(), sf::Style::Fullscreen);
		else
			window = new sf::RenderWindow(sf::VideoMode(720,480,32), engine->getName());
		
		fullscreenAction = new Action("fullscreen", this);
		engine->addAction(fullscreenAction);
		engine->bind(new Event("Input_released_f"), fullscreenAction);

		pressed = new bool[sf::Key::Count];
	}

	void WindowModule::handleAction(Action* a) {
		if(a == fullscreenAction) {
			toggleFullscreen();
		}
	}

	void WindowModule::toggleFullscreen() {
		fullscreen = !fullscreen;

		if(fullscreen) {
			std::cout << "Entering fullscreen" << std::endl;
			window->Create(sf::VideoMode::GetMode(0), engine->getName(), sf::Style::Fullscreen);
		} else {
			std::cout << "Leaving fullscreen" << std::endl;
			window->Create(sf::VideoMode(720,480,32), engine->getName());
		}
	}

	void WindowModule::update(float time) {
		sf::Event event;
		while(window->GetEvent(event)) {
			string s;
			s.append("Input_");
			if (event.Type == sf::Event::Closed) 
				engine->quit("User quit");
			else if (event.Type == sf::Event::Resized)
				window->SetSize(event.Size.Width, event.Size.Height);
			else if (event.Type == sf::Event::MouseMoved) {
				
			} else if (event.Type == sf::Event::KeyReleased) {
				s.append("released_");
				char c = event.Text.Unicode;
				s.append(charToString(c));
				pressed[event.Key.Code] = false;
				engine->event(new Event(s));
			} else if (event.Type == sf::Event::KeyPressed) {
				s.append("pressed_");
				char c = event.Text.Unicode;
				s.append(charToString(c));
				if(!pressed[event.Key.Code]) {
					pressed[event.Key.Code] = true;
					engine->event(new Event(s));
				}
			}

		}
	}

	void WindowModule::onDraw(float time) {
		window->Clear();
		int fps = 1.0f/window->GetFrameTime();
		
		for(unsigned int i = 0; i < drawList.size(); i++) {
			drawList[i]->draw(window);
		}
		
		drawFps(fps);
		window->Display();
	}

	void WindowModule::drawFps(int f) {
		std::stringstream ss;
		std::string fpsstring;
		ss << f;
		ss >> fpsstring;
		
		sf::String string;
		string.SetText("fps: " + fpsstring);
		if (f >= 58)
			string.SetColor(sf::Color::Green);
		else if (f >= 30)
			string.SetColor(sf::Color::Yellow);
		else
			string.SetColor(sf::Color::Red);

		window->Draw(string);
	}

	void WindowModule::add(Drawable* d) {
		drawList.push_back(d);
	}

	static string charToString(char c) {
		stringstream ss;
		ss << c;
		return ss.str();
	}

}
