#pragma once
#include <SFML/System.hpp>

namespace Engine {
	class Transform {
	public: 
		Transform()
		{

		}

		~Transform()
		{

		}

	public: 
		sf::Vector2f _position;
		sf::Vector2f _scale; 

	};
}