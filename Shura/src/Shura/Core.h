#pragma once

#ifdef SH_PLATFORM_WINDOWS
	#ifdef SH_BUILD_DLL
		#define SHURA_API __declspec(dllexport)
	#else	
		#define SHURA_API __declspec(dllimport)
	#endif
#else
	#error Shura only supports Windows!
#endif