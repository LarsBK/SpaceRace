#include "Map.h"

Map::Map(string fn) : filename(fn) {
	
}

bool Map::load() {
	TiXmlDocument doc(filename.c_str());
	if(!doc.LoadFile()) {
		cerr << "Error opening file: " << filename << " "
			<< doc.ErrorDesc() << endl;
		return false;
	}

	TiXmlElement* map = doc.FirstChildElement("map");
	if(!map) {
		cerr << filename << " is not a map." << endl;
		return false;
	}
	TiXmlElement* name = map->FirstChildElement("name");
	mapName = name->GetText();
	cout << "Loading map " << mapName << endl;
	
	TiXmlElement* planet = map->FirstChildElement("planet");

	while(planet) {
		TiXmlElement* dynamicNode = planet->FirstChildElement("dynamic");
		bool dynamic = false;
		if(dynamicNode) {
			dynamic = (string(dynamicNode->GetText()) == "true");
		}

		float x = atof(planet->FirstChildElement("x")->GetText());
		float y = atof(planet->FirstChildElement("y")->GetText());
		float mass = atof(planet->FirstChildElement("mass")->GetText());
		float radius = atof(planet->FirstChildElement("radius")->GetText());

		float xSpeed = 0;
		float ySpeed = 0;
		TiXmlElement* temp = 0;
		temp = planet->FirstChildElement("xSpeed");
		if(temp)
			xSpeed = atof(temp->GetText());
		temp = planet->FirstChildElement("ySpeed");
		if(temp)
			ySpeed = atof(temp->GetText());

		string texture = planet->FirstChildElement("texture")->GetText();

		objects.push_back((GameObject*) new Planet(x,y,radius,
			mass, dynamic,xSpeed, ySpeed, texture, &imageManager));

		planet = planet->NextSiblingElement("planet");
	}
	return true;
	
}

vector<GameObject*>* Map::getObjects() {
	return &objects;
}

void Map::spawn(Box2DModule* box2d, WindowModule* window) {
	for(unsigned i = 0; i < objects.size(); i++) {
		box2d->addObject((z::PhysicsObject*) objects[i]);
		window->add((z::Drawable*) objects[i]);
	}
}

