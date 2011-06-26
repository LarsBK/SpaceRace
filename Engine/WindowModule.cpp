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
		engine->bind(new Event("f"), fullscreenAction);
	}

	void WindowModule::handleAction(Action* a) {
		if(a == fullscreenAction) {
			toggleFullscreen();
		}
	}

	void WindowModule::toggleFullscreen() {
		fullscreen = !fullscreen;

		if(fullscreen)
			window->Create(sf::VideoMode::GetMode(0), engine->getName(), sf::Style::Fullscreen);
		else
			window->Create(sf::VideoMode(720,480,32), engine->getName());
	}

	void WindowModule::update(float time) {
		sf::Event event;
		string s;
		while(window->GetEvent(event)) {
			s.append("Input_");
			if (event.Type == sf::Event::Closed) 
				engine->quit("User quit");
			else if (event.Type == sf::Event::Resized)
				window->SetSize(event.Size.Width, event.Size.Height);
			else if (event.Type == sf::Event::MouseMoved) {
				
			} else if (event.Type == sf::Event::KeyReleased) {
				s.append("released_");
				stringstream ss;
				char c = event.Text.Unicode;
				ss << c;
				s.append(ss.str()); // >> s;
				engine->event(new Event(s));
			}
		}
	}

}
