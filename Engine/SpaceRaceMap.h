#ifndef SPACERACEMAP_ZMBYZC9C
#define SPACERACEMAP_ZMBYZC9C

#include "Planet.h"
#include "Engine/Map.h"

using namespace z;

class SpaceRaceMap : public Map {
	
	public:
	SpaceRaceMap(Engine* e) : Map(e) {}
	virtual void interpret(TiXmlElement* d);
};

#endif /* end of include guard: SPACERACEMAP_ZMBYZC9C */
