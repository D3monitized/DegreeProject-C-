#pragma once

namespace Engine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Start(); 
		virtual void Run(); 
	};

	Application* CreateApplication(); 
}