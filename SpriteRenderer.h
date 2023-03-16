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

		sf::Sprite& GetSprite() { return *_sprite; }


		
	private: 
		sf::Sprite* _sprite;
		sf::Texture* _texture;
	};
}
