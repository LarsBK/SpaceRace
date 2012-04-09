#ifndef PERFORMANCEMONITOR_TZHDJF8K

#define PERFORMANCEMONITOR_TZHDJF8K

#include "WindowModule.h"

namespace z {
class PerformanceMonitor : public Drawable {
	
	float lastTime;
	int frames;
	Engine* engine;

	sf::Text fps_drawable;

	public:
	PerformanceMonitor(Engine* e);
	virtual void draw(WindowModule* wm, float time);

};

}

#endif /* end of include guard: PERFORMANCEMONITOR_TZHDJF8K */
