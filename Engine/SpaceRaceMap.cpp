#include "SpaceRaceMap.h"

void SpaceRaceMap::interpret(TiXmlElement* root) {
	//TiXmlElement* root = d->FirstChildElement(); //"map");
	if(! root) {
		//|| root->ValueStr() != map) {
		cerr << mapName << " is not a map." << endl;
		return;
	}
	
	TiXmlElement* name = root->FirstChildElement("name");
	if(name) {
		mapName = name->GetText();
	}
	cout << "Loading map " << mapName << endl;
	
	TiXmlElement* planet = root->FirstChildElement("planet");

	while(planet) {
		TiXmlElement* dynamicNode = planet->FirstChildElement("dynamic");
		bool dynamic = false;
		if(dynamicNode) {
			dynamic = (string(dynamicNode->GetText()) == "true");
		}

		float x = atof(planet->FirstChildElement("x")->GetText());
		float y = atof(planet->FirstChildElement("y")->GetText());
		float density = atof(planet->FirstChildElement("density")->GetText());
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
			density, dynamic,xSpeed, ySpeed, texture, engine->resourceManager()));

		planet = planet->NextSiblingElement("planet");
	}
	return;
	
}
