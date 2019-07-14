#pragma once

#ifdef JEM_WINDOWS
	#ifdef JEM_DLL
		#define JEM_API __declspec(dllexport)

	#else
		#ifdef JEM_LINK_DLL
			#define JEM_API __declspec(dllimport)

		#else	
			#define JEM_API

		#endif // JEM_LINK_DLL

	#endif // JEM_DLL

#else
	#define JEM_API

#endif // JEM_WINDOWS

#ifdef JEM_DEBUG
	#define JEM_ENABLE_ASSERTIONS   // Strip out assertions for optimisation.

#endif // JEM_DEBUG