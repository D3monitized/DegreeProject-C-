#pragma once

extern Engine::Application* Engine::CreateApplication(); 

int main()
{
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	/*sf::RenderWindow window(sf::VideoMode(400, 400), "Window");
		sf::CircleShape circle(100.f);
		circle.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}



				window.clear();
				window.draw(circle);
				window.display();
			}

		}

		return 0;*/
}