#pragma once
#include "Control.hpp"
#include "Config.hpp"
#include "Button.hpp"
#include <map>
#include <string>

namespace Lucy
{
	class LUCY_API Engine
	{
	public:

		//Ctor
		Engine();

		//Dtor
		~Engine();

		void Initialize();
		
		void Add(Lucy::Control* myControl);

		void DrawControls();

	protected:


	private:
		using myControls = std::map<sf::String, Lucy::Control*>;
		myControls Controls;

	};
}


