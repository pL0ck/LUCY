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
		//myEngine.Initialize();
		std::cout << "Workspace Initialised\n";
	}

	void WorkSpace::Update(float seconds)
	{
		//Here is where we update our control ready for display
		//myEngine.DrawControls();
		for (const auto& [name, control] : Controls)
		{
			control->Draw(myWorkSpace);
		}
	}

	void WorkSpace::HandleEvent(const sf::Event& event)
	{
	}
	void WorkSpace::Add(Lucy::Control& myControl)
	{
		Controls[myControl.Name] = &myControl;
		//Controls[myControl->PsetName()] = std::make_shared<Lucy::Control>(*myControl);
		//std::shared_ptr<Lucy::Control> mc = std::make_shared<Lucy::Control>(*myControl);

		//Lucy::Button* mb = static_cast<Lucy::Button*>(myControl);
		std::cout << myControl.Name.toAnsiString() << "\n";
		std::cout << "Map size-" << Controls.size() << "\n";


		//myEngine.Add(&myControl);
		//if (myControl.GetType() == Control::CType::LayoutGroup)
		//{
		//	//Pass the engine

		//}
	}
}

