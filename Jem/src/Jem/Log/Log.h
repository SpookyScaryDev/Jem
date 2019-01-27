#pragma once

#include <memory> // TODO: pch
#include <Jem/Common.h>

#include "../Dependencies/Logger/include/Logger/Logger.h"

namespace Jem {

	class JEM_API Log
	{
	public:
		static void                        init();
		static void                        shutdown();

		static logger::Logger*             pCoreLogger;
		static logger::Logger*             pLogger;
	};
}

// Core log macros.
#define JEM_CORE_MESSAGE(...)     ::Jem::Log::pCoreLogger->logMessage("Core: ", __VA_ARGS__)
#define JEM_CORE_WARNING(...)     ::Jem::Log::pCoreLogger->logWarning("Core: ", __VA_ARGS__)
#define JEM_CORE_ERROR(...)       ::Jem::Log::pCoreLogger->logError("Core: ", __VA_ARGS__); __debugbreak()

// Client log macros.
#define JEM_MESSAGE(...)          ::Jem::Log::pLogger->logMessage(__VA_ARGS__)
#define JEM_WARNING(...)          ::Jem::Log::pLogger->logWarning(__VA_ARGS__)
#define JEM_ERROR(...)            ::Jem::Log::pLogger->logError(__VA_ARGS__); __debugbreak()