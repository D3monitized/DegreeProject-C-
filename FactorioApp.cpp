#include "FactorioApp.h"

//This is the main game file. From here we'll handle all game related logic

std::set<Engine::GameObject*> Engine::GameObject::_instances; 

Factorio::Factorio() {
	_window = new sf::RenderWindow(sf::VideoMode(400, 400), "Game Window");
}

Factorio::~Factorio() {
	delete _window; 
}

void Factorio::Start() {	

	//TestObject* to = new TestObject(); 

	_sprite = new sf::Sprite(); 
	sf::Texture* tex = new sf::Texture(); 

	tex->loadFromFile("C:/VSProjects/DegreeProject-C-/Avatar.PNG");
	_sprite->setTexture(*tex, true);


	//Any GameObjects created at start should be created before this loop in order to utilize their start function
	for (Engine::GameObject* go : Engine::GameObject::GetInstances()) 
	{
		go->Start();
	}	
}

void Factorio::Run() {
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
		_window->draw(*_sprite); 
		for (Engine::GameObject* go : Engine::GameObject::GetInstances())
		{
			_window->draw(*go->_spriteRenderer->GetSprite()); 
		}
		_window->display();
	}	
}
