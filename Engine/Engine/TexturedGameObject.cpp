#ifndef TEXTUREDGAMEOBJECT_T8OHCU4O

#define TEXTUREDGAMEOBJECT_T8OHCU4O
#include "TexturedGameObject.h"


z::TexturedGameObject::TexturedGameObject(string textureFile, ResourceManager* man) {
	sf::Texture* im = man->getTexture(textureFile);
	resMan = man;
	sprite.setTexture(*im);
}

z::TexturedGameObject::TexturedGameObject(ResourceManager* man) {
	resMan = man;
}

bool z::TexturedGameObject::setTexture(string filename) {
	sf::Texture* i = resMan->getTexture(filename);
	if(i == 0) {
		return false;
	}
	sprite.setTexture(*i);
	return true;
}

unsigned int z::TexturedGameObject::spriteHeight(){
	return sprite.getTexture()->getSize().y;
}

unsigned int z::TexturedGameObject::spriteWidth() {
	return sprite.getTexture()->getSize().x;
}

sf::Transformable* z::TexturedGameObject::getTransformable() {
	return &sprite;
}

sf::Drawable* z::TexturedGameObject::getDrawable() {
	return &sprite;
}


#endif /* end of include guard: TEXTUREDGAMEOBJECT_T8OHCU4O */
