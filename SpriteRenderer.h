#pragma once

namespace Engine {
	class SpriteRenderer {

	public:
		SpriteRenderer()
		{
			_sprite = new sf::Sprite();
		}
		SpriteRenderer(std::string imgPath)
		{
			_sprite = new sf::Sprite(); 
			sf::Texture* tex = new sf::Texture(); 
			tex->loadFromFile(imgPath);
			_sprite->setTexture(*tex, true);
			delete tex; 
		}
		~SpriteRenderer()
		{
			delete _sprite; 
		}

		void SetTexture(std::string imgPath)
		{
			sf::Texture* tex = new sf::Texture(); 
			tex->loadFromFile(imgPath); 
			_sprite->setTexture(*tex, true); 
			delete tex; 
		}

		sf::Sprite* GetSprite() { return _sprite; }

	private: 
		sf::Sprite* _sprite; 
	};
}
