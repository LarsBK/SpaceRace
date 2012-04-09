#ifndef TEXTUREDGAMEOBJECT_ACYWKM2R

#define TEXTUREDGAMEOBJECT_ACYWKM2R

#include "GameObject.h"
#include "ResourceManager.h"

namespace z {

	class TexturedGameObject : public GameObject {
		
		ResourceManager* resMan;
		protected:
		sf::Sprite sprite;

		public:
		TexturedGameObject(string textureFile, ResourceManager* man);
		TexturedGameObject(ResourceManager* man);
/*
		~TexturedGameObject() {
			resMan->unloadImage(((sf::Sprite*) sprite)->GetImage());
			delete sprite;
		}
*/

		virtual unsigned int spriteHeight();
		virtual unsigned int spriteWidth();
		virtual sf::Transformable* getTransformable();
		virtual sf::Drawable* getDrawable();
		
		bool setTexture(string filename);
	};
}
#endif /* end of include guard: TEXTUREDGAMEOBJECT_ACYWKM2R */
