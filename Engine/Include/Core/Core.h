#pragma once

#ifdef JEM_WINDOWS
	#ifdef JEM_DLL
		#define JEM_API __declspec(dllexport)

	#else
		#define JEM_API __declspec(dllimport)

	#endif // JEM_DLL

#else
	#define JEM_API

#endif // JEM_WINDOWS