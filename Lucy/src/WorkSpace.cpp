#include <WorkSpace.hpp>

namespace Lucy
{
	WorkSpace::WorkSpace()
	{
		Lucy::WorkSpace::myWorkSpace = nullptr;
		std::cout << "Workspace created\n";
	}
	WorkSpace::~WorkSpace()
	{
		std::cout << "Workspace destroyed\n";
	}

	void WorkSpace::Initialize(sf::RenderWindow& Target)
	{
		myWorkSpace = &Target;
		myEngine.Initialize();
		std::cout << "Workspace Initialised\n";
	}

	void WorkSpace::Update(float seconds)
	{
		//Here is where we update our control ready for display
		myEngine.DrawControls();

	}

	void WorkSpace::HandleEvent(const sf::Event& event)
	{
	}
	void WorkSpace::Add(Lucy::Control& myControl)
	{
		myEngine.Add(&myControl);
		if (myControl.GetType() == Control::CType::LayoutGroup)
		{
			//Pass the engine

		}
	}
}

