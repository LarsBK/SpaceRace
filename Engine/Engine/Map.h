#ifndef MAP_HVG06X4Q

#define MAP_HVG06X4Q

#include "ResourceManager.h"
#include "Engine.h"
#include "tinyxml/tinyxml.h"

namespace z {

	class GameObject;

	class Map {
		TiXmlDocument* doc;
		protected:
		Engine* engine;
		vector<GameObject*> objects;
		string mapName;

		public:
		Map(Engine* e) {
			engine = e;
		}

		~Map();
		bool load(string filename) {
			doc = engine->resourceManager()->getXml(filename);
			if(! doc)
				return false;

			mapName = filename;
			interpret(doc->RootElement());
			return true;
		}

		virtual void interpret(TiXmlElement* d) {}

		vector<GameObject*>* getObjects() {
			return &objects;
		}
	};

}

#endif /* end of include guard: MAP_HVG06X4Q */
