#include "Properties.hpp"

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


}