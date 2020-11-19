#include "Button.hpp"
#include "..\include\Button.hpp"

namespace Lucy
{
	Button::Button()
	{
	}

	Button::~Button()
	{
	}

	Button::Button(sf::String ButtonName)
	{
		Name(ButtonName);
		SetType(Control::CType::Button);
		myButton = Lucy::RoundedRectangle(sf::Vector2f(80.f, 25.f), 0.f, 0);
	}

	Button::Button(sf::String ButtonName, sf::Vector2f ButtonSize, sf::Vector2f ButtonLocation)
	{
		Name(ButtonName);
		Size(ButtonSize);
		Location(ButtonLocation);
		SetType(Control::CType::Button);
		myButton = Lucy::RoundedRectangle(ButtonSize, 5.f, 5.f);
	}

	void Button::Draw()
	{
		std::cout << "Button Draw [" << Name().toAnsiString() << "]\n";

	}

	

}
	