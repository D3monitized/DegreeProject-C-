#include "Engine.h"

sf::RenderWindow* Window = new sf::RenderWindow(sf::VideoMode(600, 400), "Application Window");
std::set<Engine::GameObject*> Engine::GameObject::_instances;

sf::Time DeltaTime = sf::Time();  
int FrameCount = 0; 

int main()
{
	auto app = Engine::CreateApplication();

	app->Start();

	for (Engine::GameObject* go : Engine::GameObject::GetInstances())
	{
		go->Start();
	}

	sf::Clock deltaClock; 

	while (Window->isOpen())
	{
		sf::Event event;

		while (Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window->close();
			}
		}

		for (Engine::GameObject* go : Engine::GameObject::GetInstances())
		{
			go->Tick();
		}
		app->Run();

		Window->clear();
		for (Engine::GameObject* go : Engine::GameObject::GetInstances())
		{
			go->Draw(*Window);
		}
		Window->display();

		DeltaTime = deltaClock.restart();
		if (FrameCount + 1 == INT_MAX)
			FrameCount = 0; 
		else
			FrameCount++; 
	}

	app->OnClose();

	delete app;
	return 0;
}