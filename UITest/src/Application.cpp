#include <WorkSpace.hpp>
#include <SFML/Graphics.hpp>
#include <LayoutGroup.hpp>
#include <Button.hpp>

int main()
{
	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "UITest", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::Event event;
	sf::Clock clock;

	Lucy::WorkSpace LucyUI;
	LucyUI.Initialize(window);
	Lucy::Button btn("myButton1",sf::Vector2f(75.f,24.f),sf::Vector2f(50.f,50.f));
	btn.PsetFillColor(sf::Color::Blue);
	btn.PsetOutlineColor(sf::Color::Red);
	btn.PsetCornerRadius(5);
	btn.PsetOutlineThickness(5.f);
	btn.PsetCornerPoints(6);
	LucyUI.Add(btn);
	//btn.Size(sf::Vector2f(50.f, 25.f));
	//btn.Location(sf::Vector2f(100.f, 100.f));

	//Lucy::Button btn2("myButton2");
	//LucyUI.Add(btn2);

	//Lucy::Button btn3("myButton3");
	//LucyUI.Add(btn3);

	//Lucy::Button btn4("myButton4");
	//LucyUI.Add(btn4);

	//Lucy::LayoutGroup lg1;
	//LucyUI.Add(lg1);
	//Lucy::Button btn5("myButton5");
	//lg1.Add(btn5);


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


		window.clear();
		LucyUI.Update(0.f);
		window.display();
	}

	getchar();
}