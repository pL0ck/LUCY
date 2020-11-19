#include "Properties.hpp"
#include "..\include\Properties.hpp"

namespace Lucy
{

	const sf::String Properties::Name()
	{
		return pName;
	}

	void Properties::Name(const sf::String& myName)
	{
		pName = myName;
	}

	const sf::Vector2f Properties::Size()
	{
		return mySize;
	}

	void Properties::Size(const sf::Vector2f& ControlSize)
	{
		mySize = ControlSize;
	}

	const sf::Vector2f Properties::Location()
	{
		return myLocation;
	}

	void Properties::Location(const sf::Vector2f& ControlLocation)
	{
		myLocation = ControlLocation;
	}

	const float Properties::CornerRadius()
	{
		return myCornerRadius;
	}

	void Properties::CornerRadius(float CRadius)
	{
		myCornerRadius = CRadius;
	}

	const unsigned int Properties::CornerPointCount()
	{
		return myCornerPointCount;
	}

	void Properties::CornerPointCount(unsigned int& PointCount)
	{
		myCornerPointCount = PointCount;
	}

	const sf::Color Properties::OutlineColor()
	{
		return myOutlineColor;
	}

	void Properties::OutlineColor(sf::Color OColor)
	{
		myOutlineColor = OColor;
	}

	const sf::Color Properties::FillColor()
	{
		return myFillColor;
	}

	void Properties::FillColor(sf::Color FColor)
	{
		myFillColor = FColor;
	}

	const float Properties::OutlineThickness()
	{
		return myOutlineThickness;
	}

	void Properties::OutlineThickness(float Thickness)
	{
		myOutlineThickness = Thickness;
	}

	const Lucy::Corners Properties::Style()
	{
		return myStyle;
	}

	void Properties::Style(Lucy::Corners ControlStyle)
	{
		myStyle = ControlStyle;
	}


}