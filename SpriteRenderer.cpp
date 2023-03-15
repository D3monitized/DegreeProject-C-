#include "SpriteRenderer.h"

namespace Engine {
	SpriteRenderer::SpriteRenderer() 
	{
		_sprite = new sf::Sprite(); 
		_texture = new sf::Texture(); 
	}

	SpriteRenderer::~SpriteRenderer() 
	{		
		delete _sprite; 
		delete _texture; 
	}

	void SpriteRenderer::SetTexture(std::string imgPath) 	
	{
		_texture->loadFromFile(imgPath); 
		_sprite->setTexture(*_texture); 
	}
}