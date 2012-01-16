#ifndef MAP_HVG06X4Q

#define MAP_HVG06X4Q

#include "Engine/ResourceManager.h"
#include "tinyxml/tinyxml.h"

using namespace z;

class Map {
	
	string filename;
	ResourceManager imageManager;
	
	public:
	Map(string fn);
	~Map();
	bool load();
};

#endif /* end of include guard: MAP_HVG06X4Q */
