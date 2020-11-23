#include "Control.hpp"

namespace Lucy
{
	Control::Control()
	{
		ControlType = CType::None;
		std::cout << "Control created\n";
	}
	
	Control::~Control()
	{
		std::cout << "Control destroyed\n";
	}

	void Control::SetType(CType myType)
	{
		ControlType = myType;
	}

	Control::CType Control::GetType()
	{
		return ControlType;
	}

	void Control::Draw(sf::RenderWindow *Target)
	{
		std::cout << "Base draw\n";
	}
}

