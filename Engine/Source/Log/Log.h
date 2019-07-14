#pragma once

#include <Core/Core.h>
#include "../Vendor/Logger/Include/LittleLogger.h"
#include <memory>

namespace Jem {
	class JEM_API Log {
	public:
		static void                          Init();

		static std::shared_ptr<lilo::Logger> CoreLogger;
		static std::shared_ptr<lilo::Logger> ClientLogger;
	};
}

// Core log macros.
#define JEM_CORE_MESSAGE(...)     Jem::Log::CoreLogger->LogMessage("Core: ", __VA_ARGS__)
#define JEM_CORE_WARNING(...)     Jem::Log::CoreLogger->LogWarning("Core: ", __VA_ARGS__)
#define JEM_CORE_ERROR(...)       Jem::Log::CoreLogger->LogError("Core: ", __VA_ARGS__); __debugbreak()
								  
// Client log macros.			  
#define JEM_MESSAGE(...)          Jem::Log::ClientLogger->LogMessage(__VA_ARGS__)
#define JEM_WARNING(...)          Jem::Log::ClientLogger->LogWarning(__VA_ARGS__)
#define JEM_ERROR(...)            Jem::Log::ClientLogger->LogError(__VA_ARGS__); __debugbreak()