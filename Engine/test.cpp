#include "Engine.h"
#include "Box2DModule.h"

using namespace z;

int main() {
	Engine* engine = new Engine();
	Box2DModule* box2d = new Box2DModule(engine);
	TestObject* o = new TestObject(0.0f,4.0f);
	box2d->addObject(o);
	engine->addPhysics(box2d);
	engine->run();
	return true;
}
