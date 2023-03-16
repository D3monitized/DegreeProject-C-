#pragma once
#include <SFML/System.hpp>

namespace Engine {
	class Transform {
	public: 
		Transform()
		{
			_position = sf::Vector2f(0, 0); 
			_scale = sf::Vector2f(1, 1); 
		}

		~Transform()
		{

		}

	public: 
		sf::Vector2f _position;
		sf::Vector2f _scale; 

	};
}