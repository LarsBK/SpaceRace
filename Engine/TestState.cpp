#include "TestState.h"

string TestState::getName() {
	return "Test State";
}

TestState::TestState(z::Engine* e, z::WindowModule* w) {
	engine = e;
	window = w;
}

int TestState::load(Game* game) {
	box2d = new z::Box2DModule(engine, 60, b2Vec2(0.0f, 0.0f), true);

	//spawn(new Wall(0,0,200,1));
	//spawn(new Wall(-100,-100,1,200));
	//spawn(new Wall(100,-100,1,200));
	//z::GameObject* go = new RandomObject(0,-100);
	//window->getCamera()->follow((z::PhysicsObject*) go);
	//spawn(go);

	//z::ResourceManager* man = new z::ResourceManager();
	engine->addModule(box2d);

	//Map
	SpaceRaceMap* map = new SpaceRaceMap(engine);
	if(map->load("TestMap.xml")) {
		box2d->add(map);
		window->add(map);
	} else {
		cout << "unable to load map" << endl;
		return -1;
	}

	cout << "Spawning...";
	
//	srand(time(NULL));
	for(unsigned int x = 0; x < 60; x++) {
		float z = -100.0f*(x+1.0f);

		for(unsigned int i = 0; i < 10; i++) {
			spawn(new RandomObject(0,z)); 
		}

		//engine->cycle();
	}
	
	engine->cycle();
	cout << " done!" << endl;
	return 0;
}

TestState::~TestState() {
	delete box2d;
}

int TestState::run() {
	engine->run();
	return 0;
}

void TestState::spawn(z::GameObject* g) {
	box2d->add((z::PhysicsObject*) g);
	window->add((z::Drawable*) g);
}
