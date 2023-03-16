#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine {
	class SpriteRenderer {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void SetTexture(std::string imgPath);
		void UpdatePosition(sf::Vector2f position); 
		void SetScale(sf::Vector2f scale); 
		sf::Vector2f GetScale(); 

		sf::Sprite& GetSprite() { return *_sprite; }
		
	private: 
		sf::Sprite* _sprite;
		sf::Texture* _texture;
	};
}
