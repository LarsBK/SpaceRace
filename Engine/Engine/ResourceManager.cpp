#include "ResourceManager.h"

sf::Texture* z::ResourceManager::getTexture(string filename) {
	for(unsigned int i = 0; i < imageList.size(); i++) {
		if(filename == imageList[i]->filename) {
			return &imageList[i]->t;
		}
	}
	
	cout << "Loading " << filename << endl;
	LoadedResource<sf::Texture>* lr = new LoadedResource<sf::Texture>(filename);
	if(!lr->t.loadFromFile(filename)) {
		cout << "Failed!" << endl;
		delete lr;
		return 0;
	}
	
	imageList.push_back(lr);
	return &lr->t;
}

void z::ResourceManager::unloadTexture(sf::Texture* im) {
	for(unsigned int i = 0; i < imageList.size(); i++) {
		if(imageList[i] && im == &imageList[i]->t) {
			imageList[i]->count--;
			if(imageList[i]->count == 0) {
				cout << "Unloading " << imageList[i]->filename << endl;
				delete imageList[i];
				imageList.erase(imageList.begin()+i);
			}
			return;
		}
	}

	return;
}

TiXmlDocument* z::ResourceManager::getXml(string filename) {
	for(unsigned i = 0; i < xmlList.size(); i++) {
		if(filename == xmlList[i]->filename) {
			xmlList[i]->count++;
			return &xmlList[i]->t;
		}
	}

	
	LoadedResource<TiXmlDocument>* lr = new LoadedResource<TiXmlDocument>(filename);
	TiXmlDocument* doc = &(lr->t);
	if(!doc->LoadFile(filename)) {
		cerr << "Error opening file: " << filename << " "
			<< doc->ErrorDesc() << endl;
		delete lr;
		return 0;
	}

	xmlList.push_back(lr);

	return doc;
}

void z::ResourceManager::unloadXml(TiXmlDocument* x) {
	for(unsigned i = 0; i < xmlList.size(); i++) {
		if( &xmlList[i]->t == x) {
			xmlList[i]->count--;
			if(xmlList[i]->count == 0) {
				cout << "Unloading " << xmlList[i]->filename << endl;
			delete xmlList[i];
			xmlList.erase(xmlList.begin()+i);
			}
			return;
		}
	}
	return;
}



