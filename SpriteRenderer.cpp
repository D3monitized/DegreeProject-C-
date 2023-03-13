#include "SpriteRenderer.h"

namespace Engine {
	SpriteRenderer::SpriteRenderer() {		
	}

	SpriteRenderer::SpriteRenderer(std::string imgPath) {		
		sf::Texture* tex = new sf::Texture();
		tex->loadFromFile(imgPath);
		_sprite->setTexture(*tex, true);
		delete tex;
	}

	SpriteRenderer::~SpriteRenderer() {
		
	}

	void SpriteRenderer::SetTexture(std::string imgPath) {
		sf::Texture* tex = new sf::Texture();
		tex->loadFromFile(imgPath);
		_sprite->setTexture(*tex, true);
		delete tex;
	}

	sf::Sprite* SpriteRenderer::GetSprite() { return _sprite; }
}