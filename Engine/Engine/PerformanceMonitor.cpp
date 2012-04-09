#include "PerformanceMonitor.hpp"

namespace z {

	PerformanceMonitor::PerformanceMonitor(Engine* e) {
		engine = e;
		lastTime = 0;
		frames = 0;
	}

	void PerformanceMonitor::draw(WindowModule* wm, float time) {
		if(time - lastTime >= 1.0f) {
			int fps = frames / (time - lastTime);
			lastTime = time;
			frames = 0;

			std::stringstream ss;
			std::string fpsstring;
			ss << fps;
			ss >> fpsstring;

			fps_drawable.setString("Framerate: " + fpsstring);
			if (fps >= 50)
				fps_drawable.setColor(sf::Color::Green);
			else if (fps >= 30)
				fps_drawable.setColor(sf::Color::Yellow);
			else
				fps_drawable.setColor(sf::Color::Red);
		}

		wm->getWindow()->draw(fps_drawable);

		frames++;
	}

}


