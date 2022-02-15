#pragma once

#ifdef P_PLATFORM_WINDOWS
	#ifdef P_BUILD_DLL
		#define PAPER_API __declspec(dllexport)
	#else
		#define PAPER_API __declspec(dllimport)
	#endif 
#else
	#error Paper Engine only supports Windows!
#endif

#define BIT(x) (1 << x)