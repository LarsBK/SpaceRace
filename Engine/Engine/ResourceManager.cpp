#include "ResourceManager.h"

sf::Texture* z::ResourceManager::getTexture(string filename) {
	for(unsigned int i = 0; i < list.size(); i++) {
		if(filename == list[i]->filename) {
			return &list[i]->im;
		}
	}
	
	cout << "Loading " << filename << endl;
	LoadedResource* lr = new LoadedResource(filename);
	if(!lr->im.loadFromFile(filename)) {
		cout << "Failed!" << endl;
		delete lr;
		return 0;
	}
	
	list.push_back(lr);
	return &lr->im;
}

void z::ResourceManager::unloadTexture(sf::Texture* im) {
	for(unsigned int i = 0; i < list.size(); i++) {
		if(list[i] && im == &list[i]->im) {
			list[i]->count--;
			if(list[i]->count == 0) {
				cout << "Unloading " << list[i]->filename << endl;
				delete list[i];
				list.erase(list.begin()+i);
			}
			return;
		}
	}

	return;
}

