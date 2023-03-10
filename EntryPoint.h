#pragma once

extern Engine::Application* Engine::CreateApplication();

int main()
{
	auto app = Engine::CreateApplication(); //Create the application 
	app->Start(); //Run the application start function

	sf::RenderWindow window(sf::VideoMode(400, 400), "Window"); //Create a SFML window
	sf::CircleShape circle(100.f); 
	circle.setFillColor(sf::Color::Green);

	while (window.isOpen()) //While window is open -> Run the application
	{
		sf::Event event; 
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //If 'X' button is pressed on the window -> close window
			{
				window.close();
			}

			app->Run();

			window.clear(); //clear frontbuffer
			window.draw(circle); //Draw on backbuffer
			window.display(); //Display backbuffer
		}
	}

	delete app;
	return 0;
}