#include "FactorioApp.h"
#include <chrono>

//This is the main game file. From here we'll handle all game related logic

std::set<Engine::GameObject*> Engine::GameObject::_instances;
sf::Time DeltaTime;


Factorio::Factorio() //Called when application is run
{
	_window = new sf::RenderWindow(sf::VideoMode(400, 400), "Game Window");
}

Factorio::~Factorio() //Called when application is closed
{
	delete _window;
}

void Factorio::Start() //Called after application has opened up (before Factorio::Run)
{
	//Any GameObjects created at start should be created before this loop in order to utilize their start function
	for (Engine::GameObject* go : Engine::GameObject::GetInstances())
	{
		go->Start();
	}
}

void Factorio::Run() //Called once when application has opened
{
	sf::Clock deltaClock; 
	
	while (_window->isOpen()) //Main gameplay loop
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		for (Engine::GameObject* go : Engine::GameObject::GetInstances())
		{
			go->Tick();
		}

		_window->clear();
		for (Engine::GameObject* go : Engine::GameObject::GetInstances())
		{
			go->Draw(*_window);
		}
		_window->display();
	
		DeltaTime = deltaClock.restart(); 
	}
}
