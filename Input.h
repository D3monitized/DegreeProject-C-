#pragma once
#include <SFML/Window.hpp>

extern sf::Event Event; 

namespace Engine 
{

	struct Key {
		Key(sf::Keyboard::Key code) 
		{
			keyCode = code; 
		}

		bool released = true; 
		sf::Keyboard::Key keyCode; 
	};

	bool GetKeyDown(Key key) 
	{
		if (Event.type == sf::Event::KeyPressed && Event.key.code == key.keyCode && key.released)
		{
			key.released = false;
			return true;
		}
		else if (Event.type == sf::Event::KeyReleased && Event.key.code == key.keyCode) 
		{
			key.released = true;
			return false; 
		}

		return false; 
	}


#ifndef Keyboard_W
	Key W = Key(sf::Keyboard::W);
	#define Keyboard_W Engine::W
#endif
#ifndef Keyboard_A
	Key A = Key(sf::Keyboard::A);
	#define Keyboard_A Engine::A
#endif
#ifndef Keyboard_S
	Key S = Key(sf::Keyboard::S);
	#define Keyboard_S Engine::S
#endif
#ifndef Keyboard_D
	Key D = Key(sf::Keyboard::D);
	#define Keyboard_D Engine::D
#endif

}