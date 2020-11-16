#include "Button.hpp"

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
	}

	void Button::Draw()
	{
		std::cout << "Button Draw [" << Name().toAnsiString() << "]\n";
	}

	

}
	