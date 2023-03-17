#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <set>

#include "GameObject.h"
#include "Application.h"

sf::RenderWindow* Window = new sf::RenderWindow(sf::VideoMode(600, 400), "Application Window");
std::set<Engine::GameObject*> Engine::GameObject::_instances;

sf::Time DeltaTime = sf::Time();  

void WindowPollEvent(); 
void GameObjectStart();
void GameObjectTick();
void GameObjectDraw();

int main()
{
	auto app = Engine::CreateApplication();
	app->Start();	
	GameObjectStart(); 

	sf::Clock deltaClock; 
	
	while (Window->isOpen())
	{		
		WindowPollEvent();
		GameObjectTick(); 
		app->Run();

		Window->clear();		
		GameObjectDraw(); 
		Window->display();
		DeltaTime = deltaClock.restart();		
	}

	app->OnClose();
	delete app;
	return 0;
}

void WindowPollEvent() 
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window->close();
		}
	}
}

void GameObjectStart() 
{
	for (Engine::GameObject* go : Engine::GameObject::GetInstances())
	{
		go->Start();
	}
}

void GameObjectTick() 
{
	for (Engine::GameObject* go : Engine::GameObject::GetInstances())
	{
		go->Tick();
	}
}

void GameObjectDraw() 
{
	for (Engine::GameObject* go : Engine::GameObject::GetInstances())
	{
		go->Draw(*Window);
	}
}