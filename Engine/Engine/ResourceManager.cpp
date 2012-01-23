#include "ResourceManager.h"

sf::Image* z::ResourceManager::getImage(string filename) {
	for(unsigned int i = 0; i < imageList.size(); i++) {
		if(filename == imageList[i]->filename) {
			return imageList[i]->t;
		}
	}
	
	cout << "Loading " << filename << endl;
	sf::Image* im = new sf::Image();
	if(!im->LoadFromFile(filename)) {
		cout << "Failed!" << endl;
		delete im;
		return 0;
	}
	
	imageList.push_back(new LoadedResource<sf::Image*>(filename, im));
	return im;
}

void z::ResourceManager::unloadImage(sf::Image* im) {
	for(unsigned int i = 0; i < imageList.size(); i++) {
		if(imageList[i] && im == imageList[i]->t) {
			imageList[i]->count--;
			if(imageList[i]->count == 0) {
				cout << "Unloading " << imageList[i]->filename << endl;
				delete imageList[i]->t;
				delete imageList[i];
				imageList.erase(imageList.begin()+i);
			}
			return;
		}
	}

	return;
}

