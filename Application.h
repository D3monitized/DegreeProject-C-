#pragma once

namespace Engine 
{
	class Application {

	public:
		Application()
		{
		}
		~Application()
		{
		}

		virtual void Start()
		{
		}

		virtual void Run()
		{
		}
	};

	Application* CreateApplication();
}

