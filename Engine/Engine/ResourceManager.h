#ifndef RESOURCEMANAGER_IKNA7F02

#define RESOURCEMANAGER_IKNA7F02
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tinyxml/tinyxml.h"

using namespace std;

namespace z {

	class Engine;
	
	template <class T>
	class LoadedResource {
		public:
		T t;
		string filename;

		unsigned int count;

		LoadedResource(string f) {
			filename = f;
			count = 0;
		}
	};

	class ResourceManager {

		Engine* engine;

		vector<LoadedResource<sf::Texture>*> imageList;
		vector<LoadedResource<TiXmlDocument>*>	xmlList;

		public:
		sf::Texture* getTexture(string filename);
		void unloadTexture(string filename);
		void unloadTexture(sf::Texture* im);
		ResourceManager(Engine* e) {
			engine = e;
		}

		TiXmlDocument* getXml(string filename);
		void unloadXml(TiXmlDocument* x);

	};

}


#endif /* end of include guard: RESOURCEMANAGER_IKNA7F02 */
