#include "Engine.h"

class Factorio : public Engine::Application {

public: 
	Factorio()
	{
		
	}
	~Factorio()
	{

	}

};

Engine::Application* Engine::CreateApplication()
{
	return new Factorio(); 
}