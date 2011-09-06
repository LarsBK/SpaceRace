#include "BenchmarkState.h"
#include "iostream"

using namespace std;

string BenchmarkState::getName() {
	return "Benchmark";
}

BenchmarkState::BenchmarkState(z::Engine* e, z::WindowModule* w) {
	engine = e;
	window = w;
}

int BenchmarkState::load(Game* game) {
	box2d = new z::Box2DModule(engine, 120, b2Vec2(0.0f, 0.0f), false);
	engine->addModule(box2d);
	window->vsync(false);
	return 0;
}

BenchmarkState::~BenchmarkState() {
	delete box2d;
}

int BenchmarkState::run() {

	float lastTime = 1.0f;
	unsigned int i = 0;
	engine->cycle();
	engine->cycle();
	do {
		if(lastTime + 0.1f < engine->getTime()) {
			lastTime += 0.1f;
			spawn(new TestBox());
			i++;
		}
		engine->cycle();
		//cout << engine->getFPS() << endl;
	} while (engine->getFPS() > 10);

	cout << "Max bodies: " << i << endl;

	return 0;
}

void BenchmarkState::spawn(z::GameObject* g) {
	box2d->addObject((z::PhysicsObject*) g);
	//window->add((z::Drawable*) g);
}

TestBox::TestBox() {
	x = 0;
	y = 0;

	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = 1;
	dynamic = true;
}
