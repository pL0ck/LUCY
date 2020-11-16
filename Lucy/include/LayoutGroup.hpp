#pragma once
#include "Config.hpp"
#include "Container.hpp"
#include "Control.hpp"
#include <Engine.hpp>

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
		std::map<sf::String, std::shared_ptr<Lucy::Control>> Children;
	};
}


