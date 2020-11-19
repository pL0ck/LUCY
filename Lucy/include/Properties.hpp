#pragma once
#include "Config.hpp"
#include "RoundedRectangle.hpp"
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

namespace Lucy
{
	class LUCY_API Properties
	{
	public:
		const sf::String Name();
		void Name(const sf::String& myName);

		const sf::Vector2f Size();
		void Size(const sf::Vector2f& ControlSize);

		const sf::Vector2f Location();
		void Location(const sf::Vector2f& ControlLocation);

		const float CornerRadius();
		void CornerRadius(float Radius);

		const unsigned int CornerPointCount();
		void CornerPointCount(unsigned int& PointCount);

		const sf::Color OutlineColor();
		void OutlineColor(sf::Color OColor);

		const sf::Color FillColor();
		void FillColor(sf::Color FColor);

		const float OutlineThickness();
		void OutlineThickness(float Thickness);

		const Lucy::Corners Style();
		void Style(Lucy::Corners ControlStyle);


	private:
		sf::String pName;
		sf::Vector2f mySize;
		sf::Vector2f myLocation;
		float myCornerRadius;
		unsigned int myCornerPointCount;
		sf::Color myOutlineColor;
		sf::Color myFillColor;
		float myOutlineThickness;
		Lucy::Corners myStyle;
	};
}


