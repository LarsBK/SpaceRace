#include "Engine.h"
#include "Box2DModule.h"
#include "DebugModule.h"
#include "WindowModule.h"
#include "PongBall.h"
#include "GameObject.h"
//#include "Wall.h"
//#include "PlayerBox.h"
#include "Paddle.h"

using namespace z;

int main() {
	Engine* engine = new Engine("Test");
	Box2DModule* box2d = new Box2DModule(engine);
	//GameObject* o;
	WindowModule* d = new WindowModule(engine);
	//DebugDrawModule* debug = new DebugDrawModule(engine, box2d);
	
	/*for(unsigned int i = 0; i < 20; i++) {
		//o = (GameObject*) new DynamicBox(100.0f+(i%2),-5.0f);
		o = (GameObject*) new PlayerBox(0,50+i,engine);
		box2d->addObject((PhysicsObject*)o);
		d->add((Drawable*)o);
	}*/

	GameObject* ball = (GameObject*) new PongBall();
	box2d->addObject((PhysicsObject*) ball);
	d->add((Drawable*)ball);
	
	GameObject* paddle1 = (GameObject*) new Paddle("Right Player", 300, 50, engine);
	box2d->addObject((PhysicsObject*) paddle1);
	d->add((Drawable*) paddle1);

	engine->bind(new Event("Input_pressed_h"), "Right Player up");
	engine->bind(new Event("Input_pressed_n"), "Right Player down");
	
	
	//GameObject* w1 = (GameObject*) new Wall(100,200,200,10);
	//GameObject* w2 = (GameObject*) new Wall(0,80,200,10);
	//box2d->addObject((PhysicsObject*) w1);
	//box2d->addObject((PhysicsObject*) w2);
	//GameObject* g = (GameObject*) new PlayerBox(100,30,engine);
	//engine->bind(new Event("Input_pressed_h"), "moveLeft");
	//box2d->addObject((PhysicsObject*)g);
	//d->add((Drawable*)g);
	//box2d->addObject((PhysicsObject*)o);
	//d->add((Drawable*)o);
	//d->add((Drawable*)w2);
	//d->add((Drawable*)w1);


	DebugDrawModule* debug = new DebugDrawModule(engine, box2d);

	engine->addModule(box2d);
	engine->addModule(d);
	engine->addModule(debug);

	engine->run();
	return true;
}

