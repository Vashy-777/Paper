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

#ifdef P_ENABLE_ASSERTS
	#define P_ASSERT(x, ...) { if(!(x)) { P_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define P_CORE_ASSERT(x, ...) { if(!(x)) { P_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define P_ASSERT(x, ...)
	#define P_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)