#include "SpaceRaceMap.h"

void SpaceRaceMap::interpret(TiXmlElement* map) {
	/*
	TiXmlElement* map = doc.FirstChildElement("map");
	if(!map) {
		cerr << filename << " is not a map." << endl;
		return false;
	}
	*/
	
	//go =  new Planet(100,0,64,5.515,0,0,0,"Earth.png", engine->resourceManager());


	TiXmlElement* name = map->FirstChildElement("name");
	mapName = name->GetText();
	cout << "Loading map " << mapName << endl;
	
	TiXmlElement* planet = map->FirstChildElement("planet");

	while(planet) {
		objects.push_back(new Planet(planet, engine));
		planet = planet->NextSiblingElement("planet");
	}

	
	
}
