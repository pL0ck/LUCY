#pragma once
#include "Control.hpp"
#include "Config.hpp"
#include <string>

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

	private:
		 sf::String myName;
	};

}

