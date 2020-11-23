#include "Properties.hpp"
#include "..\include\Properties.hpp"

namespace Lucy
{

	//const sf::String Properties::PsetName()
	//{
	//	return pName;
	//}

	void Properties::PsetName(const sf::String& ControlName)
	{
		Name = ControlName;
	}

	//const sf::Vector2f Properties::PsetSize()
	//{
	//	return mySize;
	//}

	void Properties::PsetSize(const sf::Vector2f& ControlSize)
	{
		Size = ControlSize;
		PropertyChanged(pChanged::PropertySize);
	}

	//const sf::Vector2f Properties::PsetLocation()
	//{
	//	return myLocation;
	//}

	void Properties::PsetLocation(const sf::Vector2f& ControlLocation)
	{
		Location = ControlLocation;
	}

	//const float Properties::PsetCornerRadius()
	//{
	//	return myCornerRadius;
	//}

	void Properties::PsetCornerRadius(float CRadius)
	{
		CornerRadius = CRadius;
		PropertyChanged(pChanged::PropertyCornerRadius);
	}

	//const unsigned int Properties::PsetCornerPoints()
	//{
	//	return myCornerPointCount;
	//}

	void Properties::PsetCornerPoints(unsigned int PointCount)
	{
		CornerPoints = PointCount;
		PropertyChanged(pChanged::PropertyCornerPoints);
	}

	//const sf::Color Properties::PsetOutlineColor()
	//{
	//	return PsetOutlineColor;
	//}

	void Properties::PsetOutlineColor(sf::Color OColor)
	{
		OutlineColor = OColor;
		PropertyChanged(pChanged::PropertyOutlineColor);
	}

	//const sf::Color Properties::PsetFillColor()
	//{
	//	return myFillColor;
	//}

	void Properties::PsetFillColor(sf::Color FColor)
	{
		FillColor = FColor;
		PropertyChanged(pChanged::PropertyFillColor);
	}

	//const float Properties::PsetOutlineThickness()
	//{
	//	return myOutlineThickness;
	//}

	void Properties::PsetOutlineThickness(float Thickness)
	{
		OutlineThickness = Thickness;
		PropertyChanged(pChanged::PropertyOutlineThickness);
	}

	//const Lucy::Corners Properties::PsetStyle()
	//{
	//	return myStyle;
	//}

	void Properties::PsetStyle(Lucy::Corners ControlStyle)
	{
		Style = ControlStyle;
		PropertyChanged(pChanged::PropertyStyle);
	}

	void Properties::NotifyCallback(std::function<void(int)> CallbackFunction)
	{
		myCallbackFunction = CallbackFunction;
		CallbackSetup = true;
	}

	void Properties::PropertyChanged(int WhatProperty)
	{
		if (CallbackSetup)
			myCallbackFunction(WhatProperty);
	}


}