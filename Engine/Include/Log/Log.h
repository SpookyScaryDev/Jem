#pragma once

#include <Core/Core.h>

#include "../Vendor/Logger/include/Logger/Logger.h"

namespace Jem {

	class JEM_API Log
	{
	public:
		static void                        Init();
		static void                        Shutdown();

		static logger::Logger*             CoreLogger;
		static logger::Logger*             ClientLogger;
	};
}

// Core log macros.
#define JEM_CORE_MESSAGE(...)     Jem::Log::CoreLogger->logMessage("Core: ", __VA_ARGS__)
#define JEM_CORE_WARNING(...)     Jem::Log::CoreLogger->logWarning("Core: ", __VA_ARGS__)
#define JEM_CORE_ERROR(...)       Jem::Log::CoreLogger->logError("Core: ", __VA_ARGS__); __debugbreak()
								  
// Client log macros.			  
#define JEM_MESSAGE(...)          Jem::Log::ClientLogger->logMessage(__VA_ARGS__)
#define JEM_WARNING(...)          Jem::Log::ClientLogger->logWarning(__VA_ARGS__)
#define JEM_ERROR(...)            Jem::Log::ClientLogger->logError(__VA_ARGS__); __debugbreak()