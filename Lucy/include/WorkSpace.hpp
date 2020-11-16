#pragma once
#include "Config.hpp"
#include "Engine.hpp"
#include "Control.hpp"

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

namespace Lucy
{
	class LUCY_API WorkSpace
	{
	public:
		//Ctor
		WorkSpace();

		//Dtor
		~WorkSpace();

		//Save our RenderWindow for future use
		void Initialize(sf::RenderWindow& Target);

		/** Update
		 * @param seconds Elapsed time in seconds.
		 */
		void Update(float seconds);

		/** Handle event.
		 * @param event SFML event.
		 */
		void HandleEvent(const sf::Event& event);

		void Add(Lucy::Control& myControl);

	private:
		sf::RenderWindow *myWorkSpace;
		Lucy::Engine myEngine;
	};
}


