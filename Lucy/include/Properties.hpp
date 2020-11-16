#pragma once
#include "Config.hpp"
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

	private:
		sf::String pName;
		sf::Vector2f mySize;
		sf::Vector2f myLocation;
	};
}


