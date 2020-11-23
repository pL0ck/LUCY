#pragma once
#include "Control.hpp"
#include "Config.hpp"
#include "RoundedRectangle.hpp"
#include <string>
#include <memory>
#include <utility>

namespace Lucy
{
	class LUCY_API Button : public Lucy::Control
	{
	public:

		//Ctor
		Button();

		//Dtor
		~Button();

		Button(sf::String ButtonName);

		Button(sf::String ButtonName, sf::Vector2f ButtonSize, sf::Vector2f ButtonLocation);

		void Draw(sf::RenderWindow *Target);

		void OnPropertyChanged(int WhatChanged);

	private:
		Lucy::RoundedRectangle myButton;
		void SetupCallback();

	};

}

