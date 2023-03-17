#include "FactorioApp.h"
#include "GameObject.h"
#include "Input.h"
#include <chrono>

//This is the main game file. From here we'll handle all game related logic

extern sf::Time DeltaTime; 

class TestObject : public Engine::GameObject {
#include "GameSprites.h"
public: 
	TestObject() 
	{
	}
	~TestObject()
	{
	}

	void Start() override
	{
		spriteRenderer.SetTexture(TEST_SPRITE);
		transform._scale = sf::Vector2f(.25f, .25f);
		transform._position = sf::Vector2f(600 / 2, 400 / 2); 
	}
	void Tick() override
	{
		transform._position += sf::Vector2f(1, 0) * DeltaTime.asSeconds() * 5.f;
	}

};

template <typename T>
T* Spawn() { //Creates a new instance of an object and returns its address
	return new T(); 
}

Factorio::Factorio() //Called when application is run
{
	 
}

Factorio::~Factorio() //Called when application is closed
{
	
}

void Factorio::Start() //Called after application has opened up (before Factorio::Run)
{
	TestObject* to = Spawn<TestObject>(); 	
}

void Factorio::Run() //Called every frame until application is closed
{
	if (Engine::GetKeyDown(Keyboard_W))
		std::cout << "W key" << std::endl; 

}

void Factorio::OnClose() //Called after application is closed 
{

}
