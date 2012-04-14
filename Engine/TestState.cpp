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

	//window->getCamera()->follow((z::PhysicsObject*) go);
	engine->addModule(box2d);

	window->addHUD(new PerformanceMonitor(engine));
	//Map
	
	//spawn(new Planet(100,0,64,5.515,0,0,0,"Earth.png", engine->resourceManager()));
	//SpaceRaceMap* map = new SpaceRaceMap(engine);

	TiXmlDocument* doc = new TiXmlDocument();
	if(!doc->LoadFile("TestMap.xml")) {
		cerr << "Error opening file: " << " "
			<< doc->ErrorDesc() << endl;
	}

	//map->interpret(doc->FirstChildElement("map"));

	TiXmlElement* map = doc->FirstChildElement("map");
	TiXmlElement* name = map->FirstChildElement("name");
	string mapName = name->GetText();
	cout << "Loading map " << mapName << endl;
	
	TiXmlElement* planet = map->FirstChildElement("planet");

	while(planet) {
		spawn(new Planet(planet, engine));
		planet = planet->NextSiblingElement("planet");
	}

	//if(map->load("TestMap.xml")) {
		//box2d->add(map);
		//GameObject* go = 
		//window->add(go);
		//box2d->add(go);
		
		//window->add(map);
//	} else {
//		cout << "unable to load map" << endl;
//		return -1;
//	}
	
	spawn(new Thruster(engine));

	cout << "Spawning...";
	//spawn(new Planet(100,0,64,5.515,0,0,0,"Earth.png", engine->resourceManager()));
	//spawn(new RandomObject(0,0)); 
	srand(time(NULL));
	for(unsigned int x = 0; x < 10; x++) {
		float z = -100.0f*(x+1.0f);

		for(unsigned int i = 0; i < 10; i++) {
			spawn(new RandomObject(0,z)); 
		}

		engine->cycle();
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
