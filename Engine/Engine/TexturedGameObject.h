#ifndef TEXTUREDGAMEOBJECT_ACYWKM2R

#define TEXTUREDGAMEOBJECT_ACYWKM2R

#include "GameObject.h"
#include "ResourceManager.h"

namespace z {

	class TexturedGameObject : protected GameObject {
		
		ResourceManager* resMan;

		public:
		TexturedGameObject(string textureFile, ResourceManager* man) {
			sf::Texture* im = man->getTexture(textureFile);
			resMan = man;
			sprite = (TransformableDrawable*) new sf::Sprite();
			((sf::Sprite*) sprite)->setTexture(*im); //??
		}
/*
		~TexturedGameObject() {
			resMan->unloadImage(((sf::Sprite*) sprite)->GetImage());
			delete sprite;
		}
*/

		virtual unsigned int spriteHeight(){
			return ((sf::Sprite*) sprite)->getTexture()->getHeight();
		}
		
		virtual unsigned int spriteWidth() {
			return ((sf::Sprite*) sprite)->getTexture()->getWidth();
		}

		
	};
}
#endif /* end of include guard: TEXTUREDGAMEOBJECT_ACYWKM2R */
