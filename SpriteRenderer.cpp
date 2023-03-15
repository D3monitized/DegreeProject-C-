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

	void SpriteRenderer::UpdatePosition(sf::Vector2f position) 
	{
		_sprite->setPosition(position); 
	}

	void SpriteRenderer::SetTexture(std::string imgPath) 	
	{
		_texture->loadFromFile(imgPath); 
		_sprite->setTexture(*_texture); 
	}
}