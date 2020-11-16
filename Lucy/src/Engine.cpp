#include "Engine.hpp"

namespace Lucy
{
	Engine::Engine()
	{
		std::cout << "Engine created\n";
	}

	Engine::~Engine()
	{
		std::cout << "Engine destroyed\n";
	}

	void Engine::Initialize()
	{
		std::cout << "Engine initialised\n";
	}

	void Engine::Add(Lucy::Control* myControl)
	{
		Controls[myControl->Name()] = myControl;
		//Controls[myControl->Name()] = std::make_shared<Lucy::Control>(*myControl);
		//std::shared_ptr<Lucy::Control> mc = std::make_shared<Lucy::Control>(*myControl);

		//Lucy::Button* mb = static_cast<Lucy::Button*>(myControl);
		std::cout << myControl->Name().toAnsiString() << "\n";
		std::cout << "Map size-" << Controls.size() << "\n";
	}

	void Engine::DrawControls()
	{
		for (const auto& [name, control] : Controls)
		{
			control->Draw();
		}
	}

}