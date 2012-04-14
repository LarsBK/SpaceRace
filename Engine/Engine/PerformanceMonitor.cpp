#include "PerformanceMonitor.hpp"

namespace z {

	PerformanceMonitor::PerformanceMonitor(Engine* e) {
		engine = e;
		lastTime = 0;
		frames = 0;
		fps_drawable.setCharacterSize(10);
		draw_drawable.setCharacterSize(10);
		draw_drawable.setPosition(0,15);
		physics_drawable.setCharacterSize(10);
		physics_drawable.setPosition(0,27);
		update_drawable.setCharacterSize(10);
		update_drawable.setPosition(0,39);
		fps_drawable.setString("Framerate: ");
	}

	void PerformanceMonitor::draw(WindowModule* wm, float time) {
		if(time - lastTime >= 1.0f) {
			int fps = frames / (time - lastTime);
			lastTime = time;
			frames = 0;

			std::stringstream ss;
			ss << "Framerate: " << fps;

			fps_drawable.setString(ss.str());
			if (fps >= 50)
				fps_drawable.setColor(sf::Color::Green);
			else if (fps >= 30)
				fps_drawable.setColor(sf::Color::Yellow);
			else
				fps_drawable.setColor(sf::Color::Red);
			

			float totalTime = drawTime+physicsTime+updateTime;

			ss.str("");
			ss << "Render time: " << (int)((drawTime/totalTime)*100) << "%";
			draw_drawable.setString(ss.str());
			ss.str("");
			ss << "Physics time: " << (int)((physicsTime/totalTime)*100) << "%";
			physics_drawable.setString(ss.str());
			ss.str("");
			ss << "Update time: " << (int)((updateTime/totalTime)*100) << "%";
			update_drawable.setString(ss.str());
	
			drawTime = 0;
			physicsTime = 0;
			updateTime = 0;					
		}

		drawTime += engine->getDrawTime();
		physicsTime += engine->getPhysicsTime();
		updateTime += engine->getUpdateTime();

		wm->getWindow()->draw(fps_drawable);
		wm->getWindow()->draw(draw_drawable);
		wm->getWindow()->draw(physics_drawable);
		wm->getWindow()->draw(update_drawable);

		frames++;
	}

}


