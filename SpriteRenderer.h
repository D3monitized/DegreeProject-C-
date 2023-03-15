#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine {
	class SpriteRenderer {
	public:
		SpriteRenderer();
		SpriteRenderer(std::string imgPath);
		~SpriteRenderer();

		void SetTexture(std::string imgPath);
		sf::Sprite* GetSprite();

	private: 
		sf::Sprite* _sprite = new sf::Sprite(); 
	};
}
