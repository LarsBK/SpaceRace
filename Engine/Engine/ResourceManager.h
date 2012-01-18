#ifndef RESOURCEMANAGER_IKNA7F02

#define RESOURCEMANAGER_IKNA7F02
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

namespace z {

	class LoadedResource {
		public:
		sf::Image* im;
		string filename;

		unsigned int count;

		LoadedResource(string f, sf::Image* i) {
			im = i;
			filename = f;
		}
	};

	class ResourceManager {

		vector<LoadedResource*> list;

		public:
		sf::Image* getImage(string filename);
		void unloadImage(string filename);
		void unloadImage(sf::Image* im);

	};

}


#endif /* end of include guard: RESOURCEMANAGER_IKNA7F02 */
