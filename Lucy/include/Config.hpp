#pragma once
#include <SFML/System.hpp>

constexpr auto LUCY_MAJOR_VERSION = 0;
constexpr auto LUCY_MINOR_VERSION = 0;
constexpr auto LUCY_REVISION_VERSION = 1;

//#if defined( _WIN32 ) || defined( __WIN32__ )
//	#define LUCY_PLATFORM_WINDOWS
//#endif

#if defined( LUCY_PLATFORM_WINDOWS ) && !defined( LUCY_STATIC )
	#if defined( LUCY_BUILD_DLL )
		#define LUCY_API __declspec( dllexport )
	#else
		#define LUCY_API __declspec( dllimport )
	#endif
#else
	#define LUCY_API
#endif


#if !defined( NDEBUG )
	#define LUCY_DEBUG
	#include <iostream> // Only for debugging purposes.
#endif

namespace Lucy
{
	enum Corners : unsigned int
	{
		None = 0x00,
		TopRight = 0x01,
		TopLeft = 0x02,
		BottomLeft = 0x04,
		BottomRight = 0x08,
		All = 0xF
	};
}
