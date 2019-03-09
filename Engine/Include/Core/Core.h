#pragma once

#ifdef JEM_WINDOWS
	#ifdef JEM_DLL
		#define JEM_API __declspec(dllexport)

	#elif JEM_LINK_DLL
		#define JEM_API __declspec(dllimport)

	#elif JEM_STATIC_LIB || JEM_LINK_STATIC
		#define JEM_API

	#endif // JEM_DLL / JEM_LINK_DLL / JEM_STATIC_LIB / JEM_LINK_STATIC
#else
	#define JEM_API

#endif // JEM_WINDOWS