#pragma once
#include "Config.hpp"
#include "Properties.hpp"

namespace Lucy
{
	class LUCY_API Control : public Properties
	{
	public:
		enum class CType
		{
			None,
			Button,
			LayoutGroup
		};

		//Ctor
		Control();
		//Dtor
		virtual ~Control();

		Control::CType GetType();
		virtual void Draw(sf::RenderWindow *Target);

	protected:
		void SetType(CType myType);


	private:
		CType ControlType;
	};
}


