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
		Name(GroupName);
		SetType(Control::CType::LayoutGroup);
	}

	void LayoutGroup::Add(Lucy::Control& myControl)
	{
		Children[myControl.Name()] = std::make_shared<Lucy::Control>(myControl);
	}

	void LayoutGroup::Draw()
	{
		std::cout << "LayoutGroup draw\n";
	}

}
