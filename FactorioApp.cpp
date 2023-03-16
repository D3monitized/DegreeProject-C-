#include "FactorioApp.h"
#include <chrono>

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
		sprite.SetTexture(TEST_SPRITE);
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

//This is the main game file. From here we'll handle all game related logic
Factorio::Factorio() //Called when application is run
{
	 
}

Factorio::~Factorio() //Called when application is closed
{
	
}

void Factorio::Start() //Called after application has opened up (before Factorio::Run)
{
	TestObject* ob = Spawn<TestObject>();
}

void Factorio::Run() //Called every frame until application is closed
{
	
}

void Factorio::OnClose() //Called after application is closed 
{

}
