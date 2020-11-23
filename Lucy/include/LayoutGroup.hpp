#pragma once
#include "Config.hpp"
#include "Container.hpp"
#include "Control.hpp"

namespace Lucy
{
	class LUCY_API LayoutGroup : public Lucy::Control
	{
	public:
		LayoutGroup();

		~LayoutGroup();

		LayoutGroup(sf::String GroupName);

		void Add(Lucy::Control& myControl);

		void Draw();

	private:
		using myChildren = std::map<sf::String, Lucy::Control*>;
		myChildren Children;
	};
}


