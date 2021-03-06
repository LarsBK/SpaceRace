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
/*		vector<GameObject*>* mapList = map->getObjects();
		
		for(unsigned i = 0; i < mapList->size(); i++) {
			spawn((*mapList)[i]);
		}
	}
*/
	//spawn((GameObject*) new EarthTest(man,120,100));
	//spawn((GameObject*) new EarthTest(man,300,500));
	//engine->cycle();

	for(unsigned int x = 0; x < 60; x++) {
		float z = -100.0f*(x+1.0f);

		for(unsigned int i = 0; i < 10; i++) {
			spawn(new RandomObject(0,z)); //-200)); //*(x+1)));
		}

		//engine->cycle();
	}

	engine->cycle();
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
