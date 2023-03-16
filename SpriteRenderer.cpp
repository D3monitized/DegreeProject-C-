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

	void SpriteRenderer::SetScale(sf::Vector2f scale) 
	{
		_sprite->setScale(scale); 
		_sprite->setOrigin(_sprite->getLocalBounds().width / 2, _sprite->getLocalBounds().height / 2); 
	}

	sf::Vector2f SpriteRenderer::GetScale() 
	{
		return _sprite->getScale(); 
	}
}