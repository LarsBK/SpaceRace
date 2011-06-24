#include "Engine.h"
#include "Box2DModule.h"
#include "DebugModule.h"

using namespace z;

int main() {
	Engine* engine = new Engine();
	Box2DModule* box2d = new Box2DModule(engine);
	TestObject* o;

	for(unsigned int i = 0; i < 20; i++) {
		o = new TestObject(100.0f+(i%2),-5.0f);
		box2d->addObject(o);
	}

	DebugDrawModule* d = new DebugDrawModule(engine, box2d);

	engine->addModule(box2d);
	engine->addModule(d);

	/*
	float nextTime = engine->getTime();
	int i = 0;
	while(true) {
		engine->cycle();

		if(engine->getFps() > 60 && engine->getTime() >= nextTime) {
			o = new TestObject(100.0f,-5.0f);
			box2d->addObject(o);
			o = new TestObject(100.0f,-5.0f);
			box2d->addObject(o);
			nextTime = engine->getTime() + 0.01f;
			i++;
			//std::cout << i << std::endl;
		}
	}
	*/
	engine->run();
	return true;
}
