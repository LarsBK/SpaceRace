#ifndef RESOURCEMANAGER_IKNA7F02

#define RESOURCEMANAGER_IKNA7F02
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

namespace z {

	class LoadedResource {
		public:
		sf::Texture im;
		string filename;

		unsigned int count;

		LoadedResource(string f) {
			filename = f;
		}
	};

	class ResourceManager {

		vector<LoadedResource*> list;

		public:
		sf::Texture* getTexture(string filename);
		void unloadTexture(string filename);
		void unloadTexture(sf::Texture* im);

	};

}


#endif /* end of include guard: RESOURCEMANAGER_IKNA7F02 */
