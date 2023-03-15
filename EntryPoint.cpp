#include "Engine.h"

int main() 
{
	auto app = Engine::CreateApplication(); 

	app->Start(); 
	app->Run(); 

	delete app; 
	return 0; 
}