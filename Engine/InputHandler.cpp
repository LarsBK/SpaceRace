#include "InputHandler.h"

namespace z {

	InputHandler::addCallBack(string n, void (*func)(bool pressed)) {
		names.push_back(n);
		codes.push_back(NULL);
		callBack.push_back(func);
	}

	void InputHandler::update() {
		//if(parentEngine->window != NULL) {
		while(window->GetEvent(event)) {
			if(event.Type == sf::Event::Closed) {
				engine->quit("User quit");
			} else if (event.Type == sf::Event::Resized) {
				//sf::View v = window->GetDefaultView();
				//parentEngine->window_width = event.Size.Width;
				//parentEngine->window_height = event.Size.Height;
				//window->SetView(v);
			} else if (event.Type == sf::Event::KeyPressed) {
				for(unsigned int i = 0; i < codes.size(); i++) {
					if(codes[i] == event.Key.Code)
						callBack[i](true);
				}
			} else if (event.Type == sf::Event::KeyReleased) {
				for(unsigned int i = 0; i < codes.size(); i++) {
					if(codes[i] == event.Key.Code)
						callBack[i](false);
				}
			}
		}
		//}
	}

	
