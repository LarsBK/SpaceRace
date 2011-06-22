#include "Engine.h"
#include "Box2DModule.h"
#include "DebugModule.h"

using namespace z;

int main() {
	Engine* engine = new Engine();
	Box2DModule* box2d = new Box2DModule(engine);
	TestObject* o = new TestObject(2.0f,0.0f);

	DebugDrawModule* d = new DebugDrawModule(engine, box2d);

	box2d->addObject(o);
	engine->addPhysics(box2d);
	engine->addDraw(d);
	engine->run();
	return true;
}
