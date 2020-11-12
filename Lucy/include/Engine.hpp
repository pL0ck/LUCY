#pragma once
#include "Control.hpp"
#include "Config.hpp"
#include "Button.hpp"

#include <map>
#include <string>

namespace Lucy
{
	class Engine
	{
	public:

		//Ctor
		Engine();

		//Dtor
		~Engine();

		void Initialize();
		
		void Add(Lucy::Control myControl);

	private:
		static std::map<std::string, Lucy::Control> Controls;

	};
}


