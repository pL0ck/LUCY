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
		PsetName(ButtonName);
		SetType(Control::CType::Button);
		myButton.RoundedRectangle2(sf::Vector2f(80.f, 25.f), 5.f, 5);
		myButton.setPosition(sf::Vector2f(50.f, 50.f));
		SetupCallback();
	}

	Button::Button(sf::String ButtonName, sf::Vector2f ButtonSize, sf::Vector2f ButtonLocation)
	{
		PsetName(ButtonName);
		PsetSize(ButtonSize);
		PsetLocation(ButtonLocation);
		SetType(Control::CType::Button);
		
		myButton.RoundedRectangle2(Size, 5.f, 5);
		myButton.setPosition(Location);
		myButton.setFillColor(FillColor);
		SetupCallback();
	}

	void Button::Draw(sf::RenderWindow *Target)
	{
		//std::cout << "Button Draw [" << Name.toAnsiString() << "]\n";
		Target->draw(myButton);
	}

	void Button::OnPropertyChanged(int WhatChanged)
	{
		switch (WhatChanged)
		{
		case pChanged::PropertySize:
			std::cout << "Size property changed" << "\n";
			myButton.setSize(Size);
			break;

		case pChanged::PropertyCornerPoints:
			myButton.setCornerPointCount(CornerPoints);
			break;

		case pChanged::PropertyCornerRadius:
			myButton.setCornerRadius(CornerRadius);
			break;
			
		case pChanged::PropertyFillColor:
			myButton.setFillColor(FillColor);
			break;

		case pChanged::PropertyOutlineColor:
			myButton.setOutlineColor(OutlineColor);

		}

		std::cout << "Property Changed: " <<  WhatChanged << "\n";
		myButton.UpdateShape();
	}
	void Button::SetupCallback()
	{
		NotifyCallback(std::bind(&Button::OnPropertyChanged, this, std::placeholders::_1));
	}
}
	