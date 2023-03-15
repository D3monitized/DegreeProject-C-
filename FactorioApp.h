#pragma once
#include "Engine.h"


class Factorio : public Engine::Application {
public:
	Factorio();
	~Factorio(); 

	void Start() override; 
	void Run() override; 

private: 
	sf::RenderWindow* _window; 
};

Engine::Application* Engine::CreateApplication()
{
	return new Factorio();
}