#pragma once
#include "Config.hpp"
#include "RoundedRectangle.hpp"
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

namespace Lucy
{
	class LUCY_API Properties
	{
	public:

		enum pChanged : int
		{
			PropertySize,
			PropertyCornerRadius,
			PropertyCornerPoints,
			PropertyOutlineColor,
			PropertyFillColor,
			PropertyOutlineThickness,
			PropertyStyle

		};

		void PsetName(const sf::String& myName);
 
		void PsetSize(const sf::Vector2f& ControlSize);

		void PsetLocation(const sf::Vector2f& ControlLocation);

		void PsetCornerRadius(float Radius);

		void PsetCornerPoints(unsigned int PointCount);

		void PsetOutlineColor(sf::Color OColor);

		void PsetFillColor(sf::Color FColor);

		void PsetOutlineThickness(float Thickness);

		void PsetStyle(Lucy::Corners ControlStyle);

		//Fields
		sf::Color OutlineColor{ sf::Color::White };
		sf::Color FillColor{ sf::Color::White };
		unsigned int CornerPoints{ 5 };
		float CornerRadius{ 5.f };
		sf::Vector2f Location;
		float OutlineThickness{ 0.f };
		sf::Vector2f Size{ sf::Vector2f(50.f,50.f) };
		sf::String Name;

		Lucy::Corners Style{ Lucy::Corners::All };

	protected:
		void NotifyCallback(std::function<void(int)> CallbackFunction);


	private:
		//sf::String pName;
		//sf::Vector2f mySize{sf::Vector2f(50.f,50.f )};
		//sf::Vector2f myLocation{ sf::Vector2f(100.f,100.f) };
		//float myCornerRadius{ 5.f };
		//unsigned int myCornerPointCount{ 5 };
		//sf::Color myOutlineColor{ sf::Color::Red };
		//sf::Color myFillColor{ sf::Color::White };
		//float myOutlineThickness{ 2.f };
		//Lucy::Corners myStyle{ Lucy::Corners::All };
		
		std::function<void(int)> myCallbackFunction;
		bool CallbackSetup = false;
		void PropertyChanged(int WhatChanged);

	};
}


