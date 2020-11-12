#include <WorkSpace.hpp>

namespace Lucy
{
	WorkSpace::WorkSpace()
	{
		Lucy::WorkSpace::myWorkSpace = nullptr;

	}
	WorkSpace::~WorkSpace()
	{
	}

	void WorkSpace::Initialize(sf::RenderWindow *Target)
	{
		Lucy::WorkSpace::myWorkSpace = Target;
		myEngine.Initialize();
		
	}

	void WorkSpace::Update(float seconds)
	{
	}

	void WorkSpace::HandleEvent(const sf::Event& event)
	{
	}
	void WorkSpace::Add(Lucy::Control myControl)
	{
		myEngine.Add(myControl);
	}
}

