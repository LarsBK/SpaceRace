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

		LoadedResource(string f, T i) {
			t = i;
			filename = f;
			count = 0;
		}
	};

	class ResourceManager {

		Engine* engine;

		vector<LoadedResource<sf::Image*>*> imageList;
		vector<LoadedResource<TiXmlDocument*>*>	xmlList;

		public:
		ResourceManager(Engine* e) {
			engine = e;
		}

		sf::Image* getImage(string filename);
		TiXmlDocument* getXml(string filename);
		void unloadXml(TiXmlDocument* x);
		void unloadImage(string filename);
		void unloadImage(sf::Image* im);

	};

}


#endif /* end of include guard: RESOURCEMANAGER_IKNA7F02 */
