#ifndef TEXTUREDGAMEOBJECT_ACYWKM2R

#define TEXTUREDGAMEOBJECT_ACYWKM2R

#include "GameObject.h"
#include "ResourceManager.h"

namespace z {

	class TexturedGameObject : protected GameObject {
		
		ResourceManager* resMan;

		public:
		TexturedGameObject(string textureFile, ResourceManager* man) {
			sf::Image* im = man->getImage(textureFile);
			resMan = man;
			sprite = new sf::Sprite();
			((sf::Sprite*) sprite)->SetImage(*im); //??
		}
/*
		~TexturedGameObject() {
			resMan->unloadImage(((sf::Sprite*) sprite)->GetImage());
			delete sprite;
		}
*/

		virtual unsigned int spriteHeight(){
			return ((sf::Sprite*) sprite)->GetImage()->GetHeight();
		}
		
		virtual unsigned int spriteWidth() {
			return ((sf::Sprite*) sprite)->GetImage()->GetWidth();
		}
		
	};
}
#endif /* end of include guard: TEXTUREDGAMEOBJECT_ACYWKM2R */
