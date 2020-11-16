#pragma once
#include "Control.hpp"
#include "Config.hpp"
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

		void Draw();

	private:

	};

}

