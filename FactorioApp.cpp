#include "FactorioApp.h"
#include "Engine.h"

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
T* Spawn() { 
	return new T(); 
}

Factorio::Factorio() 
{
	 
}

Factorio::~Factorio() 
{
	
}

void Factorio::Start() 
{
	TestObject* to = Spawn<TestObject>();

	
}

void Factorio::Run()
{
}

void Factorio::OnClose() 
{

}
