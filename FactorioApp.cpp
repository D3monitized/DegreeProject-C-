#include "FactorioApp.h"

//This is the main game file. From here we'll handle all game related logic

std::set<Engine::GameObject*> Engine::GameObject::_instances; 
static sf::Sprite sprite; 
static sf::Texture tex; 

Factorio::Factorio()
{
	_window = new sf::RenderWindow(sf::VideoMode(400, 400), "Game Window");
}

Factorio::~Factorio()
{
	delete _window; 
}

void Factorio::Start()
{	
	tex.loadFromFile("Resources/Sprites/Avatar.png");
	sprite.setTexture(tex); 
	sprite.setPosition(sf::Vector2f(10.f, 50.f)); 
	sprite.setScale(sf::Vector2f(10, 10)); 

	//Any GameObjects created at start should be created before this loop in order to utilize their start function
	for (Engine::GameObject* go : Engine::GameObject::GetInstances()) 
	{
		go->Start();
	}	
}

void Factorio::Run()
{
	while (_window->isOpen())
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
		_window->draw(sprite); 
		_window->display();
	}	
}
