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
	box2d = new z::Box2DModule(engine, 120, b2Vec2(0.0f, 10.0f), true);
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
	
	//wait while fps gets better
	while(engine->getTime() < lastTime - 0.5f) {
		engine->cycle();
	}
	
	do {
		while(lastTime + 0.1f < engine->getTime()) {
			lastTime += 0.1f;
			for(int u = 0; u < 10; u++) {
				spawn(new TestBox(i*2.0f, u*2.0f));
				i++;
			}
		}
		engine->cycle();
	} while (engine->getFPS() > 20 && engine->isRunning());

	cout << "Max bodies: " << i << endl;

	return 0;
}

void BenchmarkState::spawn(z::GameObject* g) {
	box2d->addObject((z::PhysicsObject*) g);
	//window->add((z::Drawable*) g);
}

TestBox::TestBox(float xi, float yi) {
	x = xi;
	y = yi;

	shape = (b2Shape*) new b2CircleShape();
	shape->m_radius = 1;
	dynamic = true;
}
