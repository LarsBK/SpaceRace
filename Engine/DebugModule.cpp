#include "DebugModule.h"

namespace z {

	DebugDrawModule::DebugDrawModule(Engine* e, Box2DModule* b) : Module(e) {
		name = "DebugDrawModule";
		window = new sf::RenderWindow(sf::VideoMode(480,272,32), "DebugDraw");
		box2d = b;
		window->SetFramerateLimit(engine->getTargetFramerate());

		debug = new DebugDraw(window);
		debug->SetFlags(b2DebugDraw::e_shapeBit);
		box2d->getWorld()->SetDebugDraw(debug);
	}

	void DebugDrawModule::onDraw(float time) {
		window->Clear();
		box2d->getWorld()->DrawDebugData();
		//drawFps();
		window->Display();
	}

	void DebugDrawModule::update(float time) {
		sf::Event event;
		while(window->GetEvent(event)) {
			if (event.Type == sf::Event::Closed) 
				engine->quit("User quit (debugdraw)");
			else if (event.Type == sf::Event::Resized)
				window->SetSize(event.Size.Width, event.Size.Height);
		}
	}


/*	void DebugDrawModule::drawFps() {
		std::stringstream ss;
		std::string fpsstring;
		ss << (int) engine->getFps();
		ss >> fpsstring;
		
		sf::String string;
		string.SetText("fps: " + fpsstring);
		if (engine->getFps() >= 58)
			string.SetColor(sf::Color::Green);
		else if (engine->getFps() >= 30)
			string.SetColor(sf::Color::Yellow);
		else
			string.SetColor(sf::Color::Red);

		window->Draw(string);
	}
*/

}
