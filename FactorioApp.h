#pragma once
#include "Engine.h"


class Factorio : public Engine::Application {
public:
	Factorio();
	~Factorio(); 

	void Start() override; 
	void Run() override; 
	void OnClose() override; 
};

Engine::Application* Engine::CreateApplication()
{
	return new Factorio();
}