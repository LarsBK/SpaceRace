#include "Engine.h"
#include "Box2DModule.h"
#include "DebugModule.h"
#include "WindowModule.h"
#include "PongBall.h"
#include "GameObject.h"
#include "PlayerBox.h"

using namespace z;

int main() {
	Engine* engine = new Engine("Test");
	Box2DModule* box2d = new Box2DModule(engine);
	GameObject* o;
	WindowModule* d = new WindowModule(engine);
	
	/*for(unsigned int i = 0; i < 20; i++) {
		o = (GameObject*) new DynamicBox(100.0f+(i%2),-5.0f);
		box2d->addObject((PhysicsObject*)o);
		d->add((Drawable*)o);
	}*/

	o = (GameObject*) new PongBall();
	GameObject* g = (GameObject*) new PlayerBox(120,100,engine);
	engine->bind(new Event("Input_pressed_h"), "moveLeft");
	box2d->addObject((PhysicsObject*)g);
	d->add((Drawable*)g);
	box2d->addObject((PhysicsObject*)o);
	d->add((Drawable*)o);

	DebugDrawModule* debug = new DebugDrawModule(engine, box2d);

	engine->addModule(box2d);
	engine->addModule(d);
	engine->addModule(debug);

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
	//engine->event("teh lulz");
	//engine->event("quit");
	engine->run();
	return true;
}
