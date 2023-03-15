#pragma once
#include "Engine.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TestObject.h"

class Factorio : public Engine::Application {
public:
	Factorio();
	~Factorio(); 

	void Start() override; 
	void Run() override; 

private: 
	sf::RenderWindow* _window; 
	sf::Sprite* _sprite; 
};

Engine::Application* Engine::CreateApplication() {
	return new Factorio(); 
}