#include "DebugModule.h"

namespace z {

	DebugDrawModule::DebugDrawModule(Engine* e, Box2DModule* b) : Module(e) {
		window = new sf::RenderWindow(sf::VideoMode(800,600,32), "DebugDraw");
		box2d = b;

		debug = new DebugDraw(window);
		debug->SetFlags(b2DebugDraw::e_shapeBit);
		box2d->getWorld()->SetDebugDraw(debug);
	}

	void DebugDrawModule::onDraw() {
		window->Clear();
		box2d->getWorld()->DrawDebugData();
		window->Display();
	}

}
