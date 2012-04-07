#include "Map.h"

Map::Map(string fn) : filename(fn) {
	
}

bool Map::load() {
	TiXmlDocument doc(filename.c_str());
	if(!doc.LoadFile()) {
		return false;
	}
	doc.Print();
	TiXmlElement* current = doc.RootElement();
	string name;
	current->QueryStringAttribute("name", &name);
	cout << "name: " << name << endl;
	return true;
}

