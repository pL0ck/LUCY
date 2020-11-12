#include <WorkSpace.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "UITest", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::Event event;
	sf::Clock clock;

	Lucy::WorkSpace LucyUI;
	LucyUI.Initialize(&window);
	Lucy::Button btn;
	LucyUI.Add(btn);



	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			LucyUI.HandleEvent(event);
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		LucyUI.Update(0.f);
		window.clear();
		window.display();
	}
}