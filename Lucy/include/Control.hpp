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

		Lucy::Control* Handle();

		//Ctor
		Control();
		//Dtor
		virtual ~Control();
		Control::CType GetType();
		virtual void Draw();

	protected:
		void SetType(CType myType);


	private:
		CType ControlType;
	};
}


