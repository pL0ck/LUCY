#include "LayoutGroup.hpp"

namespace Lucy
{
	LayoutGroup::LayoutGroup()
	{
		std::cout << "LayoutGroup created\n";
	}

	LayoutGroup::~LayoutGroup()
	{
		std::cout << "LayoutGroup destroyed\n";
	}

	LayoutGroup::LayoutGroup(sf::String GroupName)
	{
		PsetName(GroupName);
		SetType(Control::CType::LayoutGroup);
	}

	void LayoutGroup::Add(Lucy::Control& myControl)
	{
		Children[myControl.Name] = &myControl;
	}

	void LayoutGroup::Draw()
	{
		std::cout << "LayoutGroup draw\n";
	}

}
