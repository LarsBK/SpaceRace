#ifndef MAP_HVG06X4Q

#define MAP_HVG06X4Q

#include "Engine/ResourceManager.h"
#include "Engine/tinyxml/tinyxml.h"
#include "Planet.h"
#include "Engine/Box2DModule.h"
#include "Engine/WindowModule.h"

using namespace z;

class Map {
	
	string filename;
	ResourceManager imageManager;
	string mapName;

	vector<GameObject*> objects;
	
	public:
	Map(string fn);
	~Map();
	bool load();
	vector<GameObject*>* getObjects();
	void spawn(Box2DModule* box2d, WindowModule* window);
};

#endif /* end of include guard: MAP_HVG06X4Q */
