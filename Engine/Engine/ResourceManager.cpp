#include "ResourceManager.h"

sf::Image* z::ResourceManager::getImage(string filename) {
	for(unsigned int i = 0; i < list.size(); i++) {
		if(filename == list[i]->filename) {
			return list[i]->im;
		}
	}

	sf::Image* im = new sf::Image();
	if(!im->LoadFromFile(filename)) {
		delete im;
		return 0;
	}
	
	list.push_back(new LoadedResource(filename, im));
	return im;
}

void z::ResourceManager::unloadImage(sf::Image* im) {
	for(unsigned int i = 0; i < list.size(); i++) {
		if(list[i] && im == list[i]->im) {
			list[i]->count--;
			if(list[i]->count == 0) {
				cout << "Unloading " << list[i]->filename << endl;
				delete list[i]->im;
				delete list[i];
				list.erase(list.begin()+i);
			}
			return;
		}
	}

	return;
}

